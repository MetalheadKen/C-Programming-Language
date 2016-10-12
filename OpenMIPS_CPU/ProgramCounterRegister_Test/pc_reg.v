/* ���X�����O��}�A�æb�C��CLOCK�����O��}���W */
module pc_reg(clk, rst, pc, ce);

	input wire 			clk; /* �ɯ߰T�� */
	input wire 			rst; /* ���]�T�� */
	output reg [5:0]	pc;  /* �nŪ�������O��} */
	output reg			ce;  /* ���O�O����ҥΰT�� */
	
	/* �b�ɯ߰T���W�ɽtĲ�o */
	always @(posedge clk or negedge rst)
		begin
			/* rstĲ�o�B���ĮɡA���O�O����ҥΰT���h�L�� */
			if(!rst)
				ce <= 1'b0;
			else
				ce <= 1'b1;
		end
		
	always @(posedge clk)
		begin
			if(ce == 1'b0)
				pc <= 6'o00;
			else
				pc <= pc + 1'b1;
		end
		
endmodule
