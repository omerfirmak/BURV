`timescale 1ns / 10ps

`include "riscv_defines.v"
`include "alu_defines.v"

module dp_ram
#(
    parameter ADDR_WIDTH = `RISCV_ADDR_WIDTH
)(
    // Clock and Reset
    input  wire clk,

    input  wire a_valid_i,
    output reg  a_ready_o,

    input  wire [`RISCV_ADDR_WIDTH - 1 : 0] a_addr_i,
    input  wire [`RISCV_WORD_WIDTH - 1 : 0] a_wdata_i,
    input  wire [3 : 0]                     a_we_i,
    output reg  [`RISCV_WORD_WIDTH - 1 : 0] a_rdata_o,

    input  wire b_valid_i,
    output reg  b_ready_o,

    input  wire [`RISCV_ADDR_WIDTH - 1 : 0] b_addr_i,
    input  wire [`RISCV_WORD_WIDTH - 1 : 0] b_wdata_i,
    input  wire [3 : 0]                     b_we_i,
    output reg  [`RISCV_WORD_WIDTH - 1 : 0] b_rdata_o
);

    localparam words = 262144;

    reg [31:0] mem[words -1 : 0];

    always @(posedge clk) begin
        a_ready_o <= 0;
        b_ready_o <= 0;
        
        if (a_valid_i) begin
            if (a_we_i[0]) mem[a_addr_i >> 2][7 : 0] <= a_wdata_i[7 : 0];
            if (a_we_i[1]) mem[a_addr_i >> 2][15 : 8] <= a_wdata_i[15 : 8];
            if (a_we_i[2]) mem[a_addr_i >> 2][23 : 16] <= a_wdata_i[23 : 16];
            if (a_we_i[3]) mem[a_addr_i >> 2][31 : 24] <= a_wdata_i[31 : 24];

            a_rdata_o <= mem[a_addr_i >> 2];
            a_ready_o <= 1;
        end

        if (b_valid_i) begin
            if (b_we_i[0]) mem[b_addr_i >> 2][7 : 0] <= b_wdata_i[7 : 0];
            if (b_we_i[1]) mem[b_addr_i >> 2][15 : 8] <= b_wdata_i[15 : 8];
            if (b_we_i[2]) mem[b_addr_i >> 2][23 : 16] <= b_wdata_i[23 : 16];
            if (b_we_i[3]) mem[b_addr_i >> 2][31 : 24] <= b_wdata_i[31 : 24];

            b_rdata_o <= mem[b_addr_i >> 2];
            b_ready_o <= 1;
        end
    end

    function [31:0] readWord;
    /* verilator public */
    input integer byte_addr;
    readWord = mem[byte_addr >> 2];
    endfunction

    task writeWord;
    /* verilator public */
    input integer byte_addr;
    input [31:0] val;
    mem[byte_addr >> 2] = val;
    endtask

endmodule
