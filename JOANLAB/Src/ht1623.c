/*******************************************************************************
????:??????
????:
????:2013/09/07
????:
????:
*******************************************************************************/
#include "ht1623.h"
/*******************************************************************************
* ?    ?: delay(uint i)
* ?    ?: 5us??
* ?    ?: 
* ? ? ?: ?
*
* ????:
* ??    ??     ??     ???????
*   ----------------------------------------------------
*******************************************************************************/
void delay(uint16_t time)
{
    unsigned char a;
    for(a=100;a>0;a--);
	

}


void write_mode(unsigned char MODE)	//д��ģʽ,����or����
{
	delay(10);
	Clr_1625_Wr;							//	RW = 0;
	delay(10);
	Set_1625_Dat;								//	DA = 1;
	Set_1625_Wr;								//	RW = 1;
	delay(10);

	Clr_1625_Wr;								//	RW = 0;
	delay(10);
	Clr_1625_Dat;
   delay(10);	//	DA = 0;
	Set_1625_Wr;									//	RW = 1;
	delay(10);

	Clr_1625_Wr;							//	RW = 0;
	delay(10);

	if (0 == MODE)
	{
		Clr_1625_Dat;							//	DA = 0;
	}
	else
	{
		Set_1625_Dat;							//	DA = 1;
	}
	delay(10);
	Set_1625_Wr;									//	RW = 1;
	delay(10);
}

/*
*	LCD ����д�뺯��
*	���:cbyte ,����������
*	����:void
*/
void write_command(unsigned char Cbyte)
{
	unsigned char i = 0;

	for (i = 0; i < 8; i++)
	{
		Clr_1625_Wr;
		//Delay_us(10);


		if ((Cbyte >> (7 - i)) & 0x01)
		{
			Set_1625_Dat;
		}
		else
		{
			Clr_1625_Dat;
		}
		delay(10);
		Set_1625_Wr;
		delay(10);
	}
	Clr_1625_Wr;
	delay(10);
	Clr_1625_Dat;
	Set_1625_Wr;
	delay(10);
}
 
/*
*	LCD ��ַд�뺯��
*	���:cbyte,��ַ
*	����:void
*/
void write_address(unsigned char Abyte)
{
	unsigned char i = 0;
	Abyte = Abyte << 1;

	for (i = 0; i < 7; i++)
	{
		Clr_1625_Wr;
		//Delay_us(10);
		if ((Abyte >> (7 - i)) & 0x01)
		{
			Set_1625_Dat;
		}
		else
		{
			Clr_1625_Dat;
		}
		delay(10);
		Set_1625_Wr;
		delay(10);
	}
}

/*
*	LCD ����д�뺯��
*	���:Dbyte,����
*	����:void
*/
void write_data_8bit(unsigned char Dbyte)
{
	int i = 0;

	for (i = 0; i < 8; i++)
	{
		Clr_1625_Wr;
		//Delay_us(10);
		if ((Dbyte >> (7 - i)) & 0x01)
		{
			Set_1625_Dat;
		}
		else
		{
			Clr_1625_Dat;
		}
		delay(10);
		Set_1625_Wr;
		delay(10);
	}
}

void write_data_4bit(unsigned char Dbyte)
{
	int i = 0;

	for (i = 0; i < 4; i++)
	{
		Clr_1625_Wr;
		//Delay_us(10);
		if ((Dbyte >> (3 - i)) & 0x01)
		{
			Set_1625_Dat;
		}
		else
		{
			Clr_1625_Dat;
		}
		delay(10);
		Set_1625_Wr;
		delay(10);
	}
}

///////////////////////////////////////////////////�ӿں���
/*
*	LCD ��ʼ������lcd��������ʼ������
*	���:void
*	����:void
*/
void lcd_init(void)
{
	//////////////////////////////////////////////////////
	Set_1625_Cs;
	Set_1625_Wr;
	Set_1625_Dat;
	delay(500);

	//////////////////////////////////////////////////////        
	Clr_1625_Cs;       //CS = 0;
	delay(10);
	write_mode(0);    //����ģʽ
	write_command(0x01);	//Enable System
	write_command(0x03);	//Enable Bias
	write_command(0x04);	//Disable Timer
	write_command(0x05);	//Disable WDT
	write_command(0x08);	//Tone OFF
	write_command(0x18);	//on-chip RC��
	write_command(0x29);	//1/4Duty 1/3Bias
	write_command(0x80);	//Disable IRQ
	write_command(0x40);	//Tone Frequency 4kHZ
	write_command(0xE3);	//Normal Mode

	Set_1625_Cs;  //CS = 1;
}

/*
*	LCD ��������
*	���:void
*	����:void
*/
void lcd_clr(void)
{
	write_addr_dat_n(0x0, 0x00, 50);
}

/*
*	LCD ȫ��ʾ����
*	���:void
*	����:void
*/
void lcd_all(void)
{
	write_addr_dat_n(0x0, 0xFF,50);
}

void write_addr_dat_n(unsigned char _addr, unsigned char _dat, unsigned char n)
{
	unsigned char i = 0;

	Clr_1625_Cs;							// CS = 0;
	delay(10);
	write_mode(1);
	write_address(_addr);

	for (i = 0; i < n; i++)
	{
		write_data_8bit(_dat);
	}
	Set_1625_Cs;							//CS = 1;
}
