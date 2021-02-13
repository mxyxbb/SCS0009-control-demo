/*
回读所有舵机反馈参数:位置、速度、负载、电压、温度、移动状态、电流；
FeedBack函数回读舵机参数于缓冲区，Readxxx(-1)函数返回缓冲区中相应的舵机状态；
函数Readxxx(ID)，ID=-1返回FeedBack缓冲区参数；ID>=0，通过读指令直接返回指定ID舵机状态,
无需调用FeedBack函数。
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
