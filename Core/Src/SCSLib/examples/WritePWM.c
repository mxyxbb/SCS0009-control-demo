/*
电机模式例子
*/

#include "stm32f4xx.h"
#include "SCServo.h"
#include "uart.h"
#include "wiring.h"

void setup()
{
	Uart_Init(1000000);
  delay(1000);
	PWMMode(1);
}

void loop()
{
	WritePWM(1, 500);
	delay(2000);
	WritePWM(1, 0);
	delay(2000);
	WritePWM(1, -500);
	delay(2000);
	WritePWM(1,0);
	delay(2000);
}
