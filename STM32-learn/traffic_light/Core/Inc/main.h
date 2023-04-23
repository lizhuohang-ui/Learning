/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2022 STMicroelectronics.
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

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f1xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "traffic_light.h"
#include "nixie.h"
/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define nixie_A_Pin GPIO_PIN_6
#define nixie_A_GPIO_Port GPIOA
#define nixie_B_Pin GPIO_PIN_7
#define nixie_B_GPIO_Port GPIOA
#define nixie_C_Pin GPIO_PIN_8
#define nixie_C_GPIO_Port GPIOA
#define nixie_D_Pin GPIO_PIN_9
#define nixie_D_GPIO_Port GPIOA
#define check_count_Pin GPIO_PIN_0
#define check_count_GPIO_Port GPIOA
#define check_count_EXTI_IRQn EXTI0_IRQn
#define east_run_Pin GPIO_PIN_1
#define east_run_GPIO_Port GPIOA
#define east_run_EXTI_IRQn EXTI1_IRQn
#define south_run_Pin GPIO_PIN_2
#define south_run_GPIO_Port GPIOA
#define south_run_EXTI_IRQn EXTI2_IRQn
#define west_run_Pin GPIO_PIN_3
#define west_run_GPIO_Port GPIOA
#define west_run_EXTI_IRQn EXTI3_IRQn
#define north_run_Pin GPIO_PIN_4
#define north_run_GPIO_Port GPIOA
#define north_run_EXTI_IRQn EXTI4_IRQn
#define reset_count_Pin GPIO_PIN_5
#define reset_count_GPIO_Port GPIOA
#define reset_count_EXTI_IRQn EXTI9_5_IRQn
#define nixie_E_Pin GPIO_PIN_10
#define nixie_E_GPIO_Port GPIOA
#define nixie_F_Pin GPIO_PIN_11
#define nixie_F_GPIO_Port GPIOA
#define east_red_Pin GPIO_PIN_0
#define east_red_GPIO_Port GPIOB
#define east_yellow_Pin GPIO_PIN_1
#define east_yellow_GPIO_Port GPIOB
#define east_green_Pin GPIO_PIN_2
#define east_green_GPIO_Port GPIOB
#define north_yellow_Pin GPIO_PIN_4
#define north_yellow_GPIO_Port GPIOB
#define north_green_Pin GPIO_PIN_5
#define north_green_GPIO_Port GPIOB
#define nixie_G_Pin GPIO_PIN_12
#define nixie_G_GPIO_Port GPIOA
#define nixie_1_Pin GPIO_PIN_6
#define nixie_1_GPIO_Port GPIOB
#define nixie_2_Pin GPIO_PIN_7
#define nixie_2_GPIO_Port GPIOB
#define nixie_3_Pin GPIO_PIN_8
#define nixie_3_GPIO_Port GPIOB
#define nixie_4_Pin GPIO_PIN_9
#define nixie_4_GPIO_Port GPIOB
#define south_red_Pin GPIO_PIN_3
#define south_red_GPIO_Port GPIOB
#define south_yellow_Pin GPIO_PIN_4
#define south_yellow_GPIO_Port GPIOB
#define south_green_Pin GPIO_PIN_5
#define south_green_GPIO_Port GPIOB
#define west_red_Pin GPIO_PIN_0
#define west_red_GPIO_Port GPIOB
#define west_yellow_Pin GPIO_PIN_1
#define west_yellow_GPIO_Port GPIOB
#define west_green_Pin GPIO_PIN_2
#define west_green_GPIO_Port GPIOB
#define north_red_Pin GPIO_PIN_3
#define north_red_GPIO_Port GPIOB
/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
