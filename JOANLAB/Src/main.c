/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
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

/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "tim.h"
#include "gpio.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "ht1623.h"
#include "lcd.h"
#include "user.h"
#include "key.h"
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */
extern uint16_t Rpm,Time_SUM,RUN_Status;

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

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
extern  uint8_t cnt;
/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

uint32_t WriteFlashData = 0x12345678;
uint32_t addr = 0x0807E000;
uint16_t  Rpm_Cnt,PWM;
extern uint16_t Set_Flag,Set_Count,Key_Count,Key1_Count;
/*FLASH????*/
void writeFlashTest(void)
{
	/* 1/4??FLASH*/
	HAL_FLASH_Unlock();


	FLASH_EraseInitTypeDef FlashSet;
	FlashSet.TypeErase = FLASH_TYPEERASE_PAGES;
	FlashSet.PageAddress = addr;
	FlashSet.NbPages = 1;
	
	
	uint32_t PageError = 0;
	HAL_FLASHEx_Erase(&FlashSet, &PageError);

	
	HAL_FLASH_Program(FLASH_TYPEPROGRAM_WORD, addr, WriteFlashData);

	
	HAL_FLASH_Lock();
}

/*FLASH??????*/
void printFlashTest(void)
{
	uint32_t temp = *(__IO uint32_t*)(addr);

	printf("addr is:0x%x, data is:0x%x\r\n", addr, temp);
}

/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
  /* USER CODE BEGIN 1 */

  /* USER CODE END 1 */
  

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_TIM1_Init();
  /* USER CODE BEGIN 2 */
	HAL_TIM_Base_Start_IT(&htim1); 
	 
   Sys_Init();
	 HAL_TIM_PWM_Start(&htim1, TIM_CHANNEL_1);
	  PWM=0;
  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
		 //HAL_GPIO_WritePin(BEEP_GPIO_Port, BEEP_Pin, GPIO_PIN_SET);//
		if(RUN_Status==Sys_RUN)
		PWM=Rpm/20;
		else PWM=0;
	//	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_8, GPIO_PIN_RESET);
	__HAL_TIM_SET_COMPARE(&htim1,TIM_CHANNEL_1,PWM);//pwm 0°™400
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
		LCD_Display();
		Key_Handle();
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

  /** Initializes the CPU, AHB and APB busses clocks 
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
  RCC_OscInitStruct.HSEState = RCC_HSE_ON;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
  RCC_OscInitStruct.PLL.PLLMUL = RCC_PLL_MUL4;
  RCC_OscInitStruct.PLL.PREDIV = RCC_PREDIV_DIV1;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }
  /** Initializes the CPU, AHB and APB busses clocks 
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_1) != HAL_OK)
  {
    Error_Handler();
  }
}

/* USER CODE BEGIN 4 */
uint32_t next,Speed_Rel;
void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
{

	//≤‚ÀŸ
		if(GPIO_Pin ==FG_Pin)
	{
		Rpm_Cnt++;
		if(Rpm_Cnt>3)
		{
			uint32_t first = HAL_GetTick();
			if((first-next)>0)
			Speed_Rel=120000/(first-next);
			//Rpm=Speed_Rel;
			next=first;
			Rpm_Cnt=0;
	  }

  }
}
uint32_t ms10;
extern uint16_t Rpm,Time_SUM;
extern uint8_t Set_Flag1,Set_Flag2;
extern uint8_t Point_Flag;
extern uint8_t Sys_Mode;
extern uint16_t BEEP_Count,BEEP_Close;
uint16_t Half_Sec;
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
  if(htim->Instance == TIM1)
  {
		ms10++;
		if(Key1_Count)
		Key1_Count--;
		
		
		if(BEEP_Close)
			BEEP_Close--;
		
		if(BEEP_Count)
			BEEP_Count--;
		 if(BEEP_Count==0)
			 HAL_GPIO_WritePin(BEEP_GPIO_Port, BEEP_Pin, GPIO_PIN_RESET);
		 
		 
		if(ms10>5000)
		{
			
			
			    Half_Sec++;
			    if(Half_Sec>1)
					{
						if(RUN_Status ==Sys_RUN)
							Time_SUM--;
						if(Time_SUM==0)
							RUN_Status =Sys_STOP;
						
						Half_Sec=0;
					}
					if(Sys_Mode==Sys_Point)
					Point_Flag=~Point_Flag;
			
			//…Ë÷√Œª÷√…¡À∏
      if(Set_Flag)
			{
				if(Set_Count)
				Set_Count--;
				else 
				{
					Set_Flag1=0;
					Set_Flag2=0;
					Set_Flag=0;
				}
				

				
				
				if(Set_Flag==1)
				Set_Flag1=~Set_Flag1;
				else if(Set_Flag==2)
				Set_Flag2=~Set_Flag2;
				
				if(Key_Count)
					Key_Count--;
			}
			ms10=0;
			
			
			
		}
		
    //10ms//0.1ms
  }
}

/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */

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
void assert_failed(char *file, uint32_t line)
{ 
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     tex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
