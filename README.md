# SCS0009-control-demo
STM32F407VET6 | HAL | SCS0009

Successfully porting FeeTech SCS SDK to STM32 

the SDK include the following functions:

```c
extern int genWrite(uint8_t ID, uint8_t MemAddr, uint8_t *nDat, uint8_t nLen);//普通写指令
extern int regWrite(uint8_t ID, uint8_t MemAddr, uint8_t *nDat, uint8_t nLen);//异步写指令
extern int regAction(uint8_t ID);//异步写执行行
extern void syncWrite(uint8_t ID[], uint8_t IDN, uint8_t MemAddr, uint8_t *nDat, uint8_t nLen);//同步写指令
extern int writeByte(uint8_t ID, uint8_t MemAddr, uint8_t bDat);//写1个字节
extern int writeWord(uint8_t ID, uint8_t MemAddr, uint16_t wDat);//写2个字节
extern int Read(uint8_t ID, uint8_t MemAddr, uint8_t *nData, uint8_t nLen);//读指令
extern int readByte(uint8_t ID, uint8_t MemAddr);//读1个字节
extern int readWord(uint8_t ID, uint8_t MemAddr);//读2个字节
extern int Ping(uint8_t ID);//Ping指令

extern void writeBuf(uint8_t ID, uint8_t MemAddr, uint8_t *nDat, uint8_t nLen, uint8_t Fun);
extern void Host2SCS(uint8_t *DataL, uint8_t* DataH, int Data);//1个16位数拆分为2个8位数
extern int SCS2Host(uint8_t DataL, uint8_t DataH);//2个8位数组合为1个16位数
extern int Ack(uint8_t ID);//应答
extern int checkHead(void);//帧头检测

//硬件接口函数
extern int writeSCS(uint8_t *nDat, int nLen);
extern int readSCS(uint8_t *nDat, int nLen);
extern void rFlushSCS(void);
extern void wFlushSCS(void);
```

and there're many examples:

```c
/*
普通写例子在SCS15中测试通过，如果测试其它型号SCS系列舵机请更改合适的位置、速度与延时参数。
*/

#include "stm32f4xx.h"
#include "../SCServo.h"
#include "../uart.h"
#include "../wiring.h"



void loop(void)
{
  WritePos(1, 1000, 0, 1500);//舵机(ID1),以最高速度V=1500步/秒,运行至P1=1000
  delay(754);//[(P1-P0)/V]*1000+100
	
  WritePos(1, 20, 0, 1500);//舵机(ID1),以最高速度V=1500步/秒,运行至P0=20
  delay(754);//[(P1-P0)/V]*1000+100
}

```

```c
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

```

