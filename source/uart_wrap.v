module uart_wrap (
	input clk,    // Clock
	input rst_n,  // Asynchronous reset active low

	input  wire valid_i,
	output reg  ready_o,

	input  wire [`RISCV_ADDR_WIDTH - 1 : 0] addr_i,
	input  wire [`RISCV_WORD_WIDTH - 1 : 0] wdata_i,
	input  wire [3 : 0]                     we_i,
	output reg  [`RISCV_WORD_WIDTH - 1 : 0] rdata_o,

	input  wire rx_i,
	output wire tx_o,

	output wire irq
);
	
	localparam TX_DATA_REG = 4'h0; // W only
	localparam RX_DATA_REG = 4'h4; // R only
	localparam STATUS_REG  = 4'h8; // R only


	reg received_latched;

	wire [7 : 0] tx_byte,
				 rx_byte;

	wire is_transmitting,
		 is_receiving,
		 received,
		 recv_error;

	reg  transmit_en,
		 clear_received;

	reg  [`RISCV_WORD_WIDTH - 1 : 0] rdata_n;

	assign irq = received;
	assign tx_byte = wdata_i[7 : 0];

	uart uart_core(
		.clk				(clk), // The master clock for this module
		.rst				(~rst_n), // Synchronous reset.
		.rx					(rx_i), // Incoming serial line
		.tx					(tx_o), // Outgoing serial line
		.transmit			(transmit_en), // Signal to transmit
		.tx_byte			(tx_byte), // Byte to transmit
		.received			(received), // Indicated that a byte has been received.
		.rx_byte			(rx_byte), // Byte received
		.is_receiving		(is_receiving), // Low when receive line is idle.
		.is_transmitting	(is_transmitting), // Low when transmit line is idle.
		.recv_error 		(recv_error)// Indicates error in receiving packet.
	);

	always @* 
	begin
		rdata_n = 0;
		transmit_en = 0;
		clear_received = 0;

		if (valid_i)
		begin
			case (addr_i[3 : 0])
				RX_DATA_REG: begin
					if (received_latched) rdata_n[7 : 0] = rx_byte;
					clear_received = 1;
				end
				STATUS_REG: begin
					rdata_n[3 : 0] = {is_transmitting, recv_error, is_receiving, received_latched};
				end
				TX_DATA_REG:
				begin
					transmit_en = |we_i;
				end
				default : /* default */;
			endcase
		end
	end

	always @(posedge clk or negedge rst_n) begin
		if(~rst_n) begin
			received_latched <= 0;
		end else begin
			if (received)
				received_latched <= 1;
			else if (clear_received)
				received_latched <= 0;

			ready_o <= valid_i;
			if (valid_i) rdata_o <= rdata_n;
		end
	end

	always @(negedge clk) begin
		if (transmit_en) begin
			$write("%c", tx_byte); //dmem_wdata[7:0]);
		end
	end

endmodule