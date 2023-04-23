//
// Created by 86199 on 2023/4/2.
//

#ifndef LCD_LCD_H
#define LCD_LCD_H


#if __cplusplus
extern "C" {
#endif

#include "main.h"

#define LCD_BL_GPIO_PORT                GPIOC
#define LCD_BL_GPIO_PIN                 GPIO_PIN_10
#define LCD_BL_GPIO_CLK_ENABLE()        do{ __HAL_RCC_GPIOC_CLK_ENABLE(); }while(0)   /* 所在IO口时钟使能 */

#define LCD_WR_GPIO_PORT                GPIOC
#define LCD_WR_GPIO_PIN                 GPIO_PIN_7
#define LCD_WR_GPIO_CLK_ENABLE()        do{ __HAL_RCC_GPIOC_CLK_ENABLE(); }while(0)   /* 所在IO口时钟使能 */

#define LCD_RD_GPIO_PORT                GPIOC
#define LCD_RD_GPIO_PIN                 GPIO_PIN_6
#define LCD_RD_GPIO_CLK_ENABLE()        do{ __HAL_RCC_GPIOC_CLK_ENABLE(); }while(0)   /* 所在IO口时钟使能 */


#define LCD_CS_GPIO_PORT                GPIOC
#define LCD_CS_GPIO_PIN                 GPIO_PIN_9
#define LCD_CS_GPIO_CLK_ENABLE()        do{ __HAL_RCC_GPIOC_CLK_ENABLE(); }while(0)   /* 所在IO口时钟使能 */

#define LCD_RS_GPIO_PORT                GPIOC
#define LCD_RS_GPIO_PIN                 GPIO_PIN_8
#define LCD_RS_GPIO_CLK_ENABLE()        do{ __HAL_RCC_GPIOC_CLK_ENABLE(); }while(0)   /* 所在IO口时钟使能 */

#define LCD_DATA_GPIO_PORT              GPIOB
#define LCD_DATA_GPIO_PIN               GPIO_PIN_All                                  /* 16个IO都用到 */
#define LCD_DATA_GPIO_CLK_ENABLE()      do{ __HAL_RCC_GPIOB_CLK_ENABLE(); }while(0)   /* 所在IO口时钟使能 */

/* LCD 端口控制函数定义 */
/* 利用操作寄存器的方式控制IO引脚提高屏幕的刷新率 */
#define LCD_BL(x)       LCD_BL_GPIO_PORT->BSRR = LCD_BL_GPIO_PIN << (16 * (!x))     /* 设置BL引脚 */

#define LCD_WR(x)       LCD_WR_GPIO_PORT->BSRR = LCD_WR_GPIO_PIN << (16 * (!x))     /* 设置WR引脚 */
#define LCD_RD(x)       LCD_RD_GPIO_PORT->BSRR = LCD_RD_GPIO_PIN << (16 * (!x))     /* 设置RD引脚 */
#define LCD_CS(x)       LCD_CS_GPIO_PORT->BSRR = LCD_CS_GPIO_PIN << (16 * (!x))     /* 设置CS引脚 */
#define LCD_RS(x)       LCD_RS_GPIO_PORT->BSRR = LCD_RS_GPIO_PIN << (16 * (!x))     /* 设置RS引脚 */


#define LCD_DATA_OUT(x) LCD_DATA_GPIO_PORT->ODR = x                                 /* 写B0~B15引脚 */
#define LCD_DATA_IN     LCD_DATA_GPIO_PORT->IDR

/* LCD扫描方向和颜色 定义 */

/* 扫描方向定义 */
#define L2R_U2D         0           /* 从左到右,从上到下 */
#define L2R_D2U         1           /* 从左到右,从下到上 */
#define R2L_U2D         2           /* 从右到左,从上到下 */
#define R2L_D2U         3           /* 从右到左,从下到上 */

#define U2D_L2R         4           /* 从上到下,从左到右 */
#define U2D_R2L         5           /* 从上到下,从右到左 */
#define D2U_L2R         6           /* 从下到上,从左到右 */
#define D2U_R2L         7           /* 从下到上,从右到左 */

#define DFT_SCAN_DIR    L2R_U2D     /* 默认的扫描方向 */

/* 常用画笔颜色 */
#define WHITE           0xFFFF      /* 白色 */
#define BLACK           0x0000      /* 黑色 */
#define RED             0xF800      /* 红色 */
#define GREEN           0x07E0      /* 绿色 */
#define BLUE            0x001F      /* 蓝色 */
#define MAGENTA         0XF81F      /* 品红色/紫红色 = BLUE + RED */
#define YELLOW          0XFFE0      /* 黄色 = GREEN + RED */
#define CYAN            0X07FF      /* 青色 = GREEN + BLUE */

/* 非常用颜色 */
#define BROWN           0XBC40      /* 棕色 */
#define BRRED           0XFC07      /* 棕红色 */
#define GRAY            0X8430      /* 灰色 */
#define DARKBLUE        0X01CF      /* 深蓝色 */
#define LIGHTBLUE       0X7D7C      /* 浅蓝色 */
#define GRAYBLUE        0X5458      /* 灰蓝色 */
#define LIGHTGREEN      0X841F      /* 浅绿色 */
#define LGRAY           0XC618      /* 浅灰色(PANNEL),窗体背景色 */
#define LGRAYBLUE       0XA651      /* 浅灰蓝色(中间层颜色) */
#define LBBLUE          0X2B12      /* 浅棕蓝色(选择条目的反色) */

/* LCD写数据, 将函数改成宏定义函数, 以达到最高速度
 * -O2优化时, 如果lcd_wr_data使用普通函数定义, 只能到15帧刷屏
 * -O2优化时, 如果lcd_wr_data使用__forceinline函数定义, 能到39帧刷屏
 * -O2优化时, 如果lcd_wr_data使用宏定义函数, 能到51帧刷屏
 */
#define lcd_wr_data(data)\
    {\
        LCD_RS(1);\
        LCD_CS(0);\
        LCD_DATA_OUT(data);\
        LCD_WR(0);\
        LCD_WR(1);\
        LCD_CS(1);\
    }

class lcd {
public:
    uint16_t width;     /* LCD 宽度 */
    uint16_t height;    /* LCD 高度 */
    uint16_t id;        /* LCD ID */
    uint8_t dir;        /* 横屏还是竖屏控制：0，竖屏；1，横屏。 */
    uint16_t wramcmd;   /* 开始写gram指令 */
    uint16_t setxcmd;   /* 设置x坐标指令 */
    uint16_t setycmd;   /* 设置y坐标指令 */
public:
    void lcd_wr_xdata(uint16_t data);                   /* LCD写数据, 该函数同 lcd_wr_data 函数的功能一模一样 */
    static void lcd_wr_regno(volatile uint16_t regno);          /* LCD写寄存器编号/地址 */
    void lcd_write_reg(uint16_t regno, uint16_t data);   /* LCD写寄存器的值 */
    static uint16_t lcd_rd_data();

    void lcd_init();                        /* 初始化LCD */
    void lcd_display_on();                  /* 开显示 */
    void lcd_display_off();                 /* 关显示 */
    void lcd_scan_dir(uint8_t dir);             /* 设置屏扫描方向 */
    void lcd_display_dir(uint8_t dir);          /* 设置屏幕显示方向 */
//    void lcd_ssd_backlight_set(uint8_t pwm);    /* SSD1963 背光控制 */

    void lcd_write_ram_prepare(void);               /* 准备些GRAM */
    void lcd_set_cursor(uint16_t x, uint16_t y);    /* 设置光标 */
    uint32_t lcd_read_point(uint16_t x, uint16_t y);/* 读点(32位颜色,兼容LTDC)  */
    void lcd_draw_point(uint16_t x, uint16_t y, uint32_t color);/* 画点(32位颜色,兼容LTDC) */

    void lcd_clear(uint16_t color);     /* LCD清屏 */
    void lcd_fill_circle(uint16_t x, uint16_t y, uint16_t r, uint16_t color);                   /* 填充实心圆 */
    void lcd_draw_circle(uint16_t x0, uint16_t y0, uint8_t r, uint16_t color);                  /* 画圆 */
    void lcd_draw_hline(uint16_t x, uint16_t y, uint16_t len, uint16_t color);                  /* 画水平线 */
    void lcd_set_window(uint16_t sx, uint16_t sy, uint16_t width, uint16_t height);             /* 设置窗口 */
    void lcd_fill(uint16_t sx, uint16_t sy, uint16_t ex, uint16_t ey, uint32_t color);          /* 纯色填充矩形(32位颜色,兼容LTDC) */
    void lcd_color_fill(uint16_t sx, uint16_t sy, uint16_t ex, uint16_t ey, uint16_t *color);   /* 彩色填充矩形 */
    void lcd_draw_line(uint16_t x1, uint16_t y1, uint16_t x2, uint16_t y2, uint16_t color);     /* 画直线 */
    void lcd_draw_rectangle(uint16_t x1, uint16_t y1, uint16_t x2, uint16_t y2, uint16_t color);/* 画矩形 */


    void lcd_show_char(uint16_t x, uint16_t y, char chr, uint8_t size, uint8_t mode, uint16_t color);
    void lcd_show_num(uint16_t x, uint16_t y, uint32_t num, uint8_t len, uint8_t size, uint16_t color);
    void lcd_show_xnum(uint16_t x, uint16_t y, uint32_t num, uint8_t len, uint8_t size, uint8_t mode, uint16_t color);
    void lcd_show_string(uint16_t x, uint16_t y, uint16_t width, uint16_t height, uint8_t size, char *p, uint16_t color);

};

/* LCD参数 */
extern lcd lcddev; /* 管理LCD重要参数 */

/* LCD的画笔颜色和背景色 */
extern uint32_t  g_point_color;     /* 默认红色 */
extern uint32_t  g_back_color;      /* 背景颜色.默认为白色 */



#if __cplusplus
}

#endif

#endif //LCD_LCD_H
