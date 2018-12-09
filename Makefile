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
				./source/axilite_master.v

SIM_SRC = $(VERILOG_SRC)

TESTNAMES = $(wildcard ./tests/*.S)
MODE=soft

.PHONY: coremark dhrystone synth

all: sim_iverilog

sim_verilator: compile_sim_verilator compile_$(MODE)
	-./obj_dir/V$(MODULE)
	gtkwave $(MODULE).vcd

clean:
	rm -rf $(shell (cat .gitignore))

verilate: clean
	verilator --cc --trace $(SIM_SRC) $(COMMON_SRC) -I./source --exe $(MODULE)_tb.cpp --top-module $(MODULE)

compile_sim_verilator: verilate
	make -j -C obj_dir/ -f V$(MODULE).mk V$(MODULE)

lint:
	verilator -I./source --lint-only $(SIM_SRC) $(COMMON_SRC) --top-module $(MODULE)

compile_soft:
	riscv32-unknown-elf-gcc -I./software -O3 -g0 -falign-functions=16 -funroll-all-loops -march=rv32ec -mabi=ilp32e -nostartfiles -T software/link.ld software/start.S software/handlers.c $(SRC) -o test.elf
	riscv32-unknown-elf-objdump --disassembler-options=no-aliases,numeric -D test.elf > test.dump
	riscv32-unknown-elf-objcopy -O binary test.elf test.bin

test_all: clean compile_sim_verilator
	echo $$(date) >> test.result
	$(foreach var,$(TESTNAMES), (echo -n $(var) >> test.result; (riscv32-unknown-elf-gcc -g0 -march=rv32e -mabi=ilp32e -T software/link.ld $(var) -nostdlib -o test.elf && \
																 riscv32-unknown-elf-objcopy -O binary test.elf test.bin && \
																 ./obj_dir/V$(MODULE) && echo -e "\t\tOK"  >> test.result || echo -e "\t\tFAILED"  >> test.result));)
compile_test:
	riscv32-unknown-elf-gcc -march=rv32ec -mabi=ilp32e -nostdlib -nostartfiles -T software/link.ld tests/$(SRC).S -o test.elf
	riscv32-unknown-elf-objdump --disassembler-options=no-aliases,numeric -D test.elf > test.dump
	riscv32-unknown-elf-objcopy -O binary test.elf test.bin

dhrystone:
	make sim_verilator MODE=soft SRC="dhrystone/dhrystone.c dhrystone/dhrystone_main.c"


COREMARK_SRC = "coremark/core_list_join.c \
				coremark/core_main.c \
				coremark/core_matrix.c \
				coremark/core_portme.c \
				coremark/core_state.c \
				coremark/core_util.c \
				coremark/cvt.c \
				coremark/ee_printf.c"

coremark:
	make sim_verilator MODE=soft SRC=$(COREMARK_SRC)

sim_iverilog: compile_iverilog compile_$(MODE)
	vvp iv_exec
	gtkwave $(MODULE).vcd

compile_iverilog:
	iverilog -g2012 -I./source $(SIM_SRC) $(COMMON_SRC) riscv_top_tb.v -o iv_exec

synth:
	qflow synthesize --tech osu018 riscv_core > /dev/null

sta:
	qflow sta --tech osu018 riscv_core > /dev/null
