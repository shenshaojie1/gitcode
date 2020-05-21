#ifndef _user_h_
#define _user_h_
#include "main.h"

void Sys_Init(void);

typedef enum{
	Sys_OFF,
	Sys_ON,
	Sys_Set,
	Sys_RUN,
	Sys_Point,
	Sys_Cont,
	Sys_STOP,
}Sys_ModeTypeDef;




#endif
