create_clock -period 10.00 [get_ports clk]

set_property PACKAGE_PIN Y9 [get_ports {clk}];  # "GCLK"
set_property PACKAGE_PIN Y11  [get_ports {rst_n}];  # "JA1"
set_property PACKAGE_PIN AA8  [get_ports {dmem_valid_o}];  # "JA10"