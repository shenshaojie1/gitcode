#ifndef _ht1623_h_
#define _ht1623_h_
#include "main.h"

#define  BIAS     0x52             //0b1000 0101 0010  1/3duty 4com 
#define  SYSDIS   0X00             //0b1000 0000 0000  ???????LCD????? 
#define  SYSEN    0X02             //0b1000 0000 0010 ??????? 
#define  LCDOFF   0X04             //0b1000 0000 0100  ?LCD?? 
#define  LCDON    0X06             //0b1000 0000 0110  ??LCD?? 
#define  XTAL     0x28             //0b1000 0010 1000 ????? 
#define  RC256    0X30             //0b1000 0011 0000  ???? 
#define  WDTDIS1  0X0A            //0b1000 0000 1010  ????? 

////??????
//#define Ht1621_CS_PORT (GPIOC)
//#define Ht1621_CS_PIN  (GPIO_PIN_7)

//#define Ht1621_WR_PORT (GPIOC)
//#define Ht1621_WR_PIN  (GPIO_PIN_6)

//#define Ht1621_DAT_PORT (GPIOE)
//#define Ht1621_DAT_PIN  (GPIO_PIN_5)

////#define Ht1621_GND_PORT (GPIOC)
////#define Ht1621_GND_PIN  (GPIO_PIN_6)

//#define Ht1621_VCC_PORT (GPIOA)
//#define Ht1621_VCC_PIN  (GPIO_PIN_3)

//??????
#define Clr_1625_Cs  HAL_GPIO_WritePin(GPIOB, Ht1621_CS_Pin, GPIO_PIN_RESET) // 
#define Set_1625_Cs  HAL_GPIO_WritePin(GPIOB, Ht1621_CS_Pin, GPIO_PIN_SET)

#define Clr_1625_Wr  HAL_GPIO_WritePin(GPIOB, Ht1621_WR_Pin, GPIO_PIN_RESET)  // 
#define Set_1625_Wr  HAL_GPIO_WritePin(GPIOB, Ht1621_WR_Pin, GPIO_PIN_SET)

#define Clr_1625_Dat HAL_GPIO_WritePin(GPIOB, Ht1621_DAT_Pin, GPIO_PIN_RESET) // Ht1621_DAT_Pin
#define Set_1625_Dat HAL_GPIO_WritePin(GPIOB, Ht1621_DAT_Pin, GPIO_PIN_SET)

//#define Ht1621_GND_0() GPIO_Init(Ht1621_GND_PORT, Ht1621_GND_PIN, GPIO_MODE_OUT_PP_LOW_SLOW)  //
//#define Ht1621_GND_1() GPIO_Init(Ht1621_GND_PORT, Ht1621_GND_PIN, GPIO_MODE_OUT_PP_HIGH_FAST)

//#define Ht1621_VCC_ON() GPIO_Init(Ht1621_VCC_PORT, Ht1621_VCC_PIN, GPIO_MODE_OUT_PP_LOW_FAST)  //
//#define Ht1621_VCC_OFF() GPIO_Init(Ht1621_VCC_PORT, Ht1621_VCC_PIN, GPIO_MODE_OUT_PP_HIGH_SLOW)

extern void lcd_init(void);
extern void lcd_clr(void);
extern void lcd_all(void);
extern void data_convertor(unsigned long adc_value);
extern void Display_lcd_dot(void);
extern void Ht1621WrAllData(unsigned char Addr,unsigned char *p,unsigned char cnt);
extern void Ht1621WrOneData(unsigned char Addr,unsigned char Data);
extern unsigned char Ht1621Tab[];
extern unsigned char Ht1621Tab1[];
void write_addr_dat_n(unsigned char _addr, unsigned char _dat, unsigned char n);

#endif
/********************************WUZUXING*************************************/

