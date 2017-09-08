#include "my_fatfs.h"

FATFS fs;
FIL		file;

uint32_t ret_length = 0;
char write_in[]  = "2F IN.";
char write_out[] = "2F OUT.";

void SDCard_Config(void)
{
    SD_Error Status;

    /* SD Init */
    Status = SD_Init();

    /* Verify the SDIO SD */
    if(Status == SD_OK) {
        LCD_DbgLog("'SDIO SD intialized\n");
    } else {
        LCD_ErrLog("SDIO SD initialization failed \n");
    }
}

void InOut_Write(uint8_t in_out_flag)
{
    /* FATFS 掛載 */
    f_mount( 0, &fs );

    /* FATFS 開檔 */
    f_open(&file, "0:/Member_InOut.txt", FA_OPEN_ALWAYS | FA_WRITE);

    /* FATFS 將指針移動到文件結尾處 */
    f_lseek(&file, file.fsize);

    /* FATFS 寫檔 */
    f_write(&file, "\r\n", 2, &ret_length);

    /* Get the current Date */
    RTC_GetDate(RTC_Format_BIN, &RTC_DateStructure1);

    rtc_high[2] = ((RTC_DateStructure1.RTC_Year / 10) + 0x30);
    rtc_high[1] = ((RTC_DateStructure1.RTC_Year % 10) + 0x30);
    rtc_high[0] = '\0';
    rtc_med[2]  = ((RTC_DateStructure1.RTC_Month / 10) + 0x30);
    rtc_med[1] 	= ((RTC_DateStructure1.RTC_Month % 10) + 0x30);
    rtc_med[0] 	= '\0';
    rtc_low[2]  = ((RTC_DateStructure1.RTC_Date / 10) + 0x30);
    rtc_low[1] 	= ((RTC_DateStructure1.RTC_Date % 10) + 0x30);
    rtc_low[0]	= '\0';

    uint8_t date_display[] = {'2', '0', rtc_high[2], rtc_high[1], '/', rtc_med[2], rtc_med[1], '/', rtc_low[2], rtc_low[1], '\0'};

    /* 日期寫入 */
    f_write(&file, date_display, sizeof(date_display), &ret_length);

    /* Get the current Time */
    RTC_GetTime(RTC_Format_BIN, &RTC_TimeStructure1);

    rtc_high[2] = ((RTC_TimeStructure1.RTC_Hours / 10) + 0x30);
    rtc_high[1] = ((RTC_TimeStructure1.RTC_Hours % 10) + 0x30);
    rtc_high[0] = '\0';
    rtc_med[2]  = ((RTC_TimeStructure1.RTC_Minutes / 10) + 0x30);
    rtc_med[1] 	= ((RTC_TimeStructure1.RTC_Minutes % 10) + 0x30);
    rtc_med[0] 	= '\0';
    rtc_low[2]  = ((RTC_TimeStructure1.RTC_Seconds / 10) + 0x30);
    rtc_low[1] 	= ((RTC_TimeStructure1.RTC_Seconds % 10) + 0x30);
    rtc_low[0]	= '\0';

    uint8_t time_display[] = {' ', rtc_high[2], rtc_high[1], ':', rtc_med[2], rtc_med[1], ':', rtc_low[2], rtc_low[1], ' ', '\0'};

    /* 時間寫入 */
    f_write(&file, time_display, sizeof(time_display), &ret_length);

    /* 進出入寫入 */
    if(in_out_flag == 1) {
        /* FATFS 寫檔 */
        if (f_write(&file, write_in, sizeof(write_in), &ret_length) != FR_OK) {
            LCD_ErrLog("Cannot write on file\n");
        }
    } else {
        /* FATFS 寫檔 */
        if (f_write(&file, write_out, sizeof(write_out), &ret_length) != FR_OK) {
            LCD_ErrLog("Cannot write on file\n");
        }
    }

    in_out_enable = 0;

    /* FATFS 關檔 */
    f_close(&file);

    /* FATFS 卸載 */
    f_mount(0, NULL);
}
