module axi_lite_new_regs #
(
  parameter integer C_S_AXI_REG_DWIDTH	= 32,
  parameter integer C_S_AXI_REG_AWIDTH	= 4
)
(

  input     wire [C_S_AXI_REG_DWIDTH-1:0]   CORE_CSR0,
  output    wire [C_S_AXI_REG_DWIDTH-1:0]   CORE_CFG1,
  output    wire [C_S_AXI_REG_DWIDTH-1:0]   CORE_CFG2,
  output    wire [C_S_AXI_REG_DWIDTH-1:0]   CORE_CFG3,


  input wire  S_AXI_ACLK,
  input wire  S_AXI_ARESETN,
  
  input wire [C_S_AXI_REG_AWIDTH-1 : 0]     S_AXI_AWADDR,
  input wire [2 : 0]                        S_AXI_AWPROT,
  input wire                                S_AXI_AWVALID,
  output wire                               S_AXI_AWREADY,
  input wire [C_S_AXI_REG_DWIDTH-1 : 0]     S_AXI_WDATA, 
  input wire [(C_S_AXI_REG_DWIDTH/8)-1 : 0] S_AXI_WSTRB,
  input wire                                S_AXI_WVALID,
  output wire                               S_AXI_WREADY,

  output wire [1 : 0]                       S_AXI_BRESP,
  output wire                               S_AXI_BVALID,
  input wire                                S_AXI_BREADY,

  input wire [C_S_AXI_REG_AWIDTH-1 : 0]     S_AXI_ARADDR,
  input wire [2 : 0]                        S_AXI_ARPROT,
  input wire                                S_AXI_ARVALID,
  output wire                               S_AXI_ARREADY,
  output wire [C_S_AXI_REG_DWIDTH-1 : 0]    S_AXI_RDATA,
  output wire [1 : 0]                       S_AXI_RRESP,
  output wire                               S_AXI_RVALID,
  input wire                                S_AXI_RREADY
);

// AXI4LITE signals
reg [C_S_AXI_REG_AWIDTH-1 : 0] 	axi_awaddr;
reg  	axi_awready;
reg  	axi_wready;
reg [1 : 0] 	axi_bresp;
reg  	axi_bvalid;
reg [C_S_AXI_REG_AWIDTH-1 : 0] 	axi_araddr;
reg  	axi_arready;
reg [C_S_AXI_REG_DWIDTH-1 : 0] 	axi_rdata;
reg [1 : 0] 	axi_rresp;
reg  	axi_rvalid;

// Example-specific design signals
// local parameter for addressing 32 bit / 64 bit C_S_AXI_REG_DWIDTH
// ADDR_LSB is used for addressing 32/64 bit registers/memories
// ADDR_LSB = 2 for 32 bits (n downto 2)
// ADDR_LSB = 3 for 64 bits (n downto 3)
localparam integer ADDR_LSB = (C_S_AXI_REG_DWIDTH/32) + 1;
localparam integer OPT_MEM_ADDR_BITS = 1;
//----------------------------------------------
//-- Signals for user logic register space example
//------------------------------------------------
//-- Number of Slave Registers 4
reg [C_S_AXI_REG_DWIDTH-1:0]	slv_reg0;
reg [C_S_AXI_REG_DWIDTH-1:0]	slv_reg1;
reg [C_S_AXI_REG_DWIDTH-1:0]	slv_reg2;
reg [C_S_AXI_REG_DWIDTH-1:0]	slv_reg3;
wire	 slv_reg_rden;
wire	 slv_reg_wren;
reg [C_S_AXI_REG_DWIDTH-1:0]	 reg_data_out;
integer	 byte_index;
reg	 aw_en;

// I/O Connections assignments

assign S_AXI_AWREADY	= axi_awready;
assign S_AXI_WREADY	= axi_wready;
assign S_AXI_BRESP	= axi_bresp;
assign S_AXI_BVALID	= axi_bvalid;
assign S_AXI_ARREADY	= axi_arready;
assign S_AXI_RDATA	= axi_rdata;
assign S_AXI_RRESP	= axi_rresp;
assign S_AXI_RVALID	= axi_rvalid;
// Implement axi_awready generation
// axi_awready is asserted for one S_AXI_ACLK clock cycle when both
// S_AXI_AWVALID and S_AXI_WVALID are asserted. axi_awready is
// de-asserted when reset is low.

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
          // slave is ready to accept write address when 
          // there is a valid write address and write data
          // on the write address and data bus. This design 
          // expects no outstanding transactions. 
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
// This process is used to latch the address when both 
// S_AXI_AWVALID and S_AXI_WVALID are valid. 

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
          axi_awaddr <= S_AXI_AWADDR;
        end
    end 
