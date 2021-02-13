/*
�첽д������SCS15�в���ͨ����������������ͺ�SCSϵ�ж������ĺ��ʵ�λ�á��ٶ�����ʱ������
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
  RegWritePos(1, 1000, 0, 1500);//���(ID1),������ٶ�V=1500��/��,������P1=1000
  RegWritePos(2, 1000, 0, 1500);//���(ID2),������ٶ�V=1500��/��,������P1=1000
  RegWriteAction();
  delay(754);//[(P1-P0)/V]*1000+100
	
  RegWritePos(1, 20, 0, 1500);//���(ID1),������ٶ�V=1500��/��,������P0=20
  RegWritePos(2, 20, 0, 1500);//���(ID2),������ٶ�V=1500��/��,������P0=20
  RegWriteAction();
  delay(754);//[(P1-P0)/V]*1000+100
}
