`timescale 1ns / 10ps

`include "riscv_defines.v"
`include "alu_defines.v"

module reg_file (
    input wire clk,
    input wire rst_n,

    input wire [`RISCV_WORD_WIDTH - 1 : 0] 	    write_data_i,
    input wire [$clog2(`GP_REG_COUNT) - 1 : 0]  write_addr_i,
    input wire 				                    write_en_i,

    input wire [$clog2(`GP_REG_COUNT) - 1 : 0] read_addr_1_i,
    input wire [$clog2(`GP_REG_COUNT) - 1 : 0] read_addr_2_i,

    output wire [`RISCV_WORD_WIDTH - 1 : 0]     read_data_1_o,
    output wire [`RISCV_WORD_WIDTH - 1 : 0] 	read_data_2_o
);

    wire [`RISCV_WORD_WIDTH - 1 : 0] mem_o[`GP_REG_COUNT -1 : 0];
    reg  [`RISCV_WORD_WIDTH - 1 : 0] mem[`GP_REG_COUNT -1 : 0];
    reg                              mem_we[`GP_REG_COUNT -1 : 0];
    integer i;

    assign read_data_1_o = mem_o[read_addr_1_i];
    assign read_data_2_o = mem_o[read_addr_2_i];

    // Decode write address
    always @* 
    begin
        for (i = 0; i < `GP_REG_COUNT; i = i +1) begin
            if (write_addr_i == i[$clog2(`GP_REG_COUNT) - 1 : 0])
                mem_we[i] = write_en_i;
            else
                mem_we[i] = 1'b0;
        end
    end

    // Latch input data to actual registers
    always @(posedge clk or negedge rst_n) begin
        if (~rst_n) begin
            for (i = 0; i < `GP_REG_COUNT; i = i +1) begin
                mem[i] <= 0;
            end        
        end else begin
            for (i = 0; i < `GP_REG_COUNT; i = i +1) begin
                if (mem_we[i] == 1'b1)
                    mem[i] <= write_data_i;
            end
        end
    end

    // Hardwire r0 to 0
    assign mem_o[0] = 0;

    // Map physical registers to output addresses, storage for r0 should get optimized out
    generate
        genvar j;
        for (j = 1; j < `GP_REG_COUNT; j = j + 1) begin
            assign mem_o[j] = mem[j];        
        end
    endgenerate

`ifdef VERILATOR
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
`endif

endmodule
