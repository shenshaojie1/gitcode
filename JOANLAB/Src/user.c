#include "user.h"
#include "ht1623.h"
#include "tim.h"
uint8_t Sys_Mode;//系统运行模式
extern uint8_t Time_Status;
extern uint16_t Rpm,Time_SUM,Key_Count;
extern uint16_t cur,KEY_Flag;
uint8_t Point_Flag;
uint16_t BEEP_Count,BEEP_Close;
void BEEP(void)
{
	  if(BEEP_Close==0)
		{
	   HAL_GPIO_WritePin(BEEP_GPIO_Port, BEEP_Pin, GPIO_PIN_SET);
	   
     BEEP_Count=680;
		}
	    
}

void Sys_Init(void)
{
	HAL_GPIO_WritePin(BEEP_GPIO_Port, BEEP_Pin, GPIO_PIN_RESET);
	HAL_TIM_PWM_Stop(&htim1, TIM_CHANNEL_1);
	Sys_Mode=Sys_Point;
	Point_Flag=1;
	Time_Status =0;
	KEY_Flag=0;
	Key_Count=0;
	Time_SUM=30;
	Rpm=3000;
	cur=400;
	BEEP_Close=0;
	lcd_all();
	HAL_Delay (10000);
	BEEP();
	lcd_clr();
	lcd_init();
}
