/*
�㲥д������SCS15�в���ͨ����������������ͺ�SCSϵ�ж������ĺ��ʵ�λ�á��ٶ�����ʱ������
*/

#include "stm32f4xx.h"
#include "SCServo.h"
#include "uart.h"
#include "wiring.h"

void setup(void)
{
	Uart_Init(1000000);;
  delay(1000);
}

void loop(void)
{
  WritePos(0xfe, 1000, 0, 1500);//���(ID1),������ٶ�V=1500��/��,������P1=1000
  delay(754);//[(P1-P0)/V]*1000+100
	
  WritePos(0xfe, 20, 0, 1500);//���(ID1),������ٶ�V=1500��/��,������P0=20
  delay(754);//[(P1-P0)/V]*1000+100
}
