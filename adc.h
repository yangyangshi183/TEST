#ifndef __ADC_H_
#define __ADC_H_

#include "delay.h"

#define  TEMPMAX   4097
#define  TEMPMIN   0

extern void	ADC_config(void);
extern uint16 HandleADC(void);

#endif
