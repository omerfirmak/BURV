MODULE = riscv_top

COMMON_SRC = ./source/mem_bus_arbiter.v ./source/dp_ram.v ./source/dp_rom.v ./source/riscv_top.v

POST_SYNTH=false

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
				./source/axilite_master.v   \
				./source/uart.v   \
				./source/uart_wrap.v

SIM_SRC = $(VERILOG_SRC)

TESTNAMES = $(wildcard ./tests/*.S)

DUMP_TRACE = 1
BOOT_ADDRESS = 0
MEM_SIZE = 131072
DEFINE_FLAGS = -DBOOT_ADDRESS=$(BOOT_ADDRESS) -DMEM_SIZE=$(MEM_SIZE) -DDUMP_TRACE=$(DUMP_TRACE) -DMEM_ORIGIN=$(MEM_ORIGIN) -DMEM_LENGTH=$(MEM_LENGTH) -DSTACK_LENGTH=$(STACK_LENGTH) -DSTACK_ORIGIN=$(STACK_ORIGIN)

all: firmware sim_iverilog
test: compile_test sim_iverilog

clean:
	rm -rf $(shell (cat .gitignore))

lint:
	verilator $(DEFINE_FLAGS) -I./source --lint-only $(SIM_SRC) $(COMMON_SRC) --top-module $(MODULE)

MEM_ORIGIN=0
MEM_LENGTH=\(MEM_SIZE-STACK_LENGTH\)
STACK_LENGTH=16192 
STACK_ORIGIN=\(MEM_SIZE-STACK_LENGTH\)
CFLAGS = -O3 -g0 -falign-functions=16 -funroll-all-loops

bootrom: MEM_SIZE=2048
bootrom: MEM_ORIGIN=0x100000
bootrom: MEM_LENGTH=MEM_SIZE 
bootrom: STACK_ORIGIN=0 
bootrom: STACK_LENGTH=MEM_SIZE 
bootrom: SRC=software/bootrom.c
bootrom firmware: prepare_ld
	riscv32-unknown-elf-gcc -I./software $(CFLAGS) -march=rv32ec -mabi=ilp32e -nostartfiles -T software/out.ld software/start.S software/handlers.c $(SRC) -o firmware.elf
	riscv32-unknown-elf-objdump --disassembler-options=no-aliases,numeric -D firmware.elf > firmware.dump
	riscv32-unknown-elf-objcopy -O binary firmware.elf firmware.bin
	cat firmware.bin | od -t x4 -w4 -v -A n > firmware.txt

test_all: clean
	$(foreach var,$(TESTNAMES), make DUMP_TRACE=0 SRC=$(var) test sim_iverilog;)

compile_test:
	riscv32-unknown-elf-gcc -march=rv32ec -mabi=ilp32e -nostdlib -nostartfiles -T software/link.ld $(SRC) -o test.elf
	riscv32-unknown-elf-objdump --disassembler-options=no-aliases,numeric -D test.elf > test.dump
	riscv32-unknown-elf-objcopy -O binary test.elf test.bin
	cat test.bin | od -t x4 -w4 -v -A n > test.txt

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
coremark dhrystone: firmware sim_iverilog

sim_iverilog: compile_iverilog
	vvp iv_exec

compile_iverilog:
	iverilog $(DEFINE_FLAGS)  -g2012 -I./source $(SIM_SRC) $(COMMON_SRC) riscv_top_tb.v -o iv_exec

synth:
	qflow synthesize --tech osu018 riscv_core > /dev/null

sta:
	qflow sta --tech osu018 riscv_core > /dev/null

prepare_ld:
	gcc -E -x c $(DEFINE_FLAGS) software/link.ld | grep -v '^#' > software/out.ld