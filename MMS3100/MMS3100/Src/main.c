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
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
extern uint16_t System_Stutas;
extern uint8_t Time_Stutas;
extern uint8_t Time1_Stutas;
extern uint8_t Time2_Stutas;
extern uint8_t Time3_Stutas;
extern uint8_t Time4_Stutas;
extern  uint16_t M1_Speed;
uint16_t cnt1,cnt2;
uint16_t rpm1_cnt;
uint16_t rpm2_cnt;
uint16_t rpm3_cnt;
uint16_t rpm4_cnt;
uint16_t Set_Cnt;
uint16_t Set_Speed;
uint32_t next_cnt;
int Set_Flag;
int Dis_Flag;
uint8_t Set_Mode;
int Set_Time_R;
int Set_Time_L;
extern  uint16_t L1_Speed;
extern  uint16_t L3_Speed;
extern  uint16_t L2_Speed;
extern  uint16_t L4_Speed;
extern  uint16_t R1_Speed;
extern  uint16_t time_1,time_2,time_3,time_4,time_set_1,time_set_2,time_set_3,time_set_4;
uint8_t Wise_Flag;
uint8_t UP_Flag;
uint8_t Stable1, Stable2, Stable3,Stable4;
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
void lcd_all(void);
void lcd_clr(void);
void  delay(void);
void lcd_init(void);
void LCD_Display(void);


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
 // MX_TIM2_Init();
 // MX_TIM3_Init();
  /* USER CODE BEGIN 2 */
	  // HAL_TIM_PWM_Start(&htim2, TIM_CHANNEL_1);
//		 HAL_TIM_PWM_Start(&htim3, TIM_CHANNEL_3);
//		 HAL_TIM_PWM_Start(&htim3, TIM_CHANNEL_2);
//		 HAL_TIM_PWM_Start(&htim3, TIM_CHANNEL_1);
//		 HAL_TIM_PWM_Start(&htim3, TIM_CHANNEL_4);
		 HAL_TIM_PWM_Start(&htim1, TIM_CHANNEL_4);
		 
      //PID_init();
	   HAL_TIM_Base_Start_IT(&htim1);
		// system_init();
	   lcd_init();
		 LCD_Light(LCD_OFF);
		// __HAL_TIM_SET_COMPARE(&htim1,TIM_CHANNEL_4,9);
		 //HAL_GPIO_WritePin(GPIOE, LCD_KEY_Pin, GPIO_PIN_SET);
		 lcd_all();
	   HAL_Delay (1000);
    // lcd_clr();
     
      //__HAL_TIM_SET_COMPARE(&htim3,TIM_CHANNEL_3,1000/17);
  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
		//user_pwm_setvalue(500);
	
		// LCD_Display();
		  
		//HAL_GPIO_WritePin(PWM5_GPIO_Port, PWM5_Pin, GPIO_PIN_SET);
		 
    // HAL_Delay (10);		
		
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
  RCC_OscInitStruct.HSEPredivValue = RCC_HSE_PREDIV_DIV1;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
  RCC_OscInitStruct.PLL.PLLMUL = RCC_PLL_MUL4;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }
  /** Initializes the CPU, AHB and APB busses clocks 
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_1) != HAL_OK)
  {
    Error_Handler();
  }
}

/* USER CODE BEGIN 4 */

void user_pwm_setvalue(uint16_t value)

{

    TIM_OC_InitTypeDef sConfigOC;

  

    sConfigOC.OCMode = TIM_OCMODE_PWM1;

    sConfigOC.Pulse = value;

    sConfigOC.OCPolarity = TIM_OCPOLARITY_HIGH;

    sConfigOC.OCFastMode = TIM_OCFAST_DISABLE;

    HAL_TIM_PWM_ConfigChannel(&htim2, &sConfigOC, TIM_CHANNEL_1);

    HAL_TIM_PWM_Start(&htim2, TIM_CHANNEL_1);  

}


