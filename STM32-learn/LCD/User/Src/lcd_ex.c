//
// Created by 86199 on 2023/4/2.
//

#include "lcd.h"


/**
 * @brief       ILI9341寄存器初始化代码
 * @param       无
 * @retval      无
 */
void lcd_ex_ili9341_reginit(void)
{
    lcd.lcd_wr_regno(0xCF);
    lcd.lcd_wr_xdata(0x00);
    lcd.lcd_wr_xdata(0xC1);
    lcd.lcd_wr_xdata(0X30);
    lcd.lcd_wr_regno(0xED);
    lcd.lcd_wr_xdata(0x64);
    lcd.lcd_wr_xdata(0x03);
    lcd.lcd_wr_xdata(0X12);
    lcd.lcd_wr_xdata(0X81);
    lcd.lcd_wr_regno(0xE8);
    lcd.lcd_wr_xdata(0x85);
    lcd.lcd_wr_xdata(0x10);
    lcd.lcd_wr_xdata(0x7A);
    lcd.lcd_wr_regno(0xCB);
    lcd.lcd_wr_xdata(0x39);
    lcd.lcd_wr_xdata(0x2C);
    lcd.lcd_wr_xdata(0x00);
    lcd.lcd_wr_xdata(0x34);
    lcd.lcd_wr_xdata(0x02);
    lcd.lcd_wr_regno(0xF7);
    lcd.lcd_wr_xdata(0x20);
    lcd.lcd_wr_regno(0xEA);
    lcd.lcd_wr_xdata(0x00);
    lcd.lcd_wr_xdata(0x00);
    lcd.lcd_wr_regno(0xC0); /* Power control */
    lcd.lcd_wr_xdata(0x1B);  /* VRH[5:0] */
    lcd.lcd_wr_regno(0xC1); /* Power control */
    lcd.lcd_wr_xdata(0x01);  /* SAP[2:0];BT[3:0] */
    lcd.lcd_wr_regno(0xC5); /* VCM control */
    lcd.lcd_wr_xdata(0x30);  /* 3F */
    lcd.lcd_wr_xdata(0x30);  /* 3C */
    lcd.lcd_wr_regno(0xC7); /* VCM control2 */
    lcd.lcd_wr_xdata(0XB7);
    lcd.lcd_wr_regno(0x36); /*  Memory Access Control */
    lcd.lcd_wr_xdata(0x48);
    lcd.lcd_wr_regno(0x3A);
    lcd.lcd_wr_xdata(0x55);
    lcd.lcd_wr_regno(0xB1);
    lcd.lcd_wr_xdata(0x00);
    lcd.lcd_wr_xdata(0x1A);
    lcd.lcd_wr_regno(0xB6); /*  Display Function Control */
    lcd.lcd_wr_xdata(0x0A);
    lcd.lcd_wr_xdata(0xA2);
    lcd.lcd_wr_regno(0xF2); /*  3Gamma Function Disable */
    lcd.lcd_wr_xdata(0x00);
    lcd.lcd_wr_regno(0x26); /* Gamma curve selected */
    lcd.lcd_wr_xdata(0x01);
    lcd.lcd_wr_regno(0xE0); /* Set Gamma */
    lcd.lcd_wr_xdata(0x0F);
    lcd.lcd_wr_xdata(0x2A);
    lcd.lcd_wr_xdata(0x28);
    lcd.lcd_wr_xdata(0x08);
    lcd.lcd_wr_xdata(0x0E);
    lcd.lcd_wr_xdata(0x08);
    lcd.lcd_wr_xdata(0x54);
    lcd.lcd_wr_xdata(0XA9);
    lcd.lcd_wr_xdata(0x43);
    lcd.lcd_wr_xdata(0x0A);
    lcd.lcd_wr_xdata(0x0F);
    lcd.lcd_wr_xdata(0x00);
    lcd.lcd_wr_xdata(0x00);
    lcd.lcd_wr_xdata(0x00);
    lcd.lcd_wr_xdata(0x00);
    lcd.lcd_wr_regno(0XE1);    /* Set Gamma */
    lcd.lcd_wr_xdata(0x00);
    lcd.lcd_wr_xdata(0x15);
    lcd.lcd_wr_xdata(0x17);
    lcd.lcd_wr_xdata(0x07);
    lcd.lcd_wr_xdata(0x11);
    lcd.lcd_wr_xdata(0x06);
    lcd.lcd_wr_xdata(0x2B);
    lcd.lcd_wr_xdata(0x56);
    lcd.lcd_wr_xdata(0x3C);
    lcd.lcd_wr_xdata(0x05);
    lcd.lcd_wr_xdata(0x10);
    lcd.lcd_wr_xdata(0x0F);
    lcd.lcd_wr_xdata(0x3F);
    lcd.lcd_wr_xdata(0x3F);
    lcd.lcd_wr_xdata(0x0F);
    lcd.lcd_wr_regno(0x2B);
    lcd.lcd_wr_xdata(0x00);
    lcd.lcd_wr_xdata(0x00);
    lcd.lcd_wr_xdata(0x01);
    lcd.lcd_wr_xdata(0x3f);
    lcd.lcd_wr_regno(0x2A);
    lcd.lcd_wr_xdata(0x00);
    lcd.lcd_wr_xdata(0x00);
    lcd.lcd_wr_xdata(0x00);
    lcd.lcd_wr_xdata(0xef);
    lcd.lcd_wr_regno(0x11); /* Exit Sleep */
    HAL_Delay(120);
    lcd.lcd_wr_regno(0x29); /* display on */
}
