/* Includes ------------------------------------------------------------------*/
#include "lwip/debug.h"
#include "httpd.h"
#include "lwip/tcp.h"
#include "fs.h"
#include "main.h"
#include "my_uart.h"

#include <string.h>
#include <stdlib.h>

tSSIHandler CHECK_Page_SSI_Handler;

/* By Include my_uart.c */
extern uint8_t in_out_flag;

/* we will use character "t" as tag for CGI */
char const* TAGCHAR="t";
char const** TAGS=&TAGCHAR;

/* CGI handler for Login */ 
const char * LOGIN_CGI_Handler(int iIndex, int iNumParams, char *pcParam[], char *pcValue[]);

/* Html request for "/login.cgi" will start LOGIN_CGI_Handler */
const tCGI LOGIN_CGI={"/login.cgi", LOGIN_CGI_Handler};

/* Cgi call table, only one CGI used */
tCGI CGI_TAB[1];

u16_t CHECK_Handler(int iIndex, char *pcInsert, int iInsertLen)
{
  /* We have only one SSI handler iIndex = 0 */
  if (iIndex ==0)
  {  
      /* prepare data to be inserted in html */
		if(in_out_flag == 1)
		{
			*pcInsert 			= (char)('I');
			*(pcInsert + 1) = (char)('N');
		}
		else
		{
			*pcInsert 			= (char)('O');
			*(pcInsert + 1) = (char)('U');
			*(pcInsert + 2) = (char)('T');
		}
    
    /* 4 characters need to be inserted in html*/
    return 4;
  }
  return 0;
}

const char *LOGIN_CGI_Handler(int iIndex, int iNumParams, char *pcParam[], char *pcValue[])
{
  uint32_t i = 0;
  
  /* We have only one SSI handler iIndex = 0 */
  if (iIndex == 0)
  {    
    /* Check cgi parameter : example GET /leds.cgi?led=2&led=4 */
    for (i = 0; i < iNumParams; i++)
    {
      /* check parameter "user" */
      if(strcmp(pcParam[i] , "user") == 0)   
      {
				/* ½T»{±b¸¹ */
        if(strcmp(pcValue[i], "root") == 0) 
				{
					/* ½T»{±K½X */
					if(strcmp(pcValue[i + 1], "123456") == 0)
						return "/Select_Option.html";
				}
      }
    }
  }
	
  return "/Login_Failure.html";  
}

/**
 * Initialize SSI handlers
 */
void httpd_ssi_init(void)
{  
  /* configure SSI handlers (ADC page SSI) */
  http_set_ssi_handler(CHECK_Handler, (char const **)TAGS, 1);
}

/**
 * Initialize CGI handlers
 */
void httpd_cgi_init(void)
{ 
  /* configure CGI handlers (LEDs control CGI) */
  CGI_TAB[0] = LOGIN_CGI;
  http_set_cgi_handlers(CGI_TAB, 1);
}

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
