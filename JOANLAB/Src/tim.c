/**
  ******************************************************************************
  * File Name          : TIM.c
  * Description        : This file provides code for the configuration
  *                      of the TIM instances.
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

/* Includes ------------------------------------------------------------------*/
#include "tim.h"

/* USER CODE BEGIN 0 */

//void LCD_Display(void);	
/* USER CODE END 0 */

TIM_HandleTypeDef htim1;
TIM_HandleTypeDef htim2;
TIM_HandleTypeDef htim3;

/* TIM1 init function */
void MX_TIM1_Init(void)
{
  TIM_ClockConfigTypeDef sClockSourceConfig = {0};
  TIM_MasterConfigTypeDef sMasterConfig = {0};
  TIM_OC_InitTypeDef sConfigOC = {0};
  TIM_BreakDeadTimeConfigTypeDef sBreakDeadTimeConfig = {0};

  htim1.Instance = TIM1;
  htim1.Init.Prescaler = 36-1;
  htim1.Init.CounterMode = TIM_COUNTERMODE_UP;
  htim1.Init.Period = 10-1;
  htim1.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
  htim1.Init.RepetitionCounter = 0;
  htim1.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;
  if (HAL_TIM_Base_Init(&htim1) != HAL_OK)
  {
    Error_Handler();
  }
  sClockSourceConfig.ClockSource = TIM_CLOCKSOURCE_INTERNAL;
  if (HAL_TIM_ConfigClockSource(&htim1, &sClockSourceConfig) != HAL_OK)
  {
    Error_Handler();
  }
  if (HAL_TIM_PWM_Init(&htim1) != HAL_OK)
  {
    Error_Handler();
  }
  sMasterConfig.MasterOutputTrigger = TIM_TRGO_RESET;
  sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
  if (HAL_TIMEx_MasterConfigSynchronization(&htim1, &sMasterConfig) != HAL_OK)
  {
    Error_Handler();
  }
  sConfigOC.OCMode = TIM_OCMODE_PWM1;
  sConfigOC.Pulse = 0;
  sConfigOC.OCPolarity = TIM_OCPOLARITY_HIGH;
  sConfigOC.OCFastMode = TIM_OCFAST_DISABLE;
  sConfigOC.OCIdleState = TIM_OCIDLESTATE_RESET;
  sConfigOC.OCNIdleState = TIM_OCNIDLESTATE_RESET;
  if (HAL_TIM_PWM_ConfigChannel(&htim1, &sConfigOC, TIM_CHANNEL_4) != HAL_OK)
  {
    Error_Handler();
  }
  sBreakDeadTimeConfig.OffStateRunMode = TIM_OSSR_DISABLE;
  sBreakDeadTimeConfig.OffStateIDLEMode = TIM_OSSI_DISABLE;
  sBreakDeadTimeConfig.LockLevel = TIM_LOCKLEVEL_OFF;
  sBreakDeadTimeConfig.DeadTime = 0;
  sBreakDeadTimeConfig.BreakState = TIM_BREAK_DISABLE;
  sBreakDeadTimeConfig.BreakPolarity = TIM_BREAKPOLARITY_HIGH;
  sBreakDeadTimeConfig.AutomaticOutput = TIM_AUTOMATICOUTPUT_DISABLE;
  if (HAL_TIMEx_ConfigBreakDeadTime(&htim1, &sBreakDeadTimeConfig) != HAL_OK)
  {
    Error_Handler();
  }
  HAL_TIM_MspPostInit(&htim1);

}
/* TIM2 init function */
void MX_TIM2_Init(void)
{
  TIM_ClockConfigTypeDef sClockSourceConfig = {0};
  TIM_MasterConfigTypeDef sMasterConfig = {0};
  TIM_OC_InitTypeDef sConfigOC = {0};

  htim2.Instance = TIM2;
  htim2.Init.Prescaler = 360-1;
  htim2.Init.CounterMode = TIM_COUNTERMODE_UP;
  htim2.Init.Period = 1000-1;
  htim2.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
  htim2.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_ENABLE;
  if (HAL_TIM_Base_Init(&htim2) != HAL_OK)
  {
    Error_Handler();
  }
  sClockSourceConfig.ClockSource = TIM_CLOCKSOURCE_INTERNAL;
  if (HAL_TIM_ConfigClockSource(&htim2, &sClockSourceConfig) != HAL_OK)
  {
    Error_Handler();
  }
  if (HAL_TIM_PWM_Init(&htim2) != HAL_OK)
  {
    Error_Handler();
  }
  sMasterConfig.MasterOutputTrigger = TIM_TRGO_RESET;
  sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
  if (HAL_TIMEx_MasterConfigSynchronization(&htim2, &sMasterConfig) != HAL_OK)
  {
    Error_Handler();
  }
  sConfigOC.OCMode = TIM_OCMODE_PWM1;
  sConfigOC.Pulse = 0;
  sConfigOC.OCPolarity = TIM_OCPOLARITY_HIGH;
  sConfigOC.OCFastMode = TIM_OCFAST_DISABLE;
  if (HAL_TIM_PWM_ConfigChannel(&htim2, &sConfigOC, TIM_CHANNEL_1) != HAL_OK)
  {
    Error_Handler();
  }
  HAL_TIM_MspPostInit(&htim2);

}
/* TIM3 init function */
void MX_TIM3_Init(void)
{
  TIM_ClockConfigTypeDef sClockSourceConfig = {0};
  TIM_MasterConfigTypeDef sMasterConfig = {0};
  TIM_OC_InitTypeDef sConfigOC = {0};

  htim3.Instance = TIM3;
  htim3.Init.Prescaler = 8;
  htim3.Init.CounterMode = TIM_COUNTERMODE_UP;
  htim3.Init.Period = 200-1;
  htim3.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
  htim3.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;
  if (HAL_TIM_Base_Init(&htim3) != HAL_OK)
  {
    Error_Handler();
  }
  sClockSourceConfig.ClockSource = TIM_CLOCKSOURCE_INTERNAL;
  if (HAL_TIM_ConfigClockSource(&htim3, &sClockSourceConfig) != HAL_OK)
  {
    Error_Handler();
  }
  if (HAL_TIM_PWM_Init(&htim3) != HAL_OK)
  {
    Error_Handler();
  }
  sMasterConfig.MasterOutputTrigger = TIM_TRGO_RESET;
  sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
  if (HAL_TIMEx_MasterConfigSynchronization(&htim3, &sMasterConfig) != HAL_OK)
  {
    Error_Handler();
  }
  sConfigOC.OCMode = TIM_OCMODE_PWM1;
  sConfigOC.Pulse = 0;
  sConfigOC.OCPolarity = TIM_OCPOLARITY_HIGH;
  sConfigOC.OCFastMode = TIM_OCFAST_DISABLE;
  if (HAL_TIM_PWM_ConfigChannel(&htim3, &sConfigOC, TIM_CHANNEL_1) != HAL_OK)
  {
    Error_Handler();
  }
  if (HAL_TIM_PWM_ConfigChannel(&htim3, &sConfigOC, TIM_CHANNEL_2) != HAL_OK)
  {
    Error_Handler();
  }
  if (HAL_TIM_PWM_ConfigChannel(&htim3, &sConfigOC, TIM_CHANNEL_3) != HAL_OK)
  {
    Error_Handler();
  }
  if (HAL_TIM_PWM_ConfigChannel(&htim3, &sConfigOC, TIM_CHANNEL_4) != HAL_OK)
  {
    Error_Handler();
  }
  HAL_TIM_MspPostInit(&htim3);

}

