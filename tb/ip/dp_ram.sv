 module dp_ram
#(
    parameter ADDR_WIDTH = RISCV_ADDR_WIDTH
)(
    // Clock and Reset
    input  logic clk,

    input  logic a_valid_i,
    output logic a_ready_o,

    input  logic [RISCV_ADDR_WIDTH - 1 : 0] a_addr_i,
    input  logic [RISCV_WORD_WIDTH - 1 : 0] a_wdata_i,
    input  logic [3 : 0]                    a_we_i,
    output logic [RISCV_WORD_WIDTH - 1 : 0] a_rdata_o,

    input  logic b_valid_i,
    output logic b_ready_o,

    input  logic [RISCV_ADDR_WIDTH - 1 : 0] b_addr_i,
    input  logic [RISCV_WORD_WIDTH - 1 : 0] b_wdata_i,
    input  logic [3 : 0]                    b_we_i,
    output logic [RISCV_WORD_WIDTH - 1 : 0] b_rdata_o
);

    localparam words = 4096;

    logic [3:0][7:0] mem[words];

    always @(posedge clk) begin
        a_ready_o <= 0;
        b_ready_o <= 0;
        
        if (a_valid_i && !a_ready_o) begin
            if (a_we_i[0]) mem[a_addr_i >> 2][0] <= a_wdata_i[7:0];
            if (a_we_i[1]) mem[a_addr_i >> 2][1] <= a_wdata_i[15:8];
            if (a_we_i[2]) mem[a_addr_i >> 2][2] <= a_wdata_i[23:16];
            if (a_we_i[3]) mem[a_addr_i >> 2][3] <= a_wdata_i[31:24];

            a_rdata_o <= mem[a_addr_i >> 2];
            a_ready_o <= 1;
        end

        if (b_valid_i && !b_ready_o) begin
            if (b_we_i[0]) mem[b_addr_i >> 2][0] <= b_wdata_i[7:0];
            if (b_we_i[1]) mem[b_addr_i >> 2][1] <= b_wdata_i[15:8];
            if (b_we_i[2]) mem[b_addr_i >> 2][2] <= b_wdata_i[23:16];
            if (b_we_i[3]) mem[b_addr_i >> 2][3] <= b_wdata_i[31:24];

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
