# BURV

This is the development repository for a Master's Thesis in Computer Engineering.

## Folder Structure

```
-- /
  |-- source/ (Verilog Sources)  
  |-- tests/ (RISCV Compliance Tests)  
  |-- software/ (Platform Specific Software Libraries)  
  |-- coremark/ (Coremark Port Source Files)  
  |-- dhrystone/ (Dhrystone Port Source Files)  
  |-- tinycrypt/ (NIST P-256 Source Files)  
  |-- CycloneCrypto/ (Curve25519 Source Files)  
  |-- FourQ_RV32/ (FourQ Source Files)  
  |-- analysis/ (Benchmark Results)  
```

## Build System

- GNU Make is required.  
- RISCV toolchain with rv32ec support is required for compilation. (https://github.com/riscv/riscv-gnu-toolchain)  
- Verilator (https://www.veripool.org/wiki/verilator) or Icarus Verilog (http://iverilog.icarus.com/) is required for simulation.  
- GTKWave (http://gtkwave.sourceforge.net/) is required for viewing simuation outputs.  

### Make Targets

- `make test_all`

Runs all RISCV compliance tests

- `make coremark`

Runs Coremark benchmark  

- `make dhrystone`

Runs Dhrystone benchmark  

- `make fourq`

Runs specified FourQ benchmark  

- `make p256`

Runs specified NIST P256 benchmark  

- `make c25519`

Runs Curves25519 benchmark  

- `make synth`
- `make sta`

Synthesize and do STA with Qflow on OSU018 technology

- Argument `DUMP_TRACE`  

Enables logging simulation to vcd file

- Argument `HARD_GF`  

0 - Disables use of custom instruction  
1 - Enables custom intruction with atomic execution  
2 - Enables custom intruction with partial execution  

- Argument `FOURQ_TEST`  

Specifies which FourQ test to run  

- Argument `P256_TEST`  

Specifies which NIST P256 test to run  


Example: `make fourq FOURQ_TEST=fp_test DUMP_TRACE=0`