end       

// Implement axi_wready generation
// axi_wready is asserted for one S_AXI_ACLK clock cycle when both
// S_AXI_AWVALID and S_AXI_WVALID are asserted. axi_wready is 
// de-asserted when reset is low. 

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

assign slv_reg_wren = axi_wready && S_AXI_WVALID && axi_awready && S_AXI_AWVALID;

always @( posedge S_AXI_ACLK )
begin
  if ( S_AXI_ARESETN == 1'b0 )
    begin
      slv_reg0 <= 0;
      slv_reg1 <= 0;
      slv_reg2 <= 0;
      slv_reg3 <= 0;
    end 
  else begin
    if (slv_reg_wren)
      begin
        case ( axi_awaddr[ADDR_LSB+OPT_MEM_ADDR_BITS:ADDR_LSB] )
          2'h0:
            for ( byte_index = 0; byte_index <= (C_S_AXI_REG_DWIDTH/8)-1; byte_index = byte_index+1 )
              if ( S_AXI_WSTRB[byte_index] == 1 ) begin
                slv_reg0[(byte_index*8) +: 8] <= S_AXI_WDATA[(byte_index*8) +: 8];
              end  
          2'h1:
            for ( byte_index = 0; byte_index <= (C_S_AXI_REG_DWIDTH/8)-1; byte_index = byte_index+1 )
              if ( S_AXI_WSTRB[byte_index] == 1 ) begin
                slv_reg1[(byte_index*8) +: 8] <= S_AXI_WDATA[(byte_index*8) +: 8];
              end  
          2'h2:
            for ( byte_index = 0; byte_index <= (C_S_AXI_REG_DWIDTH/8)-1; byte_index = byte_index+1 )
              if ( S_AXI_WSTRB[byte_index] == 1 ) begin
                slv_reg2[(byte_index*8) +: 8] <= S_AXI_WDATA[(byte_index*8) +: 8];
              end  
          2'h3:
            for ( byte_index = 0; byte_index <= (C_S_AXI_REG_DWIDTH/8)-1; byte_index = byte_index+1 )
              if ( S_AXI_WSTRB[byte_index] == 1 ) begin
                slv_reg3[(byte_index*8) +: 8] <= S_AXI_WDATA[(byte_index*8) +: 8];
              end  
          default : begin
                      slv_reg0 <= slv_reg0;
                      slv_reg1 <= slv_reg1;
                      slv_reg2 <= slv_reg2;
                      slv_reg3 <= slv_reg3;
                    end
        endcase
      end
  end
end    

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
      axi_araddr  <= 32'b0;
    end 
  else
    begin    
      if (~axi_arready && S_AXI_ARVALID)
        begin
          // indicates that the slave has acceped the valid read address
          axi_arready <= 1'b1;
          // Read address latching
          axi_araddr  <= S_AXI_ARADDR;
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

// define a new reg: CSR for monitoring the running states of CORE
reg [C_S_AXI_REG_DWIDTH-1:0]	reg_core_csr;
wire[C_S_AXI_REG_DWIDTH-1:0]	w_core_csr;

assign w_core_csr = reg_core_csr;

always @( posedge S_AXI_ACLK )
begin
   if ( S_AXI_ARESETN == 1'b0 )
    begin
      reg_core_csr <= 0;
    end 
   else begin
      reg_core_csr <= CORE_CSR0;
   end
end

// Implement memory mapped register select and read logic generation
assign slv_reg_rden = axi_arready & S_AXI_ARVALID & ~axi_rvalid;
always @(*)
begin
      // Address decoding for reading registers
      case ( axi_araddr[ADDR_LSB+OPT_MEM_ADDR_BITS:ADDR_LSB] )
        2'h0   : reg_data_out <= w_core_csr; // CSR is read-only by PS, write by 
        2'h1   : reg_data_out <= slv_reg1;
        2'h2   : reg_data_out <= slv_reg2;
        2'h3   : reg_data_out <= slv_reg3;
        default : reg_data_out <= 0;
      endcase
end

// Output register or memory read data
always @( posedge S_AXI_ACLK )
begin
  if ( S_AXI_ARESETN == 1'b0 )
    begin
      axi_rdata  <= 0;
    end 
  else
    begin    
      // When there is a valid read address (S_AXI_ARVALID) with 
      // acceptance of read address by the slave (axi_arready), 
      // output the read dada 
      if (slv_reg_rden)
        begin
          axi_rdata <= reg_data_out;     // register read data
        end   
    end
end    

// Add user logic here
assign CORE_CFG1 = slv_reg1;
assign CORE_CFG2 = slv_reg2;
assign CORE_CFG3 = slv_reg3;

// User logic ends

endmodule