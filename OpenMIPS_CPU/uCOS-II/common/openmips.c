/* 新建一個Task，名子叫TaskStart，在這個TaskStart中初始化串列埠、GPIO，然後通過串列埠輸出一個字串的兩個字元（一個中文字兩個字元），
** 同時GPIO的輸出加2，然後等待100ms，再輸出這個字串的下兩個字元，直到字串輸出完畢。 */

#include "includes.h"

#define BOTH_EMPTY (UART_LS_TEMT | UART_LS_THRE)

#define WAIT_FOR_XMITR \
        do { \
                lsr = REG8(UART_BASE + UART_LS_REG); \
        } while ((lsr & BOTH_EMPTY) != BOTH_EMPTY)

#define WAIT_FOR_THRE \
        do { \
                lsr = REG8(UART_BASE + UART_LS_REG); \
        } while ((lsr & UART_LS_THRE) != UART_LS_THRE)

#define TASK_STK_SIZE 256

OS_STK TaskStartStk[TASK_STK_SIZE];

/*  要輸出的字串，這是一段中文字的編碼 */
char Info[103]={0xC9,0xCF,0xB5,0xDB,0xCB,0xB5,0xD2,0xAA,0xD3,0xD0,0xB9,0xE2,0xA3,0xAC,0xD3,0xDA,0xCA,0xC7,0xBE,0xCD,0xD3,0xD0,0xC1,0xCB,0xB9,0xE2,0x0D,0x0A,0xC9,0xCF,0xB5,0xDB,0xCB,0xB5,0xD2,0xAA,0xD3,0xD0,0xCC,0xEC,0xBF,0xD5,0xA3,0xAC,0xD3,0xDA,0xCA,0xC7,0xBE,0xCD,0xD3,0xD0,0xC1,0xCB,0xCC,0xEC,0xBF,0xD5,0x0D,0x0A,0xC9,0xCF,0xB5,0xDB,0xCB,0xB5,0xD2,0xAA,0xD3,0xD0,0xC2,0xBD,0xB5,0xD8,0xBA,0xCD,0xBA,0xA3,0xD1,0xF3,0xA3,0xAC,0xD3,0xDA,0xCA,0xC7,0xBE,0xCD,0xD3,0xD0,0xC1,0xCB,0xC2,0xBD,0xB5,0xD8,0xBA,0xCD,0xBA,0xA3,0xD1,0xF3,0x0D};

/* 串列埠初始化函數 */
void uart_init(void)
{
        INT32U divisor;
 
         /* Set baud rate */
	
        divisor = (INT32U) IN_CLK/(16 * UART_BAUD_RATE);

        REG8(UART_BASE + UART_LC_REG) = 0x80;
        REG8(UART_BASE + UART_DLB1_REG) = divisor & 0x000000ff;
        REG8(UART_BASE + UART_DLB2_REG) = (divisor >> 8) & 0x000000ff;
        REG8(UART_BASE + UART_LC_REG) = 0x00;
        
        
        /* Disable all interrupts */
       
        REG8(UART_BASE + UART_IE_REG) = 0x00;
       
 
        /* Set 8 bit char, 1 stop bit, no parity */
        
       REG8(UART_BASE + UART_LC_REG) = UART_LC_WLEN8 | (UART_LC_ONE_STOP | UART_LC_NO_PARITY);
        
  
        uart_print_str("UART initialize done ! \n");
	return;
}

/* 通過串列埠輸出字元的函數 */
void uart_putc(char c)
{
        unsigned char lsr;
        WAIT_FOR_THRE;
        REG8(UART_BASE + UART_TH_REG) = c;
        if(c == '\n') {
          WAIT_FOR_THRE;
          REG8(UART_BASE + UART_TH_REG) = '\r';
        }
        WAIT_FOR_XMITR;  
  
}

/* 通過串列埠輸出字串的函數 */
void uart_print_str(char* str)
{
       INT32U i=0;
       OS_CPU_SR cpu_sr;
       OS_ENTER_CRITICAL()
       
       while(str[i]!=0)
       {
       	uart_putc(str[i]);
        i++;
       }
        
       OS_EXIT_CRITICAL()
        
}

/* GPIO初始化的函數 */
void gpio_init()
{
	REG32(GPIO_BASE + GPIO_OE_REG) = 0xffffffff;
	REG32(GPIO_BASE + GPIO_INTE_REG) = 0x00000000;
	gpio_out(0x0f0f0f0f);
	uart_print_str("GPIO initialize done ! \n");
        return;
}

/* 設置GPIO輸出的函數 */
void gpio_out(INT32U number)
{
	

	  REG32(GPIO_BASE + GPIO_OUT_REG) = number;
	  

}

/* 讀取GPIO輸入的函數 */
INT32U gpio_in()
{
	INT32U temp = 0;
	

	
	 temp = REG32(GPIO_BASE + GPIO_IN_REG);
	  

	
	return temp;
}

/* 設置compare暫存器，以使能時鐘中斷 */
void OSInitTick(void)
{
    INT32U compare = (INT32U)(IN_CLK / OS_TICKS_PER_SEC);
    
    asm volatile("mtc0   %0,$9"   : :"r"(0x0)); 
    asm volatile("mtc0   %0,$11"   : :"r"(compare));  
    asm volatile("mtc0   %0,$12"   : :"r"(0x10000401));
    //uart_print_str("OSInitTick Done!!!\n");
    
    return; 
}

/* 主任務Task Start */
void TaskStart (void *pdata)
{
    INT32U count = 0;
    pdata = pdata;          /* Prevent compiler warning                 */
    OSInitTick();	      	/* don't put this function in main()        */       
    for (;;) {
       if(count <= 102)
    	{
         uart_putc(Info[count]);
         uart_putc(Info[count+1]);
        }
        gpio_out(count);
        count=count+2;
        OSTimeDly(10);  /* Wait 100ms                   */
    }
    
}

/* main函數 */
void main()
{
  OSInit();
  
  uart_init();
  
  gpio_init();	
  
  OSTaskCreate(TaskStart, 
	       (void *)0, 
	       &TaskStartStk[TASK_STK_SIZE - 1], 
	       0);
  
  OSStart();  
  
}
