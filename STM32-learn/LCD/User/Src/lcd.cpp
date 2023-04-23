//
// Created by 86199 on 2023/4/2.
//

#if __cplusplus
extern "C" {
#endif

#include "lcd.h"
#include <cstdio>

/* LCD的画笔颜色和背景色 */
uint32_t g_point_color = 0XF800;    /* 画笔颜色 */
uint32_t g_back_color = 0XFFFF;    /* 背景色 */

/* 管理LCD重要参数 */
lcd lcddev;

/**
 * @brief       LCD写数据
 *   @note      该函数的功能和 lcd_wr_data 完全一模一样
 *              lcd_wr_data 是用空间换时间, 该函数则是时间换空间
 *              该函数用于LCD初始化, 仅在 lcd_ex.c 里面调用, 以节
 *              省代码空间.
 * @param       data : 要写入的数据
 * @retval      无
 */
void lcd::lcd_wr_xdata(uint16_t data) {
    LCD_RS(1);
    LCD_CS(0);
    LCD_DATA_OUT(data);
    LCD_WR(0);
    LCD_WR(1);
    LCD_CS(1);
}

/**
 * @brief       LCD写寄存器编号/地址函数
 * @param       regno: 寄存器编号/地址
 * @retval      无
 */
__attribute__((always_inline)) void lcd::lcd_wr_regno(volatile uint16_t regno) {
    LCD_RS(0);              /* RS=0,表示写寄存器 */
    LCD_CS(0);
    LCD_DATA_OUT(regno);    /* 写入要写的寄存器序号 */
    LCD_WR(0);
    LCD_WR(1);
    LCD_CS(1);
}

/**
 * @brief       LCD写寄存器
 * @param       regno:寄存器编号/地址
 * @param       data:要写入的数据
 * @retval      无
 */
void lcd::lcd_write_reg(uint16_t regno, uint16_t data) {
    lcd_wr_regno(regno);    /* 写入要写的寄存器序号 */
    lcd_wr_data(data);      /* 写入数据 */
}

/**
 * @brief       LCD读数据
 * @param       无
 * @retval      读取到的数据
 */
uint16_t lcd::lcd_rd_data() {
    volatile uint16_t ram;  /* 防止被优化 */
    GPIO_InitTypeDef gpio_init_struct;
    /* LCD_DATA 引脚模式设置, 上拉输入, 准备接收数据 */
    gpio_init_struct.Pin = LCD_DATA_GPIO_PIN;
    gpio_init_struct.Mode = GPIO_MODE_INPUT;
    gpio_init_struct.Pull = GPIO_PULLUP;
    gpio_init_struct.Speed = GPIO_SPEED_FREQ_HIGH;
    HAL_GPIO_Init(LCD_DATA_GPIO_PORT, &gpio_init_struct);

    LCD_RS(1);              /* RS=1,表示操作数据 */
    LCD_CS(0);
    LCD_RD(0);
    ram = LCD_DATA_IN;      /* 读取数据 */
    LCD_RD(1);
    LCD_CS(1);
    /* LCD_DATA 引脚模式设置, 推挽输出, 恢复输出状态 */
    gpio_init_struct.Pin = LCD_DATA_GPIO_PIN;
    gpio_init_struct.Mode = GPIO_MODE_OUTPUT_PP;
    gpio_init_struct.Pull = GPIO_PULLUP;
    gpio_init_struct.Speed = GPIO_SPEED_FREQ_HIGH;
    HAL_GPIO_Init(LCD_DATA_GPIO_PORT, &gpio_init_struct);

    return ram;
}

/**
 * @brief       准备写GRAM
 * @param       无
 * @retval      无
 */
__attribute__((always_inline)) void lcd_write_ram_prepare(void) {
    lcddev.lcd_wr_regno(lcddev.wramcmd);
}


/**
 * @brief       LCD延时函数,仅用于部分在mdk -O1时间优化时需要设置的地方
 * @param       t:延时的数值
 * @retval      无
 */
static void lcd_opt_delay(uint32_t i) {
    while (i--);
}

void lcd::lcd_init(void) {
    GPIO_InitTypeDef gpio_init_struct;

    LCD_BL_GPIO_CLK_ENABLE();   /* LCD_BL脚时钟使能 */
    LCD_CS_GPIO_CLK_ENABLE();   /* LCD_CS脚时钟使能 */
    LCD_WR_GPIO_CLK_ENABLE();   /* LCD_WR脚时钟使能 */
    LCD_RD_GPIO_CLK_ENABLE();   /* LCD_RD脚时钟使能 */
    LCD_RS_GPIO_CLK_ENABLE();   /* LCD_RS脚时钟使能 */
    LCD_DATA_GPIO_CLK_ENABLE(); /* LCD_DATA脚时钟使能 */
    __HAL_RCC_AFIO_CLK_ENABLE();
    __HAL_AFIO_REMAP_SWJ_NOJTAG(); /* 禁止JTAG, 使能SWD, 释放PB3,PB4两个引脚做普通IO用 */

    gpio_init_struct.Pin = LCD_BL_GPIO_PIN;
    gpio_init_struct.Mode = GPIO_MODE_OUTPUT_PP;
    gpio_init_struct.Pull = GPIO_PULLUP;
    gpio_init_struct.Speed = GPIO_SPEED_FREQ_HIGH;
    HAL_GPIO_Init(LCD_BL_GPIO_PORT, &gpio_init_struct);     /* LCD_BL引脚模式设置(推挽输出) */

    gpio_init_struct.Pin = LCD_CS_GPIO_PIN;
    gpio_init_struct.Mode = GPIO_MODE_OUTPUT_PP;            /* 推挽复用 */
    gpio_init_struct.Pull = GPIO_PULLUP;                    /* 上拉 */
    gpio_init_struct.Speed = GPIO_SPEED_FREQ_HIGH;          /* 高速 */
    HAL_GPIO_Init(LCD_CS_GPIO_PORT, &gpio_init_struct);     /* 初始化LCD_CS引脚 */

    gpio_init_struct.Pin = LCD_WR_GPIO_PIN;
    HAL_GPIO_Init(LCD_WR_GPIO_PORT, &gpio_init_struct);     /* 初始化LCD_WR引脚 */

    gpio_init_struct.Pin = LCD_RD_GPIO_PIN;
    HAL_GPIO_Init(LCD_RD_GPIO_PORT, &gpio_init_struct);     /* 初始化LCD_RD引脚 */

    gpio_init_struct.Pin = LCD_RS_GPIO_PIN;
    HAL_GPIO_Init(LCD_RS_GPIO_PORT, &gpio_init_struct);     /* 初始化LCD_RS引脚 */

    gpio_init_struct.Pin = LCD_DATA_GPIO_PIN;
    gpio_init_struct.Mode = GPIO_MODE_OUTPUT_PP;            /* 推挽输出 */
    HAL_GPIO_Init(LCD_DATA_GPIO_PORT, &gpio_init_struct);   /* LCD_DATA引脚模式设置 */
    LCD_WR(1);                  /* WR 默认高电平 */
    LCD_RD(1);                  /* RD 默认高电平 */
    LCD_CS(1);                  /* CS 默认高电平 */
    LCD_RS(1);                  /* RS 默认高电平 */
    LCD_DATA_OUT(0XFFFF);       /* DATA 默认高电平 */

    lcd_opt_delay(0X1FFFF);     /* 初始化FSMC后,必须等待一定时间才能开始初始化 */

    /* 尝试9341 ID的读取 */
    lcd_wr_regno(0XD3);
    lcddev.id = lcd_rd_data();  /* dummy read */
    lcddev.id = lcd_rd_data();  /* 读到0X00 */
    lcddev.id = lcd_rd_data();  /* 读取0X93 */
    lcddev.id <<= 8;
    lcddev.id |= lcd_rd_data(); /* 读取0X41 */

    if (lcddev.id != 0X9341)    /* 不是 9341 , 尝试看看是不是 ST7789 */
    {
        lcd_wr_regno(0X04);
        lcddev.id = lcd_rd_data();      /* dummy read */
        lcddev.id = lcd_rd_data();      /* 读到0X85 */
        lcddev.id = lcd_rd_data();      /* 读取0X85 */
        lcddev.id <<= 8;
        lcddev.id |= lcd_rd_data();     /* 读取0X52 */

        if (lcddev.id == 0X8552)        /* 将8552的ID转换成7789 */
        {
            lcddev.id = 0x7789;
        }

        if (lcddev.id != 0x7789)        /* 也不是ST7789, 尝试是不是 NT35310 */
        {
            lcd_wr_regno(0XD4);
            lcddev.id = lcd_rd_data();  /* dummy read */
            lcddev.id = lcd_rd_data();  /* 读回0X01 */
            lcddev.id = lcd_rd_data();  /* 读回0X53 */
            lcddev.id <<= 8;
            lcddev.id |= lcd_rd_data(); /* 这里读回0X10 */

            if (lcddev.id != 0X5310)    /* 也不是NT35310,尝试看看是不是NT35510 */
            {
                /* 发送秘钥（厂家提供,照搬即可） */
                lcd_write_reg(0xF000, 0x0055);
                lcd_write_reg(0xF001, 0x00AA);
                lcd_write_reg(0xF002, 0x0052);
                lcd_write_reg(0xF003, 0x0008);
                lcd_write_reg(0xF004, 0x0001);

                lcd_wr_regno(0xC500);           /* 读取ID高8位 */
                lcddev.id = lcd_rd_data();      /* 读回0X55 */
                lcddev.id <<= 8;

                lcd_wr_regno(0xC501);           /* 读取ID低8位 */
                lcddev.id |= lcd_rd_data();     /* 读回0X10 */
                HAL_Delay(5);

                if (lcddev.id != 0X5510)        /* 也不是NT5510,尝试看看是不是SSD1963 */
                {
                    lcd_wr_regno(0XA1);
                    lcddev.id = lcd_rd_data();
                    lcddev.id = lcd_rd_data();  /* 读回0X57 */
                    lcddev.id <<= 8;
                    lcddev.id |= lcd_rd_data(); /* 读回0X61 */

                    if (lcddev.id == 0X5761)lcddev.id = 0X1963; /* SSD1963读回的ID是5761H,为方便区分,我们强制设置为1963 */
                }
            }
        }
    }

    /* 特别注意, 如果在main函数里面屏蔽串口1初始化, 则会卡死在printf
     * 里面(卡死在f_putc函数), 所以, 必须初始化串口1, 或者屏蔽掉下面
     * 这行 printf 语句 !!!!!!!
     */
    printf("LCD ID:%x\r\n", lcddev.id); /* 打印LCD ID */

//    if (lcddev.id == 0X7789)
//    {
//        lcd_ex_st7789_reginit();    /* 执行ST7789初始化 */
//    }
//    else if (lcddev.id == 0X9341)
//    {
//        lcd_ex_ili9341_reginit();   /* 执行ILI9341初始化 */
//    }
//    else if (lcddev.id == 0x5310)
//    {
//        lcd_ex_nt35310_reginit();   /* 执行NT35310初始化 */
//    }
//    else if (lcddev.id == 0x5510)
//    {
//        lcd_ex_nt35510_reginit();   /* 执行NT35510初始化 */
//    }
//    else if (lcddev.id == 0X1963)
//    {
//        lcd_ex_ssd1963_reginit();   /* 执行SSD1963初始化 */
//        lcd_ssd_backlight_set(100); /* 背光设置为最亮 */
//    }

    lcd_display_dir(0); /* 默认为竖屏 */
    LCD_BL(1);          /* 点亮背光 */
    lcd_clear(WHITE);
}

void lcd::lcd_display_on(void) {

}

void lcd::lcd_display_off(void) {

}

void lcd::lcd_scan_dir(uint8_t dir) {

}

void lcd::lcd_display_dir(uint8_t dir) {

}

#if __cplusplus
}
#endif