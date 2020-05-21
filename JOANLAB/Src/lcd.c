#include "lcd.h"
#include "user.h"
void write_addr_dat_n(unsigned char _addr, unsigned char _dat, unsigned char n);

uint8_t  LCD_ADD[]={0x5f,0x06,0x3d,0x2f,0x66,0x6b,0x7b,0x0e,0x7f,0x6f};
uint8_t Time_Status;
uint8_t Rpm_B,Rpm_S,Rpm_G,time_1,time_2;
uint16_t Rpm,Time_SUM;
extern  uint16_t  Set_Flag,Key_Count,Key1_Count;
extern uint8_t Sys_Mode;
uint8_t Set_Flag1,Set_Flag2,point_add;
extern uint8_t Point_Flag;
extern uint8_t KEY1_Pin_ON;
void LCD_Display()
{
	
	
	//Rpm=234;
	//Time_SUM=3600;
	
	if(Rpm<10) {Rpm_B=0;Rpm_S=0;Rpm_G=0;}
	else if (Rpm<100) {Rpm_B=0;Rpm_S=0;Rpm_G=Rpm/10;}
	else if (Rpm<1000) {Rpm_B=0;Rpm_S=Rpm/100;Rpm_G=Rpm/10%10;}
	else if (Rpm<10000) {Rpm_B=Rpm/1000;Rpm_S=Rpm/100%10;Rpm_G=Rpm/10%10;}
	//更新转速
	
	if(Time_SUM<60) Time_Status =0;
	else Time_Status =1;
	if(Time_Status ==0) {time_1=Time_SUM/10;time_2=Time_SUM%10;if(Time_SUM<10) time_1=0;}
	else if(Time_Status ==1) {time_1=Time_SUM/60/10;time_2=Time_SUM/60%10;if(Time_SUM<10) time_1=0;}
	//更新时间
	


	if(Set_Flag1)
	{
		  if((Key_Count==0)&&(Key1_Count==0))
			{
				write_addr_dat_n(0x00, 0, 1);
				write_addr_dat_n(0x02, 0, 1);
				write_addr_dat_n(0x04, 0, 1);
			}
			else
			{
			write_addr_dat_n(0x00, LCD_ADD[Rpm_B], 1);
			write_addr_dat_n(0x02, LCD_ADD[Rpm_S], 1);
			write_addr_dat_n(0x04, LCD_ADD[Rpm_G], 1);
	    }
	
	}
	else
	{
			write_addr_dat_n(0x00, LCD_ADD[Rpm_B], 1);
			write_addr_dat_n(0x02, LCD_ADD[Rpm_S], 1);
			write_addr_dat_n(0x04, LCD_ADD[Rpm_G], 1);
	}
	
	if(Set_Flag2)
	{
		  if((Key_Count==0)&&(Key1_Count==0))
			{
				write_addr_dat_n(0x06,0|0x80, 1);
				write_addr_dat_n(0x08, 0&0xf0, 1);
				write_addr_dat_n(0x0a, (0&0x0f)<<4, 1);
			}
			else
			{
					write_addr_dat_n(0x06, LCD_ADD[time_1]|0x80, 1);
					write_addr_dat_n(0x08, LCD_ADD[time_2]&0xf0, 1);
					write_addr_dat_n(0x0a, (LCD_ADD[time_2]&0x0f)<<4, 1);
			}				
		
	}
	else
	{
			write_addr_dat_n(0x06, LCD_ADD[time_1]|0x80, 1);
			write_addr_dat_n(0x08, LCD_ADD[time_2]&0xf0, 1);
			write_addr_dat_n(0x0a, (LCD_ADD[time_2]&0x0f)<<4, 1);
	}
	
	if(Set_Flag2)
	{
		if((Key_Count==0)&&(Key1_Count==0))
   	point_add=0;
		else
		point_add=LCD_ADD[time_2];	
	}
	else
	point_add=LCD_ADD[time_2];
	
	
	
	
	if(Time_Status ==0) 
	{
		if(Point_Flag==1)
		write_addr_dat_n(0x08, ((point_add|0x01)&0xf7)&0x7f, 1);
		else
		write_addr_dat_n(0x08, ((point_add|0x01)&0xf7)|0x80, 1);	
		
	}
	else
	{
		if(Point_Flag==1)
		write_addr_dat_n(0x08, ((point_add|0x08)&0xfe)&0x7f, 1);
		else
		write_addr_dat_n(0x08,  ((point_add|0x08)&0xfe)|0x80, 1);	
	}
	//更新时间状态
	
//	if(Sys_Mode==Sys_Point)
//	{
//     if(Point_Flag==1)
//		 {
//			 write_addr_dat_n(0x08, (LCD_ADD[time_2]&0xf0)&0x7f, 1);
//		 }
//		 else
//		 {
//			 write_addr_dat_n(0x08, (LCD_ADD[time_2]&0xf0)|0x80, 1);
//		 }
//			 
//	}
//	else write_addr_dat_n(0x08, (LCD_ADD[time_2]&0xf0)|0x80, 1);
//	
	
	
	
	
	
}
