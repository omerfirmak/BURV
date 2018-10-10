MODULE = riscv_top

VERILOG_SRC = 	../rtl/include/alu_defines.sv 		\
				../rtl/include/riscv_defines.sv		\
				../rtl/alu.sv 				\
				../rtl/reg_file.sv			\
				../rtl/riscv_core.sv			\
				../rtl/decoder.sv			\
				../rtl/fetch_stage.sv		\
				../rtl/realign_buffer.sv		\
				ip/dp_ram.sv				\
				riscv_top.sv

all: sim

sim: compile_sim
	./obj_dir/V$(MODULE)
	gtkwave V$(MODULE).vcd

clean:
	rm -rf obj_dir
	rm -f *.vcd

verilate: clean
	verilator --cc --trace $(VERILOG_SRC) -I../rtl/include --exe $(MODULE)_tb.cpp --top-module $(MODULE)

compile_sim: verilate
	make -j -C obj_dir/ -f V$(MODULE).mk V$(MODULE)

lint:
	verilator --lint-only $(VERILOG_SRC)
