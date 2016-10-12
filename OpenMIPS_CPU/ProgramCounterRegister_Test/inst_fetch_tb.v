/* �� pc_reg.v �P rom.v �զX�_�� */
module inst_fetch_tb;
	
	reg 			CLOCK;	 /* �X�ʰT���A�����ɯ߰T�� */
	reg 			rst;		 /* �X�ʰT���A�������]�T�� */
	wire [31:0] inst;		 /* ��ܰT���A�������X�����O */
	
	/* �w�qCLOCK�T���A�C�j10�Ӯɶ����ACLOCK���ȴN½��A�Ѧ��o��@�Ӷg���T���C
	** �b�������ɭԡA�@�Ӯɶ����w�]�O1ns�A�ҥHCLOCK���ȨC10ns½��@���A
	** �����N�O50MHZ���ɯ�	*/
	initial begin
		CLOCK = 1'b0;
		forever #10 CLOCK = ~CLOCK;
	end
	
	/* �w�qrst�T���A�̤@�}�l��0�A��ܭ��]�T�����ġA�L�F195�Ӯɶ����A�Y195ns�A
	** �]�wrst�T�����Ȭ�1�A���]�T�����L�ġA���]�����A�b����1000ns�A�Ȱ����� */
	initial begin
		rst = 1'b0;
		#195 rst = 1'b1;
		#1000 $stop;
	end
		
	/* �ݴ��Ҳժ������ */
	inst_fetch inst_fetch0(.clk(CLOCK), .rst(rst), .inst_o(inst));
		
endmodule
