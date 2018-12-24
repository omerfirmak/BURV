`timescale 1ns / 10ps

`include "riscv_defines.v"
`include "alu_defines.v"

module csr 
#(
	parameter TVEC_ADDRESS = 32'h0
)(
	input wire clk,    // Clock
	input wire rst_n,  // Asynchronous reset active low
	
	input  wire [1 : 0]  op_i,
	input  wire [11 : 0] addr_i,
	input  wire [31 : 0] wdata_i,
	output reg  [31 : 0] rdata_o,

	input  wire 		 save_epc_i,
	input  wire [31 : 0] pc_i,
	output wire [31 : 0] epc_o,
	output wire [31 : 0] tvec_o,

	output wire 		 interrupt_enable_o
);

	reg  [31 : 0] mepc,    mepc_n;
	reg  [31 : 0] mcycle,  mcycle_n;
	reg  [31 : 0] mtvec,   mtvec_n;
	reg  [1 : 0]  mstatus, mstatus_n;

	`define MSTATUS_MIE  0
	`define MSTATUS_MPIE 1
	`define MSTATUS_MPP  2'b11

	// Read requested register
	always @* 
	begin
		rdata_o = 0;
		case (addr_i)
			12'h300: rdata_o = {19'h0, `MSTATUS_MPP, 3'h0, mstatus[`MSTATUS_MPIE], 3'h0, mstatus[`MSTATUS_MIE], 3'h0};
			12'h305: rdata_o = mtvec;
			12'h341: rdata_o = mepc;
			12'hB00: rdata_o = mcycle;
			default:;
		endcase
	end

	reg [31 : 0] wdata;

	// Prepare write data according to operation
	always @* 
	begin
		case (op_i)
			`CSR_OP_NONE:  wdata = rdata_o;
			`CSR_OP_WRITE: wdata = wdata_i;
			`CSR_OP_SET:   wdata = rdata_o | wdata_i;
			`CSR_OP_CLEAR: wdata = rdata_o & ~(wdata_i);
		endcase
	end

	always @* 
	begin
		mepc_n = mepc;
		mstatus_n = mstatus;
		mtvec_n = mtvec;
		mcycle_n = mcycle + 1;

		// Handle write operations
		case (addr_i)
			12'h305: mtvec_n = wdata;
			12'h300: mstatus_n = {wdata[7], wdata[3]};
			12'h341: mepc_n = wdata;
			12'hB00: mcycle_n = wdata;
			default:;
		endcase

		if (save_epc_i) begin
			mepc_n = pc_i;
			mstatus_n = {mstatus[`MSTATUS_MIE], 1'b0};
		end
	end

	always @(posedge clk or negedge rst_n) begin : proc_
		if(~rst_n) begin
			mepc <= 0;
			mstatus <= 0;
			mcycle <= 0;
			mtvec <= TVEC_ADDRESS;
		end else begin
			mepc <= mepc_n;
			mcycle <= mcycle_n;
			mstatus <= mstatus_n;
			mtvec <= mtvec_n;
		end
	end

	// Output values that are used by controller
	assign epc_o = mepc;
	assign tvec_o = mtvec;
	assign interrupt_enable_o = mstatus[`MSTATUS_MIE];

endmodule