void HAL_TIM_Base_MspInit(TIM_HandleTypeDef* tim_baseHandle)
{

  if(tim_baseHandle->Instance==TIM1)
  {
  /* USER CODE BEGIN TIM1_MspInit 0 */

  /* USER CODE END TIM1_MspInit 0 */
    /* TIM1 clock enable */
    __HAL_RCC_TIM1_CLK_ENABLE();

    /* TIM1 interrupt Init */
    HAL_NVIC_SetPriority(TIM1_UP_IRQn, 0, 0);
    HAL_NVIC_EnableIRQ(TIM1_UP_IRQn);
  /* USER CODE BEGIN TIM1_MspInit 1 */

  /* USER CODE END TIM1_MspInit 1 */
  }
  else if(tim_baseHandle->Instance==TIM2)
  {
  /* USER CODE BEGIN TIM2_MspInit 0 */

  /* USER CODE END TIM2_MspInit 0 */
    /* TIM2 clock enable */
    __HAL_RCC_TIM2_CLK_ENABLE();

    /* TIM2 interrupt Init */
    HAL_NVIC_SetPriority(TIM2_IRQn, 0, 0);
    HAL_NVIC_EnableIRQ(TIM2_IRQn);
  /* USER CODE BEGIN TIM2_MspInit 1 */

  /* USER CODE END TIM2_MspInit 1 */
  }
  else if(tim_baseHandle->Instance==TIM3)
  {
  /* USER CODE BEGIN TIM3_MspInit 0 */

  /* USER CODE END TIM3_MspInit 0 */
    /* TIM3 clock enable */
    __HAL_RCC_TIM3_CLK_ENABLE();

    /* TIM3 interrupt Init */
    HAL_NVIC_SetPriority(TIM3_IRQn, 1, 0);
    HAL_NVIC_EnableIRQ(TIM3_IRQn);
  /* USER CODE BEGIN TIM3_MspInit 1 */

  /* USER CODE END TIM3_MspInit 1 */
  }
}
void HAL_TIM_MspPostInit(TIM_HandleTypeDef* timHandle)
{

  GPIO_InitTypeDef GPIO_InitStruct = {0};
  if(timHandle->Instance==TIM1)
  {
  /* USER CODE BEGIN TIM1_MspPostInit 0 */

  /* USER CODE END TIM1_MspPostInit 0 */
    __HAL_RCC_GPIOE_CLK_ENABLE();
    /**TIM1 GPIO Configuration    
    PE14     ------> TIM1_CH4 
    */
    GPIO_InitStruct.Pin = GPIO_PIN_14;
    GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
    HAL_GPIO_Init(GPIOE, &GPIO_InitStruct);

    __HAL_AFIO_REMAP_TIM1_ENABLE();

  /* USER CODE BEGIN TIM1_MspPostInit 1 */

  /* USER CODE END TIM1_MspPostInit 1 */
  }
  else if(timHandle->Instance==TIM2)
  {
  /* USER CODE BEGIN TIM2_MspPostInit 0 */

  /* USER CODE END TIM2_MspPostInit 0 */
  
    __HAL_RCC_GPIOA_CLK_ENABLE();
    /**TIM2 GPIO Configuration    
    PA0-WKUP     ------> TIM2_CH1 
    */
    GPIO_InitStruct.Pin = GPIO_PIN_0;
    GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
    HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /* USER CODE BEGIN TIM2_MspPostInit 1 */

  /* USER CODE END TIM2_MspPostInit 1 */
  }
  else if(timHandle->Instance==TIM3)
  {
  /* USER CODE BEGIN TIM3_MspPostInit 0 */

  /* USER CODE END TIM3_MspPostInit 0 */
  
    __HAL_RCC_GPIOA_CLK_ENABLE();
    __HAL_RCC_GPIOB_CLK_ENABLE();
    /**TIM3 GPIO Configuration    
    PA6     ------> TIM3_CH1
    PA7     ------> TIM3_CH2
    PB0     ------> TIM3_CH3
    PB1     ------> TIM3_CH4 
    */
    GPIO_InitStruct.Pin = GPIO_PIN_6|GPIO_PIN_7;
    GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
    HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

    GPIO_InitStruct.Pin = GPIO_PIN_0;
    GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
    HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

    GPIO_InitStruct.Pin = GPIO_PIN_1;
    GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
    HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

  /* USER CODE BEGIN TIM3_MspPostInit 1 */

  /* USER CODE END TIM3_MspPostInit 1 */
  }

}

