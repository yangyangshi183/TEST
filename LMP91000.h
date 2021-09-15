#ifndef __LMP91000_H
#define __LMP91000_H		
#include "delay.h"	

void LMP91000_Write(uint8 address,uint8 dat);
uint8 LMP91000_Read(uint8 address);
void LMP91000_Init(void);


#endif 
