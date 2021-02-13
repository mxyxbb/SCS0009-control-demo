#include "stm32f4xx.h"
#include "wiring.h"

extern void setup(void);
extern void loop(void);

void initSys(void)
{
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE);
  RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOB, ENABLE);
  RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART1, ENABLE);
  RCC_APB1PeriphClockCmd(RCC_APB1Periph_USART2, ENABLE);
	
  // 2 bit for pre-emption priority, 2 bits for subpriority
  NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
	
	SysTick_Config(SystemCoreClock / 1000);
}

int main()
{
	initSys();
	setup();
	while(1){
		loop();
	}
}
