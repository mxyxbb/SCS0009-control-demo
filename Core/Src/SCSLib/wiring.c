#include "stm32f4xx_hal.h"

__IO uint32_t TimingMillis = 0;


uint32_t millis(void)
{
	return TimingMillis;
}

void delay(uint32_t ms)
{
    uint32_t end = millis() + ms;
    while (millis() < end);
}
/**
 * @brief �δ�ʱ���ص��������������ڣ�1ms
 */
void HAL_SYSTICK_Callback(void)
{
	TimingMillis++;
}
