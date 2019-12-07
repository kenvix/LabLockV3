#ifndef __INC_GUARD_WATCHDOG
#define __INC_GUARD_WATCHDOG

#include <REG52.H>

#define LED_PORT P2 //定义LED 控制端口为P2 口


void WatchDog_Init(void) 
{
    EX1 = 1; //允许外部中断1 中断
    IT1 = 0; //低电平触发
    EA = 1; //允许所有中断
    WDT_CONTR = 256; //使能看门狗，预分频64
    EN_WDT = 1;
}

void WatchDog_Feed(void) 
{
    WDT_CONTR = 0x35;
}


void EXT1IRQ(void) interrupt 2

{

    WDTFeed(); //喂狗
}

#endif