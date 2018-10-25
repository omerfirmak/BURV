MODULE = riscv_top

VERILOG_SRC = 	../rtl/include/alu_defines.sv 		\
				../rtl/include/riscv_defines.sv		\
				../rtl/alu.sv 				\
				../rtl/reg_file.sv			\
				../rtl/riscv_core.sv			\
				../rtl/decoder.sv			\
				../rtl/controller.sv			\
				../rtl/lsu.sv			\
				../rtl/fetch_stage.sv		\
				../rtl/realign_buffer.sv		\
				ip/dp_ram.sv				\
				riscv_top.sv

TESTNAMES = $(wildcard ./tests/*.S)

all: sim

sim: compile_sim compile_software
	-./obj_dir/V$(MODULE)
	gtkwave V$(MODULE).vcd wave.gtkw

clean:
	rm -rf obj_dir
	rm -f *.vcd test.elf test.bin test.dump test.result

verilate: clean
	verilator --cc --trace $(VERILOG_SRC) -I../rtl/include --exe $(MODULE)_tb.cpp --top-module $(MODULE)

compile_sim: verilate
	make -j -C obj_dir/ -f V$(MODULE).mk V$(MODULE)

lint:
	verilator --lint-only $(VERILOG_SRC)

compile_software:
	riscv32-unknown-elf-gcc -march=rv32e -mabi=ilp32e -T link.ld $(SOFT_SRC) -o test.elf
	riscv32-unknown-elf-objdump --disassembler-options=no-aliases,numeric -D test.elf > test.dump
	riscv32-unknown-elf-objcopy -O binary test.elf test.bin

test: clean compile_sim
	echo $$(date) >> test.result
	$(foreach var,$(TESTNAMES), (echo -n $(var) >> test.result; (riscv32-unknown-elf-gcc -march=rv32e -mabi=ilp32e -T link.ld $(var) -nostdlib -o test.elf && \
																 riscv32-unknown-elf-objcopy -O binary test.elf test.bin && \
																 ./obj_dir/V$(MODULE) && echo -e "\t\tOK"  >> test.result || echo -e "\t\tFAILED"  >> test.result));)