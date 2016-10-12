/* �x�s��}�A�è̾ڿ�J����}�A���X������}�����O */
module rom(ce, addr, inst);

	input wire 			ce; 	 /* �ҥΰT�� */
	input wire [5:0]	addr;  /* �nŪ�������O��} */
	output reg [31:0]	inst;  /* Ū�X�����O */
	
	reg [31:0] rom[63:0];	 /* �ϥΤG���V�q�G��64�ӡA�C�Ӭ�32�줸 */
	
	/* Ū�J�ɮ�rom.data����ƨ�rom�� */
	initial $readmemh ("rom.data", rom);
	
	/* �ҥΰT���L�ĮɡA���X����Ƭ�0�A�Ϥ��h���X��}addr���������O */
	always @( ce, addr )
		begin
			if(!ce)
				inst <= 32'h00000000;
			else
				inst <= rom[addr]; /* 2 ^ 6(->addr) = 64(->rom[]) */
		end
		
endmodule
