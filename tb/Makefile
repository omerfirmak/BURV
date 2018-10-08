
MODULE = riscv_top

VERILOG_SRC = ../include/alu_defines.sv 	\
			  ../include/riscv_defines.sv	\
			  riscv_top.sv					\
			  ip/ram.sv 					\
			  ip/dp_ram.sv 					\
			  ../rtl/alu.sv 				\
			  ../rtl/reg_file.sv			\
			  ../rtl/riscv_core.sv			\
			  ../rtl/decode_stage.sv		\
			  ../rtl/prefetch_buffer.sv

all: sim

sim: compile_sim
	./obj_dir/V$(MODULE)
	gtkwave V$(MODULE).vcd

clean:
	rm -rf obj_dir
	rm -f *.vcd

verilate: clean
	verilator --cc --trace $(VERILOG_SRC) --exe $(MODULE)_tb.cpp --top-module riscv_top

compile_sim: verilate
	make -j -C obj_dir/ -f V$(MODULE).mk V$(MODULE)

lint:
	verilator --lint-only $(VERILOG_SRC)