void HAL_TIM_Base_MspDeInit(TIM_HandleTypeDef* tim_baseHandle)
{

  if(tim_baseHandle->Instance==TIM1)
  {
  /* USER CODE BEGIN TIM1_MspDeInit 0 */

  /* USER CODE END TIM1_MspDeInit 0 */
    /* Peripheral clock disable */
    __HAL_RCC_TIM1_CLK_DISABLE();

    /* TIM1 interrupt Deinit */
    HAL_NVIC_DisableIRQ(TIM1_UP_IRQn);
  /* USER CODE BEGIN TIM1_MspDeInit 1 */

  /* USER CODE END TIM1_MspDeInit 1 */
  }
  else if(tim_baseHandle->Instance==TIM2)
  {
  /* USER CODE BEGIN TIM2_MspDeInit 0 */

  /* USER CODE END TIM2_MspDeInit 0 */
    /* Peripheral clock disable */
    __HAL_RCC_TIM2_CLK_DISABLE();

    /* TIM2 interrupt Deinit */
    HAL_NVIC_DisableIRQ(TIM2_IRQn);
  /* USER CODE BEGIN TIM2_MspDeInit 1 */

  /* USER CODE END TIM2_MspDeInit 1 */
  }
  else if(tim_baseHandle->Instance==TIM3)
  {
  /* USER CODE BEGIN TIM3_MspDeInit 0 */

  /* USER CODE END TIM3_MspDeInit 0 */
    /* Peripheral clock disable */
    __HAL_RCC_TIM3_CLK_DISABLE();

    /* TIM3 interrupt Deinit */
    HAL_NVIC_DisableIRQ(TIM3_IRQn);
  /* USER CODE BEGIN TIM3_MspDeInit 1 */

  /* USER CODE END TIM3_MspDeInit 1 */
  }
} 

