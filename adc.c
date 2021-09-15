#include "adc.h"	

 /**************************************************************************
功能描述：ADC口初始化
入口参数：无
返回值：无
 *************************************************************************/
void	ADC_config(void)
{	
	ADC_CONTR|=0x80;      	//开AD转换电源
	delay_ms(10);           //适当延时等待AD转换供电稳定
	ADC_CONTR|=0x0E;		//选择P0.6作为模拟功能AD使用
	ADC_CONTR&=0xFE;		//选择P0.6作为模拟功能AD使用
	
	ADCCFG&=0xFC;             //AD转换速度为416个时钟数转换一次
	ADCCFG|=0x0C;             //AD转换速度为416个时钟数转换一次
	ADC_CONTR&=0xDF;          //清AD转换完成标志
		
	EADC=0;                   //禁止ADC转换中断
	ADCCFG|=0x20;             //ADC转换结果ADC_RES存高4位，ADC_RESL存低8位
	ADC_CONTR|=0x40;          //启动AD转换，ADC_START=1
}

/**************************************
功能描述：ADC口检测AD转换值函数
入口参数：无
返回值：ADC 12位数据
***************************************/
uint16	Get_ADC12bitResult(void)	
{
	uint16	AD_Dat=0;
 	ADC_CONTR&=0xDF;  	    // 将ADC_FLAG清0
	ADC_CONTR&=0xBF;        //关闭AD转换，ADC_START=0	//12位AD结果的高4位放ADC_RES的低4位，低8位在ADC_RESL
	AD_Dat = ADC_RES;		       //将ADC_RES低4位移到应在的第9位至第12位
	AD_Dat <<= 8;
	AD_Dat|= ADC_RESL;	       //将ADC_RESL的8位移到应在的低8位
	
  ADC_CONTR|=0x40;           //启动AD转换，ADC_START=1
	return	AD_Dat;	
}

/***************************************************************************
功能描述：将采集的原始值转换为电压值
入口参数：无
返回值：实测电压值
 **************************************************************************/
uint16 HandleADC(void)
{
	uint16 Temp_signal;
//	float g_voltage;

	//读取采集的原始值
	Temp_signal=Get_ADC12bitResult();  
	
//因为开发板J6选择2V5为ADC基准电压。所以计算电压值公式：V=Temp_signal/4096*2.5。（单位V）
//	if((Temp_signal<TEMPMAX)&&(Temp_signal>TEMPMIN))
//	{
//    g_voltage=(2.5*Temp_signal)/4096;		 	    //（单位V）
//	}		
	
  //返回实测电压值
	return Temp_signal;	
}

/*********************************END FILE********************************************/	

