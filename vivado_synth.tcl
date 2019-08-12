
read_verilog    ./source/mem_bus_arbiter.v \
				./source/dp_ram.v \
				./source/dp_rom.v \
				./source/riscv_top.v \
				./source/riscv_top_small.v \
				./source/uart.v \
				./source/uart_wrap.v \
				./source/gpio.v \
				./source/alu.v 				\
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

read_xdc vivado_synth.xdc

synth_design -part xc7z020clg484-1 -top riscv_top_small
opt_design
place_design
phys_opt_design
route_design

report_utilization
report_timing