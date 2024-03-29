#include	"uart.h"

/***************************************************************************
 * 描  述 : 串口1初始化函数
 * 入  参 : 无
 * 返回值 : 无
备注：波特率9600bps   晶振11.0592MHz
 **************************************************************************/
void Uart1_Init(void)
{	
	PCON &= 0x3f;		//波特率不倍速，串行口工作方式由SM0、SM1决定
	SCON = 0x50;		//8位数据,可变波特率，启动串行接收器
	AUXR |= 0x40;		//定时器1时钟为Fosc,即1T
	AUXR &= 0xfe;		//串口1选择定时器1为波特率发生器
	TMOD &= 0x0f;		//清除定时器1模式位
	TMOD |= 0x20;		//设定定时器1为8位自动重装方式
	TL1 = 0xDC;		  //设定定时初值
	TH1 = 0xDC;		  //设定定时器重装值
	ET1 = 0;		    //禁止定时器1中断
	TR1 = 1;		    //启动定时器1
	ES = 1;         // 串口1中断打开
}

/***************************************************************************
 * 描  述 : 串口1发送数据函数
 * 入  参 : uint8 数据
 * 返回值 : 无
 **************************************************************************/
void SendDataByUart1(uint8 dat)
{
    SBUF = dat;                 //写数据到UART数据寄存器
		while(TI == 0);             //在停止位没有发送时，TI为0即一直等待
		TI = 0;                     //清除TI位（该位必须软件清零）
}

/***************************************************************************
 * 描  述 : 重定向c库函数printf到USART1
 * 入  参 : char dat
 * 返回值 : char 
 **************************************************************************/
char putchar(char dat)
{
		SendDataByUart1(dat);           
		return dat;                    
}

/***************************************************************************
 * 描  述 : 串口1中断服务函数
 * 入  参 : 无
 * 返回值 : 无
 **************************************************************************/
void Uart1() interrupt 4 using 1
{
	ES = 0;                       //串口1中断关闭
	if (RI)                       //串行接收到停止位的中间时刻时，该位置1
  {
      RI = 0;                   //清除RI位 （该位必须软件清零）        
   }
   if (TI)                      //在停止位开始发送时，该位置1
   {
      TI = 0;                   //清除TI位（该位必须软件清零）
   }
	 ES =  1;                     //串口1中断打开
}

/*********************************END FILE********************************************/	