/* USER CODE BEGIN 1 */
uint16_t count;
uint16_t L1_Speed;
uint16_t L3_Speed;
uint16_t L2_Speed;
uint16_t L4_Speed;
uint16_t M1_Speed;
uint16_t M2_Time;
uint16_t R1_Speed;
uint16_t half_sec;
uint16_t Start_Time;
uint16_t time_1,time_2,time_3,time_4,time_set_1,time_set_2,time_set_3,time_set_4;
extern  uint16_t cnt1,cnt2;
extern uint16_t System_Stutas;
uint16_t at1=0,at2=0;
extern int Dis_Flag;
extern int Set_Flag;
extern uint16_t rpm1_cnt;
extern uint16_t rpm2_cnt;
extern uint16_t rpm3_cnt;
extern uint16_t rpm4_cnt;
extern int sumError1;
extern int sumError2;
extern int sumError3;
extern int sumError4;
extern uint8_t Set_Mode;
extern uint32_t time1_down,time2_down,time3_down,time4_down;
extern uint16_t time_1,time_2,time_3,time_4,time_set_1,time_set_2,time_set_3,time_set_4;
extern uint8_t Time_Stutas;
extern uint8_t Time1_Stutas;
extern uint8_t Time2_Stutas;
extern uint8_t Time3_Stutas;
extern uint8_t Time4_Stutas;
extern uint16_t L1_Rel,L2_Rel,L3_Rel,L4_Rel;
extern 	uint32_t next1,next2,next3,next4;
extern uint16_t Set_Speed1;
extern uint16_t Set_Speed2;
extern uint16_t Set_Speed3;
extern uint16_t Set_Speed4;
uint32_t Speed0_Flag,Speed1_Flag,Speed2_Flag,Speed3_Flag,Speed4_Flag;
extern uint32_t time1_full,time2_full,time3_full,time4_full;
extern  uint8_t Wise_Flag;
extern  uint8_t UP_Flag;
extern uint32_t next_cnt;
extern uint16_t Set_Speed;
extern uint8_t  default1;
extern uint8_t  default2;
extern uint8_t  default3;
extern uint8_t  default4;
extern uint8_t Stable1, Stable2, Stable3,Stable4;


