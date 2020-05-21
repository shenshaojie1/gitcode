#include "key.h"
#include "user.h"

extern uint16_t Rpm,Time_SUM;
uint16_t Scan_Status,KEY_Flag,RUN_Status;
uint16_t cur,Set_Flag,Set_Count,Key_Count,Key1_Count;
extern uint8_t Set_Flag1,Set_Flag2;
extern uint8_t Time_Status;
extern uint8_t Sys_Mode;
extern uint8_t Point_Flag;
uint16_t MAX_RPM;
uint8_t KEY1_Pin_ON;
extern uint16_t PWM;
extern uint16_t BEEP_Count,BEEP_Close;


void stop(void);
/*******************************************************************************
* 名   称: Key_Scan(GPIO_TypeDef* GPIOx,uint16_t GPIO_Pin)
* 功   能: 按键扫描
* 参   数: PIO_TypeDef* GPIOx,uint16_t GPIO_Pin
* 返 回值: KEY_ON/KEY_OFF
*
* 修改历史:
* 改动原因：
*   ----------------------------------------------------
*******************************************************************************/
uint8_t Key_Scan(GPIO_TypeDef* GPIOx,uint16_t GPIO_Pin)
{                        


        if(HAL_GPIO_ReadPin (GPIOx,GPIO_Pin) == 0 )  
        {
					      
                BEEP();
					      BEEP_Close=200;
								if(KEY_Flag==0) 
								{
									KEY_Flag=1;
									return KEY_ON;
								}
					       uint32_t cur_time = HAL_GetTick();
	               static uint32_t start_time = 0;
                 if(start_time == 0)
								 start_time = cur_time;
								 
								 
									 if(cur_time - start_time < cur)
									 return KEY_OFF;

								 
                 if(HAL_GPIO_ReadPin (GPIOx,GPIO_Pin) == 0)   
								 {
		                 
					           Scan_Status++;
									   if(Scan_Status>3)
											 cur=8;
										 start_time = cur_time;		
										 return         KEY_ON; 
								 	
								 }	

        }
        else
				{
			  
					if((HAL_GPIO_ReadPin (GPIOB,KEY2_Pin) ==1)&&(HAL_GPIO_ReadPin (GPIOB,KEY3_Pin) ==1 ) )
					{
						   if(HAL_GPIO_ReadPin (GPIOB,KEY1_Pin) ==1)
							 {
								 KEY1_Pin_ON=0;
							 }
							Scan_Status=0;
							cur=400;
						  return         KEY_OFF;
					}			
				}
				return         KEY_OFF;
}

/*******************************************************************************
* 名   称: Key_Handle(void)
* 功   能: 按键处理
* 参   数: PIO_TypeDef* GPIOx,uint16_t GPIO_Pin
* 返 回值: 
*
* 修改历史:
* 改动原因：
*   ----------------------------------------------------
*******************************************************************************/

void Key_Handle(void)
{

				if(( Key_Scan(GPIOB,KEY1_Pin) == KEY_ON))
				{
					   // BEEP();
              Set_Flag++;	
					    
					    Set_Flag1=0;
					    Set_Flag2=0;
					    Set_Count=10;
					    if(Set_Flag>2)
						  Set_Flag=1;
							KEY1_Pin_ON++;
							
							if(KEY1_Pin_ON>3)
							{
								if(Sys_Mode==Sys_Point)
								{
									Sys_Mode=Sys_Cont;
									if(Rpm>1500)
										Rpm=1500;
									Point_Flag=0;
								}
								else
								{
									Sys_Mode=Sys_Point;
									Point_Flag=1;
								}
								KEY1_Pin_ON=0;
							
							}
							Key1_Count=5000;
							
			  }

				
				
			  if ( (Key_Scan(GPIOB,KEY2_Pin) == KEY_ON))//加键
				{  
					  if(Set_Flag==1)
						{
							if(Sys_Mode==Sys_Point)//点动模式
								MAX_RPM=3000;
							else if(Sys_Mode==Sys_Cont)//连续模式
								MAX_RPM=1500;
							Rpm=Rpm+10;
							if(Rpm>MAX_RPM)
								Rpm=MAX_RPM;
							
							
						}
						else if(Set_Flag==2)
						{
							if(Time_Status ==0)
						   Time_SUM +=1;
							else
							 Time_SUM +=60;
							if(Time_SUM>5940)
							 Time_SUM=5940;
						}
						
						Set_Count=10;//按键设置计时
						Key_Count=3;//按键加减计时
						
						//PWM=Rpm/30;
				}
				
				
				if ( (Key_Scan(GPIOB,KEY3_Pin) == KEY_ON))//减键
				{  
					
					
					 	if(Set_Flag==1)
						{
							Rpm=Rpm-10;
							if(Rpm<200)
								Rpm=200;
						}
						else if(Set_Flag==2)
						{
							if(Time_Status ==0)
						   Time_SUM -=1;
							else
							 Time_SUM -=60;
							if(Time_SUM<1)
							 Time_SUM=1;
						}
						Set_Count=10;//按键设置计时
						Key_Count=3;//按键加减计时
						//PWM=Rpm/30;
						
						
				}
				if ( (Key_Scan(GPIOB,KEY_T_Pin) == KEY_ON))
				{  
					 	if(Sys_Mode==Sys_Point)
						{
							RUN_Status =Sys_RUN;
							
						}
							
							
					
					
				}
				if ( (Key_Scan(GPIOB,KEY4_Pin) == KEY_ON))
				{  
					 	if(RUN_Status ==Sys_RUN)
						{
							
							stop();
						}
						else
						{
							if(Sys_Mode==Sys_Cont)
							RUN_Status =Sys_RUN;
						}
							
							
					
				}
				//BEEP();
}

void stop(void)
{
	RUN_Status =Sys_STOP;
//	Time_SUM=30;
//	if(Sys_Mode==Sys_Point)//点动模式
//	Rpm=3000;
//	else if(Sys_Mode==Sys_Cont)//连续模式
//	Rpm=1500;
}
