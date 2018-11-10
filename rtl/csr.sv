`timescale 1ns / 1ps

`include "riscv_defines.sv"
`include "alu_defines.sv"

module csr (
	input logic clk,    // Clock
	input logic rst_n,  // Asynchronous reset active low
	
	input  logic [1 : 0]  op_i,
	input  logic [11 : 0] addr_i,
	input  logic [31 : 0] wdata_i,
	output logic [31 : 0] rdata_o,

	input  logic 		  save_epc_i,
	input  logic [31 : 0] pc_i,
	output logic [31 : 0] epc_o

);

	logic [31 : 0] mepc, mepc_n;
	logic [31 : 0] mcycle, mcycle_n;
	logic [1 : 0]  mstatus, mstatus_n;

	`define MSTATUS_MIE  0
	`define MSTATUS_MPIE 1
	`define MSTATUS_MPP  2'b11

	always_comb
	begin
		rdata_o = 0;
		unique case (addr_i)
			12'h300: rdata_o = {19'h0, `MSTATUS_MPP, 3'h0, mstatus[`MSTATUS_MPIE], 3'h0, mstatus[`MSTATUS_MIE], 3'h0};
			12'h341: rdata_o = mepc;
			12'hB00: rdata_o = mcycle;
			default:;
		endcase
	end

	logic [31 : 0] wdata;

	always_comb
	begin
		unique case (op_i)
			CSR_OP_NONE:  wdata = rdata_o;
			CSR_OP_WRITE: wdata = wdata_i;
			CSR_OP_SET:	  wdata = rdata_o | wdata_i;
			CSR_OP_CLEAR: wdata = rdata_o & ~(wdata_i);
		endcase
	end

	always_comb
	begin
		mepc_n = mepc;
		mstatus_n = mstatus;
		mcycle_n = mcycle + 1;

		unique case (addr_i)
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

	always_ff @(posedge clk or negedge rst_n) begin : proc_
		if(~rst_n) begin
			mepc <= 0;
			mstatus <= 0;
			mcycle <= 0;
		end else begin
			mepc <= mepc_n;
			mcycle <= mcycle_n;
			mstatus <= mstatus_n;
		end
	end

	assign epc_o = mepc;

endmodule