#ifndef __I2C_H
#define __I2C_H			 
#include "delay.h"

extern void I2C_init(void);
extern void	I2C_Wait(void);
extern void I2C_Start(void);
extern void I2C_SendData(uint8 dat);
extern void I2C_RecvACK(void);
extern void I2C_SendACK(void) ;
extern void I2C_SendNAK(void);
extern uint8 I2C_RecvData(void);
extern void I2C_Stop(void);


#endif 

