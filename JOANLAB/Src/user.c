#include "user.h"
#include "tim.h"
uint16_t System_Stutas;
uint8_t Time_Stutas;
uint8_t Time1_Stutas;
uint8_t Time2_Stutas;
uint8_t Time3_Stutas;
uint8_t Time4_Stutas;
uint16_t Init_Speed;
uint16_t Set_Speed1;
uint16_t Set_Speed2;
uint16_t Set_Speed3;
uint16_t Set_Speed4;
extern  uint8_t Set_Time_R;
extern  uint8_t Set_Time_L;
extern  uint16_t L1_Speed;
extern  uint16_t L3_Speed;
extern  uint16_t L2_Speed;
extern  uint16_t L4_Speed;
extern  uint16_t M1_Speed;
extern  uint16_t M2_Time;
extern  uint16_t R1_Speed;
extern  uint8_t Set_Flag;
extern  uint8_t Dis_Flag;
extern  uint16_t Start_Time;
extern  uint16_t time_1,time_2,time_3,time_4,time_set_1,time_set_2,time_set_3,time_set_4;
extern uint32_t time1_down,time2_down,time3_down,time4_down;
extern uint32_t time1_full,time2_full,time3_full,time4_full;
float PID_realize(float speed);
unsigned int PID1(void);
unsigned int PID2(void);
unsigned int PID3(void);
unsigned int PID4(void);
extern uint16_t L1_Rel,L2_Rel,L3_Rel,L4_Rel;
uint8_t  default1;
uint8_t  default2;
uint8_t  default3;
uint8_t  default4;
extern   uint8_t Set_Mode;
extern uint8_t Stable1, Stable2, Stable3,Stable4;

 void system_init(void)
 {
	    HAL_GPIO_WritePin(MO5_GPIO_Port, MO5_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(MO6_GPIO_Port, MO6_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(MO7_GPIO_Port, MO7_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(MO8_GPIO_Port, MO8_Pin, GPIO_PIN_SET);
	    System_Stutas=Sys_ON;
	    Time_Stutas=Time_sec ;
			Time1_Stutas=Time_sec ;
		  Time2_Stutas=Time_sec ;
			Time3_Stutas=Time_sec ;
			Time4_Stutas=Time_sec ;
			 Stable1=0;
			 Stable2=0;
			 Stable3=0;
			 Stable4=0;
	    L1_Speed=200;
		  L3_Speed=200;
		  L2_Speed=200;
		  L4_Speed=200;
		  M1_Speed=0;
		  R1_Speed=200;
	    Set_Flag=0;
	    Dis_Flag =0;
	    Set_Time_R=0;
			Set_Time_L=0;
	    time1_down=000;
	    time1_full=000;
	 	  time2_down=000;
	    time2_full=000;
	 	  time3_down=000;
	    time3_full=000;
	 	  time4_down=000;
	    time4_full=000;
		  default1=1;
			default2=1;
			default3=1;
		  default4=1;
			Set_Mode=0;
	    //Init_Speed=40;
	   time_set_1=time1_full/60/10;
		 time_set_2=time1_full/60%10;
		 time_set_3=time1_full%60/10;
		 time_set_4=time1_full%60%10;
		 Time_Stutas=0;
		 Set_Time_R=time1_full%60;
		 Set_Time_L=time1_full%3600/60;
	 
 }
  void PWM_Set(void)
	{
		 if((System_Stutas==Sys_RUN)||(System_Stutas==4))
		 {
//		  if(L1_Speed<R1_Speed) Init_Speed++;
// 		  else if(L1_Speed>R1_Speed) Init_Speed--;
			// L2_Speed=PID_realize(R1_Speed);
			  
			 if(Start_Time)
			 {
				  //L2_Speed=400;
				 if(L1_Speed)
				 __HAL_TIM_SET_COMPARE(&htim3,TIM_CHANNEL_3,800/17);
				 if(L3_Speed )
				 __HAL_TIM_SET_COMPARE(&htim3,TIM_CHANNEL_1,800/17);
				 if(L4_Speed )
				 __HAL_TIM_SET_COMPARE(&htim3,TIM_CHANNEL_2,800/17);
				 if(L2_Speed )
				 __HAL_TIM_SET_COMPARE(&htim3,TIM_CHANNEL_4,800/17);
			 }
			 else
			 {
				 //   PID();
							 PID1();
							 PID2();
							 PID3();
							 PID4();
             if((time3_down)||(default3))
						 __HAL_TIM_SET_COMPARE(&htim3,TIM_CHANNEL_1,Set_Speed3/17);
						 else
						 __HAL_TIM_SET_COMPARE(&htim3,TIM_CHANNEL_1,0);
						 
						 if((time1_down)||(default1))
						 __HAL_TIM_SET_COMPARE(&htim3,TIM_CHANNEL_3,Set_Speed1/17);
						 else
						 __HAL_TIM_SET_COMPARE(&htim3,TIM_CHANNEL_3,0);
						 
				      if((time4_down)||(default4))
						 __HAL_TIM_SET_COMPARE(&htim3,TIM_CHANNEL_2,Set_Speed4/17);
							else
						 __HAL_TIM_SET_COMPARE(&htim3,TIM_CHANNEL_2,0);
							
							if((time2_down)||(default2))
						 __HAL_TIM_SET_COMPARE(&htim3,TIM_CHANNEL_4,Set_Speed2/17);
							else
						 __HAL_TIM_SET_COMPARE(&htim3,TIM_CHANNEL_4,0);
			 }
			 
			 if((default1==0)&&(default2==0)&&(default3==0)&&(default4==0)&&(time1_down==0)&&(time2_down==0)&&(time3_down==0)&&(time4_down==0))
				 system_init();

		 }
		
	}
	
	
struct _pid{      

	float Kp,Ki,Kd; //¶¨Òå±ÈÀý¡¢»ý·Ö¡¢Î¢·ÖÏµÊý
}pid;
void PID_init(){

	pid.Kp=0.6;//3.8
	pid.Ki=0.015;//0.015
	pid.Kd=0.02;//0.02
}

int sumError1;
int lastError1;
unsigned int PID1()
{  

  int dError=0,Error1=0,B;
   // if((L1_Rel<2000)&&(L1_Rel>100))
   Error1=L1_Speed-L1_Rel;//µ±Ç°Îó²î
   sumError1=Error1+sumError1;//Îó²îºÍ
	  //if(sumError1>3000) sumError1=3000;
   dError=Error1-lastError1;//Îó²îÆ«²î
   lastError1=Error1;
  B=pid.Kp*Error1+pid.Ki*sumError1+pid.Kd*dError;
        
//        if(B>2500) Set_Speed1=2500;
//   if(B<0) Set_Speed1=0;
//        if(B>=0&&B<=2500)
	      if(B>100&&B<2500)
        Set_Speed1=B;
         return(0);
}
int sumError2;
int lastError2;
unsigned int PID2()
{  

  int dError=0,Error=0,B;
        
   Error=L2_Speed-L2_Rel;//µ±Ç°Îó²î
   sumError2=Error+sumError2;//Îó²îºÍ
	  //if(sumError>300) sumError=300;
   dError=Error-lastError2;//Îó²îÆ«²î
   lastError2=Error;
  B=pid.Kp*Error+pid.Ki*sumError2+pid.Kd*dError;
        
        if(B>2500) Set_Speed2=2500;
   if(B<0) Set_Speed2=0;
        if(B>=0&&B<=2500)
        Set_Speed2=B;
         return(0);
}
int sumError3;
int lastError3;
unsigned int PID3()
{  

  int dError=0,Error=0,B;
        
   Error=L3_Speed-L3_Rel;//µ±Ç°Îó²î
   sumError3=Error+sumError3;//Îó²îºÍ
	  //if(sumError>300) sumError=300;
   dError=Error-lastError3;//Îó²îÆ«²î
   lastError3=Error;
  B=pid.Kp*Error+pid.Ki*sumError3+pid.Kd*dError;
        
        if(B>2500) Set_Speed3=2500;
   if(B<0) Set_Speed3=0;
        if(B>=0&&B<=2500)
        Set_Speed3=B;
         return(0);
}
int sumError4;
int lastError4;
unsigned int PID4()
{  

  int dError=0,Error=0,B;
        
   Error=L4_Speed-L4_Rel;//µ±Ç°Îó²î
   sumError4=Error+sumError4;//Îó²îºÍ
	  //if(sumError>300) sumError=300;
   dError=Error-lastError4;//Îó²îÆ«²î
   lastError4=Error;
  B=pid.Kp*Error+pid.Ki*sumError4+pid.Kd*dError;
        
        if(B>2500) Set_Speed4=2500;
   if(B<0) Set_Speed4=0;
        if(B>=0&&B<=2500)
        Set_Speed4=B;
         return(0);
}
