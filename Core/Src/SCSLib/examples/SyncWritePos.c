/*
ͬ��д������SCS15�в���ͨ����������������ͺ�SCSϵ�ж������ĺ��ʵ�λ�á��ٶ�����ʱ������
*/

#include "stm32f4xx.h"
#include "SCServo.h"
#include "uart.h"
#include "wiring.h"

uint8_t ID[2];
uint16_t Position[2];
uint16_t Speed[2];

void setup(void)
{
	Uart_Init(1000000);
  delay(1000);
  ID[0] = 1;
  ID[1] = 2;
	Speed[0] = 1500;
	Speed[1] = 1500;
}

void loop(void)
{
  Position[0] = 1000;
  Position[1] = 1000;
  SyncWritePos(ID, 2, Position, 0, Speed);//���(ID1/ID2),������ٶ�V=1500��/��,������P1=1000
  delay(754);//[(P1-P0)/V]*1000+100
	
  Position[0] = 20;
  Position[1] = 20;
  SyncWritePos(ID, 2, Position, 0, Speed);//���(ID1/ID2),������ٶ�V=1500��/��,������P0=20
  delay(754);//[(P1-P0)/V]*1000+100
}
