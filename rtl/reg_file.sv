`timescale 1ns / 1ps

`include "../include/riscv_defines.sv"

module reg_file (
                    input logic clk,
                    input logic rst_n,

                    input logic [`RISCV_WORD_WIDTH - 1 : 0] 	write_data_i,
                    input logic [$clog2(`GP_REG_COUNT) - 1 : 0] write_addr_i,
                    input logic 				write_en_i,

                    input logic [$clog2(`GP_REG_COUNT) - 1 : 0] read_addr_1_i,
                    input logic [$clog2(`GP_REG_COUNT) - 1 : 0] read_addr_2_i,

                    output logic [`RISCV_WORD_WIDTH - 1 : 0] 	read_data_1_o,
                    output logic [`RISCV_WORD_WIDTH - 1 : 0] 	read_data_2_o
        );

    logic [`RISCV_WORD_WIDTH - 1 : 0] mem[`GP_REG_COUNT];

    assign read_data_1_o = mem[read_addr_1_i];
    assign read_data_2_o = mem[read_addr_2_i];

    always_ff @(posedge clk or negedge rst_n) begin : proc_
        if(~rst_n) begin
            for (integer index = 0; index < `GP_REG_COUNT; ++index) begin
                mem[index] = 0;
            end
        end else begin
            if ( write_en_i && (write_addr_i != 0) ) begin
                mem[write_addr_i] <= write_data_i;
            end
        end
    end

endmodule
