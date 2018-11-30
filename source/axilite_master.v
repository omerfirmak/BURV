`timescale 1ns / 10ps

`include "riscv_defines.v"
`include "alu_defines.v"

module axilite_master (
	input wire clk,    // Clock
	input wire rst_n,  // Asynchronous reset active low
	
    input  wire valid_i,
    output wire ready_o,

    input  wire [`RISCV_ADDR_WIDTH - 1 : 0] addr_i,
    input  wire [`RISCV_WORD_WIDTH - 1 : 0] wdata_i,
    input  wire [3 : 0]                     we_i,
    output wire [`RISCV_WORD_WIDTH - 1 : 0] rdata_o,

	output wire   			axi_awvalid,
	input  wire   			axi_awready,
	output wire [31 : 0] 	axi_awaddr,
	output wire [2 : 0] 	axi_awprot,

	output wire   			axi_wvalid,
	input  wire   			axi_wready,
	output wire [31 : 0] 	axi_wdata,
	output wire [3 : 0] 	axi_wstrb,

	input  wire    			axi_bvalid,
	output wire    			axi_bready,

	output wire    			axi_arvalid,
	input  wire    			axi_arready,
	output wire [31 : 0] 	axi_araddr,
	output wire [2 : 0] 	axi_arprot,

	input  wire        		axi_rvalid,
	output wire       		axi_rready,
	input  wire [31 : 0]	axi_rdata
);
	reg ack_awvalid, ack_arvalid, ack_wvalid, xfer_done;

	assign axi_awvalid = valid_i && |we_i && !ack_awvalid;
	assign axi_awaddr = addr_i;
	assign axi_awprot = 0;

	assign axi_arvalid = valid_i && !(|we_i) && !ack_arvalid;
	assign axi_araddr = addr_i;
	assign axi_arprot = 0;

	assign axi_wvalid = valid_i && |we_i && !ack_wvalid;
	assign axi_wdata = wdata_i;
	assign axi_wstrb = we_i;

	assign ready_o = axi_bvalid || axi_rvalid;
	assign axi_bready = valid_i && |we_i;
	assign axi_rready = valid_i && !(|we_i);
	assign rdata_o = axi_rdata;

	always @(posedge clk or negedge rst_n) begin
		if (!rst_n) begin
			ack_awvalid <= 0;
		end else begin
			xfer_done <= valid_i && ready_o;
			if (axi_awready && axi_awvalid)
				ack_awvalid <= 1;
			if (axi_arready && axi_arvalid)
				ack_arvalid <= 1;
			if (axi_wready && axi_wvalid)
				ack_wvalid <= 1;
			if (xfer_done || !valid_i) begin
				ack_awvalid <= 0;
				ack_arvalid <= 0;
				ack_wvalid <= 0;
			end
		end
	end

endmodule