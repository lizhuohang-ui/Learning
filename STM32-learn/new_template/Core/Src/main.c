/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2023 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "dma.h"
#include "tim.h"
#include "usart.h"
#include "gpio.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "retarget.h"
#include "stdio.h"
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
uint16_t curcnt;
uint16_t oldcnt;
extern uint16_t g_timxchy_pwmin_sta;    /* PWM输入状态 */
extern uint16_t g_timxchy_pwmin_psc;    /* PWM输入分频系数 */
extern uint32_t g_timxchy_pwmin_hval;   /* PWM的高电平脉宽 */
extern uint32_t g_timxchy_pwmin_cval;   /* PWM的周期宽度 */
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/

/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
  /* USER CODE BEGIN 1 */
    double ht, ct, f, tpsc;
  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */
    RetargetInit(&huart1);
  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_DMA_Init();
  MX_USART1_UART_Init();
//  MX_TIM2_Init();
//  MX_TIM6_Init();
//  MX_TIM3_Init();
//  MX_TIM8_Init();
//  MX_TIM1_Init();
  /* USER CODE BEGIN 2 */
//    __HAL_TIM_ENABLE_IT(&htim2, TIM_IT_UPDATE);
//    HAL_TIM_IC_Start_IT(&htim2, TIM_CHANNEL_1);
//    HAL_TIM_Base_Start(&htim6);
//    HAL_TIM_PWM_Start(&htim3, TIM_CHANNEL_1);
//    __HAL_TIM_ENABLE_IT(&htim8, TIM_IT_UPDATE);
//    HAL_TIM_PWM_Start(&htim8, TIM_CHANNEL_1);
//    atim_timx_npwm_chy_set(5);
//    HAL_TIM_OC_Start(&htim1, TIM_CHANNEL_1);
//    HAL_TIM_OC_Start(&htim1, TIM_CHANNEL_2);
//    __HAL_TIM_SET_COMPARE(&htim1, TIM_CHANNEL_2, 1000 - 1);
//    __HAL_TIM_SET_COMPARE(&htim1, TIM_CHANNEL_1, 500 - 1);
//    HAL_TIM_PWM_Start(&htim1, TIM_CHANNEL_1);
//    HAL_TIMEx_PWMN_Start(&htim1, TIM_CHANNEL_1);
//    atim_timx_cplm_pwm_set(700 - 1, 250);
//    HAL_TIM_IC_Start_IT(&htim8, TIM_CHANNEL_1);
//    HAL_TIM_IC_Start(&htim8, TIM_CHANNEL_2);
    printf("hello world!");
  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
      printf("1\r\n");
//      __HAL_TIM_SET_COMPARE(&htim3, TIM_CHANNEL_1, 50);
//      HAL_Delay(1000);
//      __HAL_TIM_SET_COMPARE(&htim3, TIM_CHANNEL_1, 250);
      HAL_Delay(1000);
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
//      curcnt = __HAL_TIM_GET_COUNTER(&htim2);
//      if(oldcnt != curcnt)
//      {
//          oldcnt = curcnt;
//          printf("CNT:%d\r\n", oldcnt);
//      }
//      if (g_timxchy_pwmin_sta)    /* 捕获了一次数据 */
//      {
//          printf("\r\n");                                     /* 输出空,另起一行 */
//          printf("PWM PSC  :%d\r\n", g_timxchy_pwmin_psc);    /* 打印分频系数 */
//          printf("PWM Hight:%d\r\n", g_timxchy_pwmin_hval);   /* 打印高电平脉宽 */
//          printf("PWM Cycle:%d\r\n", g_timxchy_pwmin_cval);   /* 打印周期 */
//          tpsc = ((double)g_timxchy_pwmin_psc + 1) / 72;      /* 得到PWM采样时钟周期时间 */
//          ht = g_timxchy_pwmin_hval * tpsc;                   /* 计算高电平时间 */
//          ct = g_timxchy_pwmin_cval * tpsc;                   /* 计算周期长度 */
//          f = (1 / ct) * 1000000;                             /* 计算频率 */
//          printf("PWM Hight time:%.3fus\r\n", ht);            /* 打印高电平脉宽长度 */
//          printf("PWM Cycle time:%.3fus\r\n", ct);            /* 打印周期时间长度 */
//          printf("PWM Frequency :%.3fHz\r\n", f);             /* 打印频率 */
//          atim_timx_pwmin_chy_restart(); /* 重启PWM输入检测 */
//      }

  }
  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
  RCC_OscInitStruct.HSEState = RCC_HSE_ON;
  RCC_OscInitStruct.HSEPredivValue = RCC_HSE_PREDIV_DIV1;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
  RCC_OscInitStruct.PLL.PLLMUL = RCC_PLL_MUL9;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }
  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV2;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_2) != HAL_OK)
  {
    Error_Handler();
  }
}

/* USER CODE BEGIN 4 */

/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1)
  {
  }
  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
