
`timescale 1 ns / 100 ps

	module axi_lite_regs_as_dram_v1_0_S00_AXI #
	(
		parameter integer C_S_AXI_DATA_WIDTH	= 32,
		// Width of S_AXI address bus
		parameter integer C_S_AXI_ADDR_WIDTH	= 11
	)
	(
        // CORE access
		input 	wire							core_dram_clk_inv	,
		input	wire							core_dram_en		,
		input 	wire							core_dram_rd_en		,
        input   wire                            core_dram_wr_en     ,
		input	wire [C_S_AXI_ADDR_WIDTH-1 :0]	core_dram_addr	    ,
        input	wire [C_S_AXI_DATA_WIDTH-1 :0]	core_dram_din		,
		output	wire  [C_S_AXI_DATA_WIDTH-1 :0]	core_dram_dout		,

		input wire  S_AXI_ACLK,
		input wire  S_AXI_ARESETN,
		// Write address (issued by master, acceped by Slave)
		input wire [C_S_AXI_ADDR_WIDTH-1 : 0] S_AXI_AWADDR,
		input wire [2 : 0] S_AXI_AWPROT,
		input wire  S_AXI_AWVALID,
		output wire  S_AXI_AWREADY,
		input wire [C_S_AXI_DATA_WIDTH-1 : 0] S_AXI_WDATA, 
		input wire [(C_S_AXI_DATA_WIDTH/8)-1 : 0] S_AXI_WSTRB,
		input wire  S_AXI_WVALID,
		output wire  S_AXI_WREADY,
		output wire [1 : 0] S_AXI_BRESP,
		output wire  S_AXI_BVALID,
		input wire  S_AXI_BREADY,
		input wire [C_S_AXI_ADDR_WIDTH-1 : 0] S_AXI_ARADDR,
		input wire [2 : 0] S_AXI_ARPROT,
		input wire  S_AXI_ARVALID,
		output wire  S_AXI_ARREADY,
		output wire [C_S_AXI_DATA_WIDTH-1 : 0] S_AXI_RDATA,
		output wire [1 : 0] S_AXI_RRESP,
		output wire  S_AXI_RVALID,
		input wire  S_AXI_RREADY
	);

	// AXI4LITE signals
	reg [C_S_AXI_ADDR_WIDTH-1 : 0] 	axi_awaddr;
	reg  	axi_awready;
	reg  	axi_wready;
	reg [1 : 0] 	axi_bresp;
	reg  	axi_bvalid;
	reg [C_S_AXI_ADDR_WIDTH-1 : 0] 	axi_araddr;
	reg  	axi_arready;
	reg [C_S_AXI_DATA_WIDTH-1 : 0] 	axi_rdata;
	reg [1 : 0] 	axi_rresp;
	reg  	axi_rvalid;

	// Example-specific design signals
	localparam integer ADDR_LSB = (C_S_AXI_DATA_WIDTH/32) + 1;
	localparam integer OPT_MEM_ADDR_BITS = 8;
	//----------------------------------------------
	//-- Signals for user logic register space example
	//------------------------------------------------
	//-- Number of Slave Registers 512
	//reg [C_S_AXI_DATA_WIDTH-1:0]	mem [0: 511];
	wire	 mem_rden;
	wire	 mem_wren;
	reg [C_S_AXI_DATA_WIDTH-1:0]	 reg_data_out;
	wire [C_S_AXI_ADDR_WIDTH-1 : 0] axi_addr;
	integer	 byte_index;
	reg	 aw_en;

	// I/O Connections assignments

	assign S_AXI_AWREADY	= axi_awready;
	assign S_AXI_WREADY	= axi_wready;
	assign S_AXI_BRESP	= axi_bresp;
	assign S_AXI_BVALID	= axi_bvalid;
	assign S_AXI_ARREADY	= axi_arready;
//	assign S_AXI_RDATA	= axi_rdata;
	assign S_AXI_RRESP	= axi_rresp;
	assign S_AXI_RVALID	= axi_rvalid;

	assign axi_addr = (mem_wren == 1) ? axi_awaddr : axi_araddr;
	// Implement axi_awready generation
	always @( posedge S_AXI_ACLK )
	begin
	  if ( S_AXI_ARESETN == 1'b0 )
	    begin
	      axi_awready <= 1'b0;
	      aw_en <= 1'b1;
	    end 
	  else
	    begin    
	      if (~axi_awready && S_AXI_AWVALID && S_AXI_WVALID && aw_en)
	        begin
	          axi_awready <= 1'b1;
	          aw_en <= 1'b0;
	        end
	        else if (S_AXI_BREADY && axi_bvalid)
	            begin
	              aw_en <= 1'b1;
	              axi_awready <= 1'b0;
	            end
	      else           
	        begin
	          axi_awready <= 1'b0;
	        end
	    end 
	end       

	// Implement axi_awaddr latching
	always @( posedge S_AXI_ACLK )
	begin
	  if ( S_AXI_ARESETN == 1'b0 )
	    begin
	      axi_awaddr <= 0;
	    end 
	  else
	    begin    
	      if (~axi_awready && S_AXI_AWVALID && S_AXI_WVALID && aw_en)
	        begin
	          // Write Address latching 
	          axi_awaddr <= S_AXI_AWADDR[OPT_MEM_ADDR_BITS+ADDR_LSB:ADDR_LSB];
	        end
	    end 
	end       

	// Implement axi_wready generation
	always @( posedge S_AXI_ACLK )
	begin
	  if ( S_AXI_ARESETN == 1'b0 )
	    begin
	      axi_wready <= 1'b0;
	    end 
	  else
	    begin    
	      if (~axi_wready && S_AXI_WVALID && S_AXI_AWVALID && aw_en )
	        begin
	          axi_wready <= 1'b1;
	        end
	      else
	        begin
	          axi_wready <= 1'b0;
	        end
	    end 
	end       

	// Implement memory mapped register select and write logic generation
	assign mem_wren = axi_wready && S_AXI_WVALID && axi_awready && S_AXI_AWVALID;

    // integer i;
	// always @( posedge S_AXI_ACLK )
	// begin
	//     if (mem_wren)
	//       begin
    //         mem[axi_awaddr] <= S_AXI_WDATA;
	//       end
	// end    

	// Implement write response logic generation
	always @( posedge S_AXI_ACLK )
	begin
	  if ( S_AXI_ARESETN == 1'b0 )
	    begin
	      axi_bvalid  <= 0;
	      axi_bresp   <= 2'b0;
	    end 
	  else
	    begin    
	      if (axi_awready && S_AXI_AWVALID && ~axi_bvalid && axi_wready && S_AXI_WVALID)
	        begin
	          // indicates a valid write response is available
	          axi_bvalid <= 1'b1;
	          axi_bresp  <= 2'b0; // 'OKAY' response 
	        end                   // work error responses in future
	      else
	        begin
	          if (S_AXI_BREADY && axi_bvalid)  
	            begin
	              axi_bvalid <= 1'b0; 
	            end  
	        end
	    end
	end   

	// Implement axi_arready generation

	always @( posedge S_AXI_ACLK )
	begin
	  if ( S_AXI_ARESETN == 1'b0 )
	    begin
	      axi_arready <= 1'b0;
	      axi_araddr  <= {C_S_AXI_ADDR_WIDTH{1'b0}};
	    end 
	  else
	    begin    
	      if (~axi_arready && S_AXI_ARVALID)
	        begin
	          // indicates that the slave has acceped the valid read address
	          axi_arready <= 1'b1;
	          // Read address latching
	          axi_araddr  <= S_AXI_ARADDR[OPT_MEM_ADDR_BITS+ADDR_LSB:ADDR_LSB];
	        end
	      else
	        begin
	          axi_arready <= 1'b0;
	        end
	    end 
	end       

	// Implement axi_arvalid generation 
	always @( posedge S_AXI_ACLK )
	begin
	  if ( S_AXI_ARESETN == 1'b0 )
	    begin
	      axi_rvalid <= 0;
	      axi_rresp  <= 0;
	    end 
	  else
	    begin    
	      if (axi_arready && S_AXI_ARVALID && ~axi_rvalid)
	        begin
	          // Valid read data is available at the read data bus
	          axi_rvalid <= 1'b1;
	          axi_rresp  <= 2'b0; // 'OKAY' response
	        end   
	      else if (axi_rvalid && S_AXI_RREADY)
	        begin
	          // Read data is accepted by the master
	          axi_rvalid <= 1'b0;
	        end                
	    end
	end    

	// Implement memory mapped register select and read logic generation
	assign mem_rden = axi_arready & S_AXI_ARVALID & ~axi_rvalid;
	// always @(*)
	// begin
    //     reg_data_out <= mem[axi_araddr];
	// end

	// Output register or memory read data
	// always @( posedge S_AXI_ACLK )
	// begin
	//   if ( S_AXI_ARESETN == 1'b0 )
	//     begin
	//       axi_rdata  <= 0;
	//     end 
	//   else
	//     begin    
	//       if (mem_rden)
	//         begin
	//           axi_rdata <= reg_data_out;     // register read data
	//         end   
	//     end
	// end

    // // Core read memory
    // always @(posedge core_dram_clk_inv)
	// begin
	// 	if (core_dram_en & core_dram_rd_en)
	// 	begin
	// 		core_dram_dout <= mem[core_dram_addr];
	// 	end
	// end

    // // Core write memory
    // always @(posedge core_dram_clk_inv)
	// begin
	// 	if (core_dram_en & core_dram_wr_en)
	// 	begin
	// 		mem[core_dram_addr] <= core_dram_din;
	// 	end
	// end



	// bram_dp
	dp_bram
	#(
	  .N				(C_S_AXI_ADDR_WIDTH),
	  .B				(C_S_AXI_DATA_WIDTH)
	)
	pram (
	  .clka			(S_AXI_ACLK        ),
	  .ena    	    (mem_wren|mem_rden),
	  .wea    		(mem_wren),
	  .rea          (mem_rden),
	  .addra	    (axi_addr),
	  .dia    		(S_AXI_WDATA),
	  .doa    		(S_AXI_RDATA),
  
	  .clkb			(core_dram_clk_inv),
	  .enb    	    (core_dram_en),
	  .web    		(core_dram_wr_en),
	  .reb          (core_dram_rd_en),
	  .addrb		(core_dram_addr),
	  .dib    		(core_dram_din),
	  .dob    		(core_dram_dout)
	);

	endmodule