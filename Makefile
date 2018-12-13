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
MODE=soft

DUMP_TRACE = 1
BOOT_ADDRESS = 0
MEM_SIZE = 65536
DEFINE_FLAGS = -DBOOT_ADDRESS=$(BOOT_ADDRESS) -DMEM_SIZE=$(MEM_SIZE) -DDUMP_TRACE=$(DUMP_TRACE)

.PHONY: coremark dhrystone synth

all: sim_iverilog

clean:
	rm -rf $(shell (cat .gitignore))

lint:
	verilator $(DEFINE_FLAGS) -I./source --lint-only $(SIM_SRC) $(COMMON_SRC) --top-module $(MODULE)

compile_soft:
	riscv32-unknown-elf-gcc -I./software -O3 -g0 -falign-functions=16 -funroll-all-loops -march=rv32ec -mabi=ilp32e -nostartfiles -T software/link.ld software/start.S software/handlers.c $(SRC) -o test.elf
	riscv32-unknown-elf-objdump --disassembler-options=no-aliases,numeric -D test.elf > test.dump
	riscv32-unknown-elf-objcopy -O binary test.elf test.bin
	cat test.bin | od -t x4 -w4 -v -A n > test.txt

test_all: clean
	$(foreach var,$(TESTNAMES), make DUMP_TRACE=0 MODE=test SRC=$(var);)

compile_test:
	riscv32-unknown-elf-gcc -march=rv32ec -mabi=ilp32e -nostdlib -nostartfiles -T software/link.ld $(SRC) -o test.elf
	riscv32-unknown-elf-objdump --disassembler-options=no-aliases,numeric -D test.elf > test.dump
	riscv32-unknown-elf-objcopy -O binary test.elf test.bin
	cat test.bin | od -t x4 -w4 -v -A n > test.txt

dhrystone:
	make MODE=soft SRC="dhrystone/dhrystone.c dhrystone/dhrystone_main.c"


COREMARK_SRC = "coremark/core_list_join.c \
				coremark/core_main.c \
				coremark/core_matrix.c \
				coremark/core_portme.c \
				coremark/core_state.c \
				coremark/core_util.c \
				coremark/cvt.c \
				coremark/ee_printf.c"

coremark:
	make MODE=soft SRC=$(COREMARK_SRC)

sim_iverilog: compile_$(MODE) compile_iverilog
	vvp iv_exec

compile_iverilog:
	iverilog $(DEFINE_FLAGS)  -g2012 -I./source $(SIM_SRC) $(COMMON_SRC) riscv_top_tb.v -o iv_exec

synth:
	qflow synthesize --tech osu018 riscv_core > /dev/null

sta:
	qflow sta --tech osu018 riscv_core > /dev/null
