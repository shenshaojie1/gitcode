/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2020 STMicroelectronics.
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

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */
void PWM_Set(void);
unsigned int PID(void);
 void system_init(void);
/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define MO6_Pin GPIO_PIN_2
#define MO6_GPIO_Port GPIOC
#define MO7_Pin GPIO_PIN_4
#define MO7_GPIO_Port GPIOC
#define MO8_Pin GPIO_PIN_7
#define MO8_GPIO_Port GPIOE
#define KEY2B_Pin GPIO_PIN_10
#define KEY2B_GPIO_Port GPIOE
#define KEY2B_EXTI_IRQn EXTI15_10_IRQn
#define KEY2A_Pin GPIO_PIN_11
#define KEY2A_GPIO_Port GPIOE
#define KEY2A_EXTI_IRQn EXTI15_10_IRQn
#define KEY1B_Pin GPIO_PIN_12
#define KEY1B_GPIO_Port GPIOE
#define KEY1B_EXTI_IRQn EXTI15_10_IRQn
#define KEY1A_Pin GPIO_PIN_13
#define KEY1A_GPIO_Port GPIOE
#define KEY1A_EXTI_IRQn EXTI15_10_IRQn
#define Ht1621_CS_Pin GPIO_PIN_12
#define Ht1621_CS_GPIO_Port GPIOB
#define Ht1621_WR_Pin GPIO_PIN_13
#define Ht1621_WR_GPIO_Port GPIOB
#define Ht1621_DAT_Pin GPIO_PIN_15
#define Ht1621_DAT_GPIO_Port GPIOB
#define KEY1_Pin GPIO_PIN_14
#define KEY1_GPIO_Port GPIOD
#define KEY1_EXTI_IRQn EXTI15_10_IRQn
#define KEY2_Pin GPIO_PIN_15
#define KEY2_GPIO_Port GPIOD
#define KEY2_EXTI_IRQn EXTI15_10_IRQn
#define LCD_Pin GPIO_PIN_6
#define LCD_GPIO_Port GPIOC
#define MO5_Pin GPIO_PIN_1
#define MO5_GPIO_Port GPIOD
#define FG5_Pin GPIO_PIN_6
#define FG5_GPIO_Port GPIOB
#define FG5_EXTI_IRQn EXTI9_5_IRQn
#define FG6_Pin GPIO_PIN_7
#define FG6_GPIO_Port GPIOB
#define FG6_EXTI_IRQn EXTI9_5_IRQn
#define FG7_Pin GPIO_PIN_8
#define FG7_GPIO_Port GPIOB
#define FG7_EXTI_IRQn EXTI9_5_IRQn
#define FG8_Pin GPIO_PIN_9
#define FG8_GPIO_Port GPIOB
#define FG8_EXTI_IRQn EXTI9_5_IRQn
/* USER CODE BEGIN Private defines */
#define Stable_Time 30
/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
