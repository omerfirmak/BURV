MODULE = riscv_top

TECH=osu018

COMMON_SRC = ./source/mem_bus_arbiter.v ./source/dp_ram.v ./source/dp_rom.v ./source/riscv_top.v ./source/uart.v ./source/uart_wrap.v ./source/gpio.v

VERILOG_SRC = 	./source/alu.v 				\
				./source/reg_file.v			\
				./source/riscv_core.v			\
				./source/riscv_core_axi.v			\
				./source/decoder.v			\
				./source/decompressor.v			\
				./source/controller.v			\
				./source/lsu.v			\
				./source/csr.v			\
				./source/fetch_stage.v		\
				./source/realign_buffer.v 	\
				./source/mont_mul.v 	\
				./source/axilite_master.v

POST_SYNTH_SRC = ./riscv_core.rtlnopwr.v 	\
			  	 /usr/local/share/qflow/tech/osu018/osu018_stdcells.v	

SIM_SRC = $(VERILOG_SRC)

TESTNAMES = $(wildcard ./tests/*.S)

DUMP_TRACE = 1
BOOT_ADDRESS = 0
MEM_SIZE = 262144
DEFINE_FLAGS = -DBOOT_ADDRESS=$(BOOT_ADDRESS) -DMEM_SIZE=$(MEM_SIZE) -DDUMP_TRACE=$(DUMP_TRACE) -DMEM_ORIGIN=$(MEM_ORIGIN) -DMEM_LENGTH=$(MEM_LENGTH) -DSTACK_LENGTH=$(STACK_LENGTH) -DSTACK_ORIGIN=$(STACK_ORIGIN)

all: firmware sim_iverilog
test: compile_test sim_iverilog

clean:
	rm -rf $(shell (cat .gitignore))

lint:
	verilator $(DEFINE_FLAGS) -I./source --lint-only $(SIM_SRC) $(COMMON_SRC) --top-module $(MODULE)

MEM_ORIGIN=0
MEM_LENGTH=\(MEM_SIZE-STACK_LENGTH\)
STACK_LENGTH=65536
STACK_ORIGIN=\(MEM_SIZE-STACK_LENGTH\)
CFLAGS = -O2 -falign-functions=16 -funroll-all-loops

COMMON_C_SRC = software/start.S software/handlers.c software/print.c

compile_test: CFLAGS += -nostdlib
compile_test: COMMON_C_SRC = 
bootrom: CFLAGS=-Os -fdata-sections -ffunction-sections -Wl,--gc-sections
bootrom: MEM_SIZE=2048
bootrom: MEM_ORIGIN=0x100000
bootrom: MEM_LENGTH=MEM_SIZE 
bootrom: STACK_ORIGIN=0 
bootrom: STACK_LENGTH=MEM_SIZE 
bootrom: SRC=software/bootrom.c
compile_test bootrom firmware: prepare_ld
	riscv32-unknown-elf-gcc -I./software $(CFLAGS) -march=rv32ec -mabi=ilp32e -nostartfiles -T software/out.ld $(COMMON_C_SRC) $(SRC) -o firmware.elf
	riscv32-unknown-elf-objdump --disassembler-options=no-aliases,numeric -D firmware.elf > firmware.dump
	riscv32-unknown-elf-objcopy -O binary firmware.elf firmware.bin
	cat firmware.bin | od -t x4 -w4 -v -A n > firmware.txt

test_all: clean
	$(foreach var,$(TESTNAMES), echo "Test Name:$(var)"; make DUMP_TRACE=0 SRC=$(var) compile_test sim_iverilog;)

COREMARK_SRC =  coremark/core_list_join.c \
				coremark/core_main.c \
				coremark/core_matrix.c \
				coremark/core_portme.c \
				coremark/core_state.c \
				coremark/core_util.c \
				coremark/cvt.c \
				coremark/ee_printf.c

coremark:  SRC=$(COREMARK_SRC)
dhrystone: SRC=dhrystone/dhrystone.c dhrystone/dhrystone_main.c
coremark dhrystone: DUMP_TRACE=0
coremark dhrystone: firmware sim_verilator

sim_verilator: compile_verilator
	-./obj_dir/V$(MODULE)

compile_verilator:
	verilator $(DEFINE_FLAGS) --cc --trace --x-assign unique $(SIM_SRC) $(COMMON_SRC) -I./source --exe $(MODULE)_tb.cpp --top-module $(MODULE)
	make CXXFLAGS="$(DEFINE_FLAGS)" -j -C obj_dir/ -f V$(MODULE).mk V$(MODULE)

sim_iverilog: compile_iverilog
	vvp iv_exec

compile_iverilog:
	iverilog $(DEFINE_FLAGS) -g2012 -I./source $(SIM_SRC) $(COMMON_SRC) riscv_top_tb.v -o iv_exec

synth:
	qflow synthesize --tech $(TECH) riscv_core > /dev/null

sta:
	qflow sta --tech $(TECH) riscv_core > /dev/null

prepare_ld:
	gcc -E -x c $(DEFINE_FLAGS) software/link.ld | grep -v '^#' > software/out.ld

synth_fpga:
	yosys -ql synth_fpga.log -p 'synth_ice40 -top riscv_top; write_verilog synth.v' $(SIM_SRC) $(COMMON_SRC)