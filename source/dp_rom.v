`timescale 1ns / 10ps

`include "riscv_defines.v"
`include "alu_defines.v"

module dp_rom
#(
    parameter ADDR_WIDTH = `RISCV_ADDR_WIDTH,
    parameter SIZE_BYTES = 2048,
    parameter INIT_FILE_BIN  = ""
)(
    // Clock and Reset
    input  wire clk,

    input  wire a_valid_i,
    output reg  a_ready_o,

    input  wire [`RISCV_ADDR_WIDTH - 1 : 0] a_addr_i,
    output reg  [`RISCV_WORD_WIDTH - 1 : 0] a_rdata_o,

    input  wire b_valid_i,
    output reg  b_ready_o,

    input  wire [`RISCV_ADDR_WIDTH - 1 : 0] b_addr_i,
    output reg  [`RISCV_WORD_WIDTH - 1 : 0] b_rdata_o
);

    wire [$clog2(SIZE_BYTES/4) - 1 : 0] a_addr = a_addr_i[$clog2(SIZE_BYTES/4) + 1 : 2];
    wire [$clog2(SIZE_BYTES/4) - 1 : 0] b_addr = b_addr_i[$clog2(SIZE_BYTES/4) + 1 : 2];

    reg [31:0] mem[(SIZE_BYTES/4) -1 : 0];

    initial begin
        /* verilator lint_off WIDTH */
        if (INIT_FILE_BIN != "") $readmemh(INIT_FILE_BIN, mem);
        /* verilator lint_on WIDTH */
    end

    always @(posedge clk) begin
        a_ready_o <= 0;
        b_ready_o <= 0;
        
        if (a_valid_i) begin
            a_ready_o <= 1;
            a_rdata_o <= mem[a_addr];
        end

        if (b_valid_i) begin
            b_ready_o <= 1;
            b_rdata_o <= mem[b_addr];
        end

    end

`ifdef VERILATOR
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
`endif

endmodule
