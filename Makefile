MODULE = riscv_top

COMMON_SRC = ./rtl/dp_ram.v ./rtl/riscv_top.v

POST_SYNTH=false

VERILOG_SRC = 	./rtl/alu.v 				\
				./rtl/reg_file.v			\
				./rtl/riscv_core.v			\
				./rtl/decoder.v			\
				./rtl/decompressor.v			\
				./rtl/controller.v			\
				./rtl/lsu.v			\
				./rtl/csr.v			\
				./rtl/fetch_stage.v		\
				./rtl/realign_buffer.v

POST_SYNTH_SRC = ./synth/synth.v \
			  	 ./tech/osu018/osu018_stdcells.v	

ifeq ($(POST_SYNTH),false)
	SIM_SRC = $(VERILOG_SRC)
else
	SIM_SRC = $(POST_SYNTH_SRC)
endif

TESTNAMES = $(wildcard ./tests/*.S)
MODE=soft

.PHONY: coremark dhrystone synth

all: sim_iverilog

sim_verilator: compile_sim_verilator compile_$(MODE)
	-./obj_dir/V$(MODULE)
	gtkwave $(MODULE).vcd

clean:
	rm -rf obj_dir
	rm -f *.vcd test.elf test.bin test.dump test.result iv_exec
	rm -f synth/*.v

verilate: clean
	verilator --cc --trace $(SIM_SRC) $(COMMON_SRC) -I./rtl/include --exe $(MODULE)_tb.cpp --top-module $(MODULE)

compile_sim_verilator: verilate
	make -j -C obj_dir/ -f V$(MODULE).mk V$(MODULE)

lint:
	verilator -I./rtl/include --lint-only $(SIM_SRC) $(COMMON_SRC)

compile_soft:
	riscv32-unknown-elf-gcc -I./software -O3 -g0 -march=rv32ec -mabi=ilp32e -nostartfiles -T software/link.ld software/start.S software/handlers.c $(SRC) -o test.elf
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
	iverilog -g2012 -I./rtl/include $(SIM_SRC) $(COMMON_SRC) riscv_top_tb.v -o iv_exec

synth:
	yosys ./synth/yosys_synth.ys