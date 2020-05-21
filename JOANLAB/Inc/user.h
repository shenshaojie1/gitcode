#ifndef _user_h_
#define _user_h_

#include "main.h"
 void system_init(void);
void PWM_Set(void);
void PID_init(void);
#define	Sys_OFF  0
#define	Sys_ON   1
#define	Sys_SET  2
#define	Sys_RUN  3

#define	Time_sec  0
#define	Time_min  1


#endif
