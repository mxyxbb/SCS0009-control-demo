/*
舵机参数编程
*/

#include "stm32f4xx.h"
#include "SCServo.h"
#include "uart.h"
#include "wiring.h"

void setup()
{
	Uart_Init(1000000);
	delay(1000);
	unLockEprom(1);//打开EPROM保存功能
  writeByte(1, SCSCL_ID, 2);//ID
  writeWord(2, SCSCL_MIN_ANGLE_LIMIT_L, 20);
	writeWord(2, SCSCL_MAX_ANGLE_LIMIT_L, 1000);
	LockEprom(2);//关闭EPROM保存功能
}

void loop()
{

}
