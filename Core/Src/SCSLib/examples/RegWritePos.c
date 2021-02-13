/*
异步写例子在SCS15中测试通过，如果测试其它型号SCS系列舵机请更改合适的位置、速度与延时参数。
*/

#include "stm32f4xx.h"
#include "SCServo.h"
#include "uart.h"
#include "wiring.h"

void setup(void)
{
  Uart_Init(1000000);
  delay(1000);
}

void loop(void)
{
  RegWritePos(1, 1000, 0, 1500);//舵机(ID1),以最高速度V=1500步/秒,运行至P1=1000
  RegWritePos(2, 1000, 0, 1500);//舵机(ID2),以最高速度V=1500步/秒,运行至P1=1000
  RegWriteAction();
  delay(754);//[(P1-P0)/V]*1000+100
	
  RegWritePos(1, 20, 0, 1500);//舵机(ID1),以最高速度V=1500步/秒,运行至P0=20
  RegWritePos(2, 20, 0, 1500);//舵机(ID2),以最高速度V=1500步/秒,运行至P0=20
  RegWriteAction();
  delay(754);//[(P1-P0)/V]*1000+100
}
