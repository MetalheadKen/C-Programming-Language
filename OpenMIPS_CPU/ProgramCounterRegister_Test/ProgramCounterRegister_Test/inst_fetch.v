/* �� pc_reg.v �P rom.v �զX�_�� */
module inst_fetch(clk, rst, inst_o);

	input wire 			clk; 	 	/* �ɯ߰T�� */
	input wire 			rst;  	/* ���]�T�� */
	output wire [31:0]	inst_o;  /* Ū�X�����O */
	
	wire [5:0] pc;	 /* �������u */
	wire rom_ce;	 /* �������u */
	
	/* PC�Ҳժ������ */
	pc_reg pc_reg0(.clk(clk), .rst(rst), .pc(pc), .ce(rom_ce));
	
	/* ���O�O����ROM������� */
	rom rom0(.ce(rom_ce), .addr(pc), .inst(inst_o));
		
endmodule
