#include "my_bmp.h"

unsigned char image[BMP_LENGTH * BMP_WIDTH + BMP_HEADER] = {0};

void LCD_ShowBMP(uint32_t BmpAddress)
{
    uint32_t index = 0, size = 0;
    /* Read bitmap size */
    size = *(__IO uint16_t *) (BmpAddress + 2);
    size |= (*(__IO uint16_t *) (BmpAddress + 4)) << 16;
    /* Get bitmap data address offset */
    index = *(__IO uint16_t *) (BmpAddress + 10);
    index |= (*(__IO uint16_t *) (BmpAddress + 12)) << 16;
    size = (size - index)/2;
    BmpAddress += index;
    /* Set GRAM write direction and BGR = 1 */
    /* I/D=00 (Horizontal : decrement, Vertical : decrement) */
    /* AM=1 (address is updated in vertical writing direction) */
    LCD_WriteReg(LCD_REG_3, 0x1008);

    LCD_WriteRAM_Prepare();

    for(index = 0; index < size; index++) {
        LCD_WriteRAM(*(__IO uint8_t *)BmpAddress);
        BmpAddress += 1;
    }

    /* Set GRAM write direction and BGR = 1 */
    /* I/D = 01 (Horizontal : increment, Vertical : decrement) */
    /* AM = 1 (address is updated in vertical writing direction) */
    LCD_WriteReg(LCD_REG_3, 0x1018);
}

void LCD_DrawGrayPict(const uint8_t *Pict)
{
    uint32_t index = 0, i = 0;
    LCD_SetCursor(0, (LCD_PIXEL_WIDTH - 1));
    LCD_WriteRAM_Prepare(); /* Prepare to write GRAM */
    for(index = 0; index < BMP_LENGTH * BMP_WIDTH; index++) {
        //LCD_WriteRAM(ASSEMBLE_RGB((*(__IO uint8_t *)Pict) / 10 * 4, (*(__IO uint8_t *)Pict) / 10 * 5, (*(__IO uint8_t *)Pict) / 10 * 5));
        //LCD_WriteRAM(ASSEMBLE_RGB(*(__IO uint8_t *)Pict, *(__IO uint8_t *)Pict, *(__IO uint8_t *)Pict));
        LCD_WriteRAM(*(__IO uint16_t *)Pict);
        Pict += 1;
    }
}

void LCD_Draw16BitBMP(const uint16_t *Pict)
{
    uint32_t index = 0, i = 0;
    LCD_SetCursor(0, (LCD_PIXEL_WIDTH - 1));
    LCD_WriteRAM_Prepare(); /* Prepare to write GRAM */
    for(index = 0; index < BMP_LENGTH * BMP_WIDTH; index++) {
        //LCD_WriteRAM(ASSEMBLE_RGB((*(__IO uint8_t *)Pict) / 10 * 4, (*(__IO uint8_t *)Pict) / 10 * 5, (*(__IO uint8_t *)Pict) / 10 * 5));
        //LCD_WriteRAM(ASSEMBLE_RGB(*(__IO uint8_t *)Pict, *(__IO uint8_t *)Pict, *(__IO uint8_t *)Pict));
        LCD_WriteRAM(*(__IO uint16_t *)Pict);
        Pict += 1;
    }
}
