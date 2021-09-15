#include "delay.h"	
/*****************************************************************
功能描述：延时函数
入口参数：uint16 x ，该值为1时，延时1ms，在11.0592MHZ下
返回值：无
*****************************************************************/
void delay_ms(uint16 x) 
{  
	uint16 j,i;   
	for(j=0;j<x;j++)   
	{    
		for(i=0;i<1580;i++);   
	}  
}

/*******************************************************************
功能描述：延时函数，延时约10us，在11.0592MHZ下
入口参数：无
返回值：无
********************************************************************/
void Delay10us(void)		
{
	uint8 i;
  _nop_();
	i = 33;
	while (--i);
}

/*********************************END FILE********************************************/	
