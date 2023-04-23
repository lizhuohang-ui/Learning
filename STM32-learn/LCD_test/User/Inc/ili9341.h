//
// Created by 86199 on 2022/9/30.
//

#ifndef LCD_TEST_ILI9341_H
#define LCD_TEST_ILI9341_H

#include "main.h"

/******控制信号线******/
//片选
#define      ILI9341_CS_PORT               GPIOC
#define      ILI9341_CS_PIN                GPIO_PIN_4

//DC引脚
#define      ILI9341_DC_PORT               GPIOC
#define      ILI9341_DC_PIN                GPIO_PIN_7

//写使能
#define      ILI9341_WR_PORT               GPIOC
#define      ILI9341_WR_PIN                GPIO_PIN_6

//读使能
#define      ILI9341_RD_PORT               GPIOC
#define      ILI9341_RD_PIN                GPIO_PIN_5

//复位引脚直接使用NRST，开发板复位的时候会使液晶复位

//背光引脚
#define      ILI9341_BK_PORT               GPIOD
#define      ILI9341_BK_PIN                GPIO_PIN_2

/********数据信号线***************/
#define      ILI9341_DATA_PORT               GPIOB
#define      ILI9341_DATA_PIN                GPIO_PIN_All


/********信号线控制相关的宏***************/
#define	ILI9341_CS_SET  	ILI9341_CS_PORT->BSRR=ILI9341_CS_PIN    //片选端口
#define	ILI9341_DC_SET		ILI9341_DC_PORT->BSRR=ILI9341_DC_PIN    //数据/命令
#define	ILI9341_WR_SET		ILI9341_WR_PORT->BSRR=ILI9341_WR_PIN    //写数据
#define	ILI9341_RD_SET		ILI9341_RD_PORT->BSRR=ILI9341_RD_PIN    //读数据

#define	ILI9341_CS_CLR  	ILI9341_CS_PORT->BRR=ILI9341_CS_PIN     //片选端口
#define	ILI9341_DC_CLR		ILI9341_DC_PORT->BRR=ILI9341_DC_PIN     //数据/命令
#define	ILI9341_WR_CLR		ILI9341_WR_PORT->BRR=ILI9341_WR_PIN     //写数据
#define	ILI9341_RD_CLR		ILI9341_RD_PORT->BRR=ILI9341_RD_PIN     //读数据

//数据线输入输出
#define DATAOUT(x) 	ILI9341_DATA_PORT->ODR=x; //数据输出
#define DATAIN     	ILI9341_DATA_PORT->IDR;   //数据输入

/*************************************** 调试预用 ******************************************/
#define      DEBUG_DELAY()       ILI9341_Delay(0xFFFF)


/***************************** ILI934 显示区域的起始坐标和总行列数 ***************************/
#define      ILI9341_DispWindow_X_Star		    0     //起始点的X坐标
#define      ILI9341_DispWindow_Y_Star		    0     //起始点的Y坐标

#define 			ILI9341_LESS_PIXEL	  							240			//液晶屏较短方向的像素宽度
#define 			ILI9341_MORE_PIXEL	 								320			//液晶屏较长方向的像素宽度

//根据液晶扫描方向而变化的XY像素宽度
//调用ILI9341_GramScan函数设置方向时会自动更改
extern uint16_t LCD_X_LENGTH,LCD_Y_LENGTH;

//液晶屏扫描模式
//参数可选值为0-7
extern uint8_t LCD_SCAN_MODE;

/******************************* 定义 ILI934 显示屏常用颜色 ********************************/
#define      BACKGROUND		                BLACK   //默认背景颜色

#define      WHITE		 		                  0xFFFF	   //白色
#define      BLACK                         0x0000	   //黑色
#define      GREY                          0xF7DE	   //灰色
#define      BLUE                          0x001F	   //蓝色
#define      BLUE2                         0x051F	   //浅蓝色
#define      RED                           0xF800	   //红色
#define      MAGENTA                       0xF81F	   //红紫色，洋红色
#define      GREEN                         0x07E0	   //绿色
#define      CYAN                          0x7FFF	   //蓝绿色，青色
#define      YELLOW                        0xFFE0	   //黄色
#define      BRED                          0xF81F
#define      GRED                          0xFFE0
#define      GBLUE                         0x07FF



/******************************* 定义 ILI934 常用命令 ********************************/
#define      CMD_SetCoordinateX		 		    0x2A	     //设置X坐标
#define      CMD_SetCoordinateY		 		    0x2B	     //设置Y坐标
#define      CMD_SetPixel		 		          0x2C	     //填充像素


/* 定义 LCD 驱动芯片 ID */
#define     LCDID_UNKNOWN             0
#define     LCDID_ILI9341             0x9341
#define     LCDID_ST7789V             0x8552


/********************************** 声明 ILI934 函数 ***************************************/
void                     ILI9341_Init                    ( void );
uint16_t                 ILI9341_ReadID                  ( void );


#endif //LCD_TEST_ILI9341_H
