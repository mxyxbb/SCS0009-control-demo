/*
�ض����ж����������:λ�á��ٶȡ����ء���ѹ���¶ȡ��ƶ�״̬��������
FeedBack�����ض���������ڻ�������Readxxx(-1)�������ػ���������Ӧ�Ķ��״̬��
����Readxxx(ID)��ID=-1����FeedBack������������ID>=0��ͨ����ָ��ֱ�ӷ���ָ��ID���״̬,
�������FeedBack������
*/

//#include <stdio.h>
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
	int Pos;
  int Speed;
  int Load;
  int Voltage;
  int Temper;
  int Move;
  int Current;
  if(FeedBack(1)!=-1){
    Pos = ReadPos(-1);
    Speed = ReadSpeed(-1);
    Load = ReadLoad(-1);
    Voltage = ReadVoltage(-1);
    Temper = ReadTemper(-1);
    Move = ReadMove(-1);
		Current = ReadCurrent(-1);
		//printf("Pos:%d\n", Pos);
		//printf("Speed:%d\n", Speed);
		//printf("Load:%d\n", Load);
		//printf("Voltage:%d\n", Voltage);
		//printf("Temper:%d\n", Temper);
		//printf("Move:%d\n", Move);
    //printf("Current:%d\n", Current);
    delay(10);
  }else{
		//printf("FeedBack err\n");
    delay(2000);
  }
  Pos = ReadPos(1);
  if(Pos!=-1){
    //printf("Servo position:%d\n", Pos);
    delay(10);
  }else{
    //printf("read position err\n");
    delay(500);
  }
  
  Voltage = ReadVoltage(1);
  if(Voltage!=-1){
		//printf("Servo Voltage:%d\n", Voltage);
    delay(10);
  }else{
    //printf("read Voltage err\n");
    delay(500);
  }
  
  Temper = ReadTemper(1);
  if(Temper!=-1){
    //printf("Servo temperature:%d\n", Temper);
    delay(10);
  }else{
    //printf("read temperature err\n");
    delay(500);    
  }

  Speed = ReadSpeed(1);
  if(Speed!=-1){
    //printf("Servo Speed:%d\n", Speed);
    delay(10);
  }else{
    //printf("read Speed err\n");
    delay(500);    
  }
  
  Load = ReadLoad(1);
  if(Load!=-1){
    //printf("Servo Load:%d\n", Load);
    delay(10);
  }else{
    //printf("read Load err\n");
    delay(500);    
  }
  
  Current = ReadCurrent(1);
  if(Current!=-1){
    //printf("Servo Current:%d\n", Current);
    delay(10);
  }else{
    //printf("read Current err\n");
    delay(500);    
  }

  Move = ReadMove(1);
  if(Move!=-1){
    //printf("Servo Move:%d\n", Move);
    delay(10);
  }else{
    //printf("read Move err\n");
    delay(500);    
  }
  //printf("\n");
}