void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim){

    

//    if (htim->Instance == TIM1)
//		{
//      count++;
//      
//					  switch(Set_Flag)
//						{
//							case 0: if(Time1_Stutas==1) {time_1=time1_down/3600/10;time_2=time1_down/3600%10;time_3=time1_down%3600/60/10;time_4=time1_down%3600/60%10;Time_Stutas=1;} 
//											else {time_1=time1_down/60/10;time_2=time1_down/60%10;time_3=time1_down%60/10;time_4=time1_down%60%10;Time_Stutas=0;   }
//							break ;
//          
//							case 1: if(Time1_Stutas==1) {time_1=time1_down/3600/10;time_2=time1_down/3600%10;time_3=time1_down%3600/60/10;time_4=time1_down%3600/60%10;Time_Stutas=1;} 
//											else {time_1=time1_down/60/10;time_2=time1_down/60%10;time_3=time1_down%60/10;time_4=time1_down%60%10;Time_Stutas=0;   }
//							break ;
//							case 2: if(Time2_Stutas==1) {time_1=time2_down/3600/10;time_2=time2_down/3600%10;time_3=time2_down%3600/60/10;time_4=time2_down%3600/60%10;Time_Stutas=1;} 
//											else {time_1=time2_down/60/10;time_2=time2_down/60%10;time_3=time2_down%60/10;time_4=time2_down%60%10;Time_Stutas=0;   }
//							break ;
//							case 3: if(Time3_Stutas==1) {time_1=time3_down/3600/10;time_2=time3_down/3600%10;time_3=time3_down%3600/60/10;time_4=time3_down%3600/60%10;Time_Stutas=1;} 
//											else {time_1=time3_down/60/10;time_2=time3_down/60%10;time_3=time3_down%60/10;time_4=time3_down%60%10;Time_Stutas=0;   }
//							break ;
//							case 4: if(Time4_Stutas==1) {time_1=time4_down/3600/10;time_2=time4_down/3600%10;time_3=time4_down%3600/60/10;time_4=time4_down%3600/60%10;Time_Stutas=1;} 
//											else {time_1=time4_down/60/10;time_2=time4_down/60%10;time_3=time4_down%60/10;time_4=time4_down%60%10;Time_Stutas=0;   }
//							break ;
//							default:
//							break;
//	          }

//						

//			if( count%10==0)
//			{
//				
//				PWM_Set();
//				if(Wise_Flag)
//				Wise_Flag--;
//				if(UP_Flag)
//				UP_Flag--;
//			}
//			if(count>49)
//			{
//				//速度0
//				uint32_t test0;
//				test0=next_cnt;
//				if(Speed0_Flag==test0) 
//				{
//						Set_Speed =0;

//				}
//				Speed0_Flag=test0;
//				
//				
//				uint32_t test1;
//				test1=next1;
//				if(Speed1_Flag==test1) 
//				{
//						L1_Rel =0;
//					if(Set_Flag<2)
//						M1_Speed=L1_Rel;
//				}
//				Speed1_Flag=test1;
//				
//				
//				
//				
//				uint32_t test2;
//				test2=next2;
//				if(Speed2_Flag==test2) 
//				{
//						L2_Rel =0;
//					  if(Set_Flag==2)
//						M1_Speed=L2_Rel;
//				}
//				Speed2_Flag=test2;
//				
//				
//				
//				uint32_t test3;
//				test3=next3;
//				if(Speed3_Flag==test3) 
//				{
//						L3_Rel =0;
//					  if(Set_Flag==3)
//						M1_Speed=L3_Rel;
//				}
//				Speed3_Flag=test3;	
//				
//				uint32_t test4;
//				test4=next4;
//				if(Speed4_Flag==test4) 
//				{
//						L4_Rel =0;
//					  if(Set_Flag==4)
//						M1_Speed=L4_Rel;
//				}
//				Speed4_Flag=test4;
//				
//				
//				
//				
//				
//				if(Start_Time)
//		    Start_Time--;
//			  half_sec++;
//				if(Stable1) Stable1--;
//				if(Stable2) Stable2--;
//				if(Stable3) Stable3--;
//				if(Stable4) Stable4--;
//				
//				
//				
//				
//				
//				
//				
//				
//				
//				if(half_sec%2)
//				{
//					if((System_Stutas==3)||(System_Stutas==4))
//					{
//							if(time1_down) time1_down--;
//							if(time2_down) time2_down--;
//							if(time3_down) time3_down--;
//							if(time4_down) time4_down--;
//					}

//				}
//				
//				
//				
//			 if((System_Stutas ==2)&&(Set_Mode))
//			 {
//				 if(half_sec%2) Dis_Flag=0;
//				 else Dis_Flag=Set_Flag;
//					 
//				
//		   }

//				if(cnt1==1)
//				{
//					if(HAL_GPIO_ReadPin (KEY1_GPIO_Port,KEY1_Pin)==0)
//					at1++;
//          if(HAL_GPIO_ReadPin (KEY1_GPIO_Port,KEY1_Pin)==1)
//					{
//						cnt1=0;at1=0;
//					}
//					if(at1>4)//key长按
//					{
//						
//					  switch(Set_Flag)
//						{
//							case 0:L2_Speed=L1_Speed;L3_Speed=L1_Speed;L4_Speed=L1_Speed;Set_Speed2=Set_Speed1;Set_Speed3=Set_Speed1;Set_Speed4=Set_Speed1;
//										 time2_down=time1_down;time3_down=time1_down;time4_down=time1_down;time2_full=time1_full;time3_full=time1_full;time4_full=time1_full;
//							       Time2_Stutas=Time1_Stutas;Time3_Stutas=Time1_Stutas;Time4_Stutas=Time1_Stutas;if(default1==0) {default2=0;default3=0;default4=0;}
//																																																		else{default2=1;default3=1;default4=1;}
//							break ;
//							case 1:L2_Speed=L1_Speed;L3_Speed=L1_Speed;L4_Speed=L1_Speed;Set_Speed2=Set_Speed1;Set_Speed3=Set_Speed1;Set_Speed4=Set_Speed1;
//										 time2_down=time1_down;time3_down=time1_down;time4_down=time1_down;time2_full=time1_full;time3_full=time1_full;time4_full=time1_full;
//										 Time2_Stutas=Time1_Stutas;Time3_Stutas=Time1_Stutas;Time4_Stutas=Time1_Stutas;if(default1==0) {default2=0;default3=0;default4=0;}
//																																																		else{default2=1;default3=1;default4=1;}
//							break ;
//							case 2:L1_Speed=L2_Speed;L3_Speed=L2_Speed;L4_Speed=L2_Speed;Set_Speed1=Set_Speed2;Set_Speed3=Set_Speed2;Set_Speed4=Set_Speed2;
//										 time1_down=time2_down;time3_down=time2_down;time4_down=time2_down;time1_full=time2_full;time3_full=time2_full;time4_full=time2_full;
//									   Time1_Stutas=Time2_Stutas;Time3_Stutas=Time2_Stutas;Time4_Stutas=Time2_Stutas;if(default2==0) {default1=0;default3=0;default4=0;}
//																																																		else{default1=1;default3=1;default4=1;}
//							break ;
//							case 3:L2_Speed=L3_Speed;L1_Speed=L3_Speed;L4_Speed=L3_Speed;Set_Speed2=Set_Speed3;Set_Speed1=Set_Speed3;Set_Speed4=Set_Speed3;
//										 time2_down=time3_down;time1_down=time3_down;time4_down=time3_down;time2_full=time3_full;time1_full=time3_full;time4_full=time3_full;
//										 Time2_Stutas=Time3_Stutas;Time1_Stutas=Time3_Stutas;Time4_Stutas=Time3_Stutas;if(default3==0) {default2=0;default1=0;default4=0;}
//																																																		else{default2=1;default1=1;default4=1;}
//							break ;
//							case 4:L2_Speed=L4_Speed;L3_Speed=L4_Speed;L1_Speed=L4_Speed;Set_Speed2=Set_Speed4;Set_Speed3=Set_Speed4;Set_Speed1=Set_Speed4;
//										 time2_down=time4_down;time3_down=time4_down;time1_down=time4_down;time2_full=time4_full;time3_full=time4_full;time1_full=time4_full;
//							       Time2_Stutas=Time4_Stutas;Time3_Stutas=Time4_Stutas;Time1_Stutas=Time4_Stutas;if(default4==0) {default2=0;default3=0;default1=0;}
//																																																		else{default2=1;default3=1;default1=1;}
//							break ;
//							
//							
//						}
//						
//		        //default1=0;default2=0;default3=0;default4=0;
//						Stable1=Stable_Time;Stable2=Stable_Time;Stable3=Stable_Time;Stable4=Stable_Time;
//					}

//				}
//				
//				
//				if(cnt2==1)
//				{
//					if(HAL_GPIO_ReadPin (KEY2_GPIO_Port,KEY2_Pin)==0)
//					at2++;
//          if(HAL_GPIO_ReadPin (KEY2_GPIO_Port,KEY2_Pin)==1)
//					{
//						cnt2=0;at2=0;
//					}
//					if(at2>4)//key2长按
//					{
//						if((L2_Rel)||(L1_Rel)||(L3_Rel)||(L4_Rel))
//						{
//							   system_init();
//								//time1_down=000;
//								 __HAL_TIM_SET_COMPARE(&htim3,TIM_CHANNEL_3,0);
//								//time2_down=000;
//								 __HAL_TIM_SET_COMPARE(&htim3,TIM_CHANNEL_1,0);
//								//time3_down=000;
//								 __HAL_TIM_SET_COMPARE(&htim3,TIM_CHANNEL_2,0);
//								//time4_down=000;
//								 __HAL_TIM_SET_COMPARE(&htim3,TIM_CHANNEL_4,0);
//							cnt2=0;
//							at2=0;
//							return ;
//						}
//						else
//						{
//						
//						System_Stutas =3;
//							Stable1=Stable_Time;Stable2=Stable_Time;Stable3=Stable_Time;Stable4=Stable_Time;
//						Set_Mode=0;
//						
//						 if((L1_Rel<100)&&(L1_Speed ))
//						 {
//							 Start_Time=1;//
//							 sumError1=0xa000;
//							 
//						 }
//						  if((L2_Rel<100)&&(L2_Speed ))
//						 {
//							 Start_Time=1;
//							 sumError2=0xa000;
//							 
//						 }
//						 if((L3_Rel<100)&&(L3_Speed ))
//						 {
//							 Start_Time=1;
//							 sumError3=0xa000;
//							 
//						 }
//						 if((L4_Rel<100)&&(L4_Speed ))
//						 {
//							 Start_Time=1;
//							 sumError4=0xa000;
//							 
//						 }

//             cnt2=0;
//						 at2=0;
//						 }

//					 }    
//					}
//				count=0;
//					if(half_sec>999) half_sec=0;
//				}
//		
//			}

   }


/* USER CODE END 1 */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