uint32_t next1,next2,next3,next4,first;
uint16_t L1_Rel,L2_Rel,L3_Rel,L4_Rel;
uint32_t time1_down,time2_down,time3_down,time4_down;
uint32_t time1_full,time2_full,time3_full,time4_full;
uint16_t speed1_tab[]= {0,0,0,0,0};
extern uint8_t  default1;
extern uint8_t  default2;
extern uint8_t  default3;
extern uint8_t  default4;
void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
{

	//²âËÙ
		if(GPIO_Pin ==FG5_Pin)
	{
		
		 rpm1_cnt++;
		if(rpm1_cnt>3)
		{
			uint32_t first = HAL_GetTick();
			if((first-next1)>0)
			L1_Rel=120000/(first-next1);
			if(Set_Flag==1||Set_Flag==0)
			{ 
				  //if((L1_Rel<2000)&&(L1_Rel>200))
				  if(Stable1)
					M1_Speed=L1_Rel;
					else
					{
						  if(L1_Rel>L1_Speed)
							{
								 if((L1_Rel-L1_Speed)<150)
					       M1_Speed=L1_Speed ;
								 else M1_Speed=L1_Rel;
							}
							else
							{
								if((L1_Speed-L1_Rel)<150)
					       M1_Speed=L1_Speed ;
								 else M1_Speed=L1_Rel;
								
							}
							
					}
			}
		 next1=first;
			rpm1_cnt=0;
		}
		
	}
			if(GPIO_Pin ==FG6_Pin)
	{

		 rpm2_cnt++;
		if(rpm2_cnt>3)
		{
		 uint32_t first = HAL_GetTick();
			L2_Rel=120000/(first-next2);
			if(Set_Flag==2)
			{
				
			
		 			if(Stable2)
					M1_Speed=L2_Rel;
					else
					{
						  if(L2_Rel>L2_Speed)
							{
								 if((L2_Rel-L2_Speed)<150)
					       M1_Speed=L2_Speed ;
								 else M1_Speed=L2_Rel;
							}
							else
							{
								if((L2_Speed-L2_Rel)<150)
					       M1_Speed=L2_Speed ;
								 else M1_Speed=L2_Rel;
								
							}
							
					}
				}
		 next2=first;
			rpm2_cnt=0;
		}
		
	}
	if(GPIO_Pin ==FG7_Pin)
	{
		 rpm3_cnt++;
		if(rpm3_cnt>3)
		{
		 uint32_t first = HAL_GetTick();
			L3_Rel=120000/(first-next3);
			if(Set_Flag==3)
		 		{
				
			
		 			if(Stable3)
					M1_Speed=L3_Rel;
					else
					{
						  if(L3_Rel>L3_Speed)
							{
								 if((L2_Rel-L3_Speed)<150)
					       M1_Speed=L3_Speed ;
								 else M1_Speed=L3_Rel;
							}
							else
							{
								if((L3_Speed-L3_Rel)<150)
					       M1_Speed=L3_Speed ;
								 else M1_Speed=L3_Rel;
								
							}
							
					}
				}
		 next3=first;
			rpm3_cnt=0;
		}
		
	}
			if(GPIO_Pin ==FG8_Pin)
	{
		 rpm4_cnt++;
		if(rpm4_cnt>3)
		{
		 uint32_t first = HAL_GetTick();
			L4_Rel=120000/(first-next4);
			if(Set_Flag==4)
		 			{
				
			
		 			if(Stable4)
					M1_Speed=L4_Rel;
					else
					{
						  if(L4_Rel>L4_Speed)
							{
								 if((L4_Rel-L4_Speed)<150)
					       M1_Speed=L4_Speed ;
								 else M1_Speed=L4_Rel;
							}
							else
							{
								if((L4_Speed-L4_Rel)<150)
					       M1_Speed=L4_Speed ;
								 else M1_Speed=L4_Rel;
								
							}
							
					}
				}
		 next4=first;
			rpm4_cnt=0;
		}
		
	}


	
	//ÓÒÐý×ª
        
				if(GPIO_Pin ==KEY2B_Pin)
				{
					Set_Cnt++;
					if(Set_Cnt>6)
					{	
						uint16_t first= HAL_GetTick();
						Set_Speed=120000/(first-next_cnt);
						next_cnt=first;
						Set_Cnt=0;
					}
					
					
					
					
					if(Set_Mode==1)
					{
							if(HAL_GPIO_ReadPin(KEY2A_GPIO_Port,KEY2A_Pin)==1)
							{
                  if(Wise_Flag==0)
									{
										if(Set_Speed>300)
											R1_Speed=R1_Speed+40;
										else
										  R1_Speed=R1_Speed+5;
										if(R1_Speed>1500) R1_Speed=1500;
										if(R1_Speed<200) R1_Speed=200;
									   
										switch(Set_Flag)
										{

											case 1: L1_Speed=R1_Speed;Stable1=Stable_Time;
											break ;
											case 2: L2_Speed=R1_Speed;Stable2=Stable_Time;
											break ;
											case 3: L3_Speed=R1_Speed;Stable3=Stable_Time;
											break ;
											case 4: L4_Speed=R1_Speed;Stable4=Stable_Time;
											break ;
											default:
											break;
										}
								 }
									
							}
							else
							{
                  if(Set_Speed>300)
										R1_Speed=R1_Speed-40;
									else
									  R1_Speed=R1_Speed-5;
									if(R1_Speed>1500) R1_Speed=00;
								//	if(R1_Speed<200) R1_Speed=000;
								  Wise_Flag=5;
									switch(Set_Flag)
									{

										case 1: L1_Speed=R1_Speed;Stable1=Stable_Time;
										break ;
										case 2: L2_Speed=R1_Speed;Stable2=Stable_Time;
										break ;
										case 3: L3_Speed=R1_Speed;Stable3=Stable_Time;
										break ;
										case 4: L4_Speed=R1_Speed;Stable4=Stable_Time;
										break ;
										default:
										break;
									}
									
							}
							
					}
					if(Set_Mode==2)
					{
							if(HAL_GPIO_ReadPin(KEY2A_GPIO_Port,KEY2A_Pin)==1)
							{
								   if(Wise_Flag==0)
									Set_Time_R++;
									if(Set_Time_R>59) Set_Time_R=0;
									time_set_3=Set_Time_R/10;
									time_set_4=Set_Time_R%10;
							}
							else
							{
									Set_Time_R--;
									if(Set_Time_R<0) Set_Time_R=59;
								   Wise_Flag=5;
									time_set_3=Set_Time_R/10;
									time_set_4=Set_Time_R%10;
							}
							
					}
					if(Set_Mode==3)
					{
							if(HAL_GPIO_ReadPin(KEY2A_GPIO_Port,KEY2A_Pin)==1)
							{
								  if(Wise_Flag==0)
									Set_Time_L++;
									if(Set_Time_L>60)
									{
										Time_Stutas=Time_min;
										Set_Time_L=0;
									}
									time_set_1=Set_Time_L/10;
									time_set_2=Set_Time_L%10;
								
								
								
							}
							else
							{
									Set_Time_L--;
							   	Wise_Flag=5;
									if(Set_Time_L<0) 
									{
										Set_Time_L=60;
									 Time_Stutas=Time_sec;
									}
									time_set_1=Set_Time_L/10;
									time_set_2=Set_Time_L%10;
							}
							
					}
					 if((Set_Mode==3)||(Set_Mode==2))
					 {
									switch(Set_Flag)
									{

										case 1: if(Time_Stutas==Time_min){ time1_down=Set_Time_L*3600+Set_Time_R*60;Time1_Stutas=Time_min;;time1_full= time1_down;} else{time1_down=Set_Time_L*60+ Set_Time_R;Time1_Stutas=Time_sec;time1_full= time1_down;}  default1=0;
										break ;
										case 2: if(Time_Stutas==Time_min){ time2_down=Set_Time_L*3600+Set_Time_R*60;Time2_Stutas=Time_min;;time2_full= time2_down;} else{time2_down=Set_Time_L*60+ Set_Time_R;Time2_Stutas=Time_sec;time2_full= time2_down;}  default2=0;
										break ;
										case 3: if(Time_Stutas==Time_min){ time3_down=Set_Time_L*3600+Set_Time_R*60;Time3_Stutas=Time_min;;time2_full= time2_down;} else{time3_down=Set_Time_L*60+ Set_Time_R;Time3_Stutas=Time_sec;time3_full= time3_down;}  default3=0;
										break ;
										case 4: if(Time_Stutas==Time_min){ time4_down=Set_Time_L*3600+Set_Time_R*60;Time4_Stutas=Time_min;;time2_full= time2_down;} else{time4_down=Set_Time_L*60+ Set_Time_R;Time4_Stutas=Time_sec;time4_full= time4_down;}  default4=0;
										break ;
										default:
										break;
									}
						}	
				}

					//×óÐý×ª
	if(GPIO_Pin == KEY1A_Pin)
	{
		
//		uint8_t S=HAL_GPIO_ReadPin(KEY1B_GPIO_Port,KEY1B_Pin);
//		switch(S)
//		{
//			case 0: if((Wise_Flag==0)&&(UP_Flag==0))
//							{
//								while(HAL_GPIO_ReadPin(KEY1B_GPIO_Port,KEY1B_Pin)==1&&HAL_GPIO_ReadPin(KEY1B_GPIO_Port,KEY1A_Pin)==1){
//								
//								Set_Flag++;
//								UP_Flag=8;
//								if(Set_Flag>4) Set_Flag=1;
//								Dis_Flag= Set_Flag;
//								}
//							}
//							break ;
//			 case 1:if((Wise_Flag==0)&&(UP_Flag==0))
//							{
//								while(HAL_GPIO_ReadPin(KEY1B_GPIO_Port,KEY1B_Pin)==1&&HAL_GPIO_ReadPin(KEY1B_GPIO_Port,KEY1A_Pin)==1)
//								{
//								Set_Flag--;
//								Wise_Flag=8;
//								if(Set_Flag<1) Set_Flag=4;
//								Dis_Flag= Set_Flag;
//								}
//							}
//							break ;	
//		}

				if(HAL_GPIO_ReadPin(KEY1A_GPIO_Port,KEY1B_Pin)==0)
				{
			     	if(Wise_Flag==0)
						{
							Set_Flag++;
							UP_Flag=10;
							
							if(Set_Flag>4) Set_Flag=1;
							Dis_Flag= Set_Flag;
						}
					 
				}
//				else
//				{
//              if(UP_Flag==0)
//							Set_Flag--;
//							Wise_Flag=10;
//							//if(Set_Flag<1) Set_Flag=4;
//							Dis_Flag= Set_Flag;
//						
//				}
				
				switch(Set_Flag)
						{

							case 1: if(Time1_Stutas==1) {time_set_1=time1_full/3600/10;time_set_2=time1_full/3600%10;time_set_3=time1_full%3600/60/10;time_set_4=time1_full%3600/60%10;Time_Stutas=1;Set_Time_R=time1_full%3600/60;Set_Time_L=time1_full/3600;} 
											else {time_set_1=time1_full/60/10;time_set_2=time1_full/60%10;time_set_3=time1_full%60/10;time_set_4=time1_full%60%10;Time_Stutas=0;Set_Time_R=time1_full%60;Set_Time_L=time1_full%3600/60;   }
											R1_Speed=L1_Speed;
							break ;
							case 2: if(Time2_Stutas==1) {time_set_1=time2_full/3600/10;time_set_2=time2_full/3600%10;time_set_3=time2_full%3600/60/10;time_set_4=time2_full%3600/60%10;Time_Stutas=1;Set_Time_R=time2_full%3600/60;Set_Time_L=time2_full/3600;} 
											else {time_set_1=time2_full/60/10;time_set_2=time2_full/60%10;time_set_3=time2_full%60/10;time_set_4=time2_full%60%10;Time_Stutas=0;Set_Time_R=time2_full%60;Set_Time_L=time2_full%3600/60;   }
											R1_Speed=L2_Speed;
							break ;
							case 3: if(Time3_Stutas==1) {time_set_1=time3_full/3600/10;time_set_2=time3_full/3600%10;time_set_3=time3_full%3600/60/10;time_set_4=time3_full%3600/60%10;Time_Stutas=1;Set_Time_R=time3_full%3600/60;Set_Time_L=time3_full/3600;} 
											else {time_set_1=time3_full/60/10;time_set_2=time3_full/60%10;time_set_3=time3_full%60/10;time_set_4=time3_full%60%10;Time_Stutas=0;Set_Time_R=time3_full%60;Set_Time_L=time3_full%3600/60;   }
											R1_Speed=L3_Speed;
							break ;
							case 4: if(Time4_Stutas==1) {time_set_1=time4_full/3600/10;time_set_2=time4_full/3600%10;time_set_3=time4_full%3600/60/10;time_set_4=time4_full%3600/60%10;Time_Stutas=1;Set_Time_R=time4_full%3600/60;Set_Time_L=time4_full/3600;} 
											else {time_set_1=time4_full/60/10;time_set_2=time4_full/60%10;time_set_3=time4_full%60/10;time_set_4=time4_full%60%10;Time_Stutas=0;Set_Time_R=time4_full%60;Set_Time_L=time4_full%3600/60;   }
											R1_Speed=L4_Speed;
							break ;
							default:
							break;
	          }
						if(Set_Mode)
				    Set_Mode=1;
				      
  }
				
	if(GPIO_Pin ==KEY1_Pin)
	{
		  HAL_Delay(20);
		 if(HAL_GPIO_ReadPin(KEY1_GPIO_Port,KEY1_Pin)==0)
		 {
			//System_Stutas =Sys_SET ;
			 cnt1=1;
		 }
	}
	
  if(GPIO_Pin ==KEY2_Pin)
	{
		  HAL_Delay(20);
		 if(HAL_GPIO_ReadPin(KEY1_GPIO_Port,KEY2_Pin)==0)
		 {
			 if(Set_Flag)
			 {
				 if(System_Stutas==Sys_ON )
				 System_Stutas =Sys_SET ;
				 if(System_Stutas==Sys_RUN )
					 System_Stutas =4 ;
					 
				 
				 
				 Set_Mode++;
				 if(Set_Mode>3)
				 Set_Mode=0;
				 //Dis_Flag=0;
		   }
			 cnt2=1;
		 }
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
void assert_failed(uint8_t *file, uint32_t line)
{ 
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     tex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
