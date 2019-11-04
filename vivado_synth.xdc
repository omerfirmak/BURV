create_clock -period 10.000 [get_ports clk]

set_property PACKAGE_PIN Y9 [get_ports clk]
set_property IOSTANDARD LVCMOS33 [get_ports clk]

set_property PACKAGE_PIN P16 [get_ports rst_n]
set_property IOSTANDARD LVCMOS33 [get_ports rst_n]

set_property PACKAGE_PIN Y11 [get_ports rst_n_o]
set_property IOSTANDARD LVCMOS33 [get_ports rst_n_o]

set_property PACKAGE_PIN AA11 [get_ports ebreak_inst_o]
set_property IOSTANDARD LVCMOS33 [get_ports ebreak_inst_o]

create_clock -period 20.000 -name clk50 -waveform {0.000 10.000} [get_nets clk_50mhz]