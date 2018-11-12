`timescale 1ns / 1ps

`include "riscv_defines.sv"
`include "alu_defines.sv"

module reg_file (
                    input logic clk,
                    input logic rst_n,

                    input logic [RISCV_WORD_WIDTH - 1 : 0] 	write_data_i,
                    input logic [$clog2(GP_REG_COUNT) - 1 : 0] write_addr_i,
                    input logic 				write_en_i,

                    input logic [$clog2(GP_REG_COUNT) - 1 : 0] read_addr_1_i,
                    input logic [$clog2(GP_REG_COUNT) - 1 : 0] read_addr_2_i,

                    output logic [RISCV_WORD_WIDTH - 1 : 0] 	read_data_1_o,
                    output logic [RISCV_WORD_WIDTH - 1 : 0] 	read_data_2_o
        );

    logic [RISCV_WORD_WIDTH - 1 : 0] mem[GP_REG_COUNT];
    logic                            mem_we[GP_REG_COUNT];
    integer i;

    assign read_data_1_o = mem[read_addr_1_i];
    assign read_data_2_o = mem[read_addr_2_i];

    always_comb begin
        for (i = 0; i < GP_REG_COUNT; i++) begin
            if (write_addr_i != 0 && write_addr_i == i[$clog2(GP_REG_COUNT) - 1 : 0])
                mem_we[i] = write_en_i;
            else
                mem_we[i] = 1'b0;
        end
    end

    always_ff @(posedge clk) begin : proc_
        for (i = 0; i < GP_REG_COUNT; i++) begin
            if (mem_we[i] == 1'b1)
                mem[i] <= write_data_i;
        end
    end

    function [31:0] readReg;
    /* verilator public */
    input integer reg_num;
    readReg = mem[reg_num];
    endfunction

    task writeReg;
    /* verilator public */
    input integer reg_num;
    input [31:0] val;
    mem[reg_num] = val;
    endtask


endmodule
