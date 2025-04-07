#include <stdint.h>
#include "tm4c123gh6pm.h"
#include "FreeRTOS.h"
#include "task.h"
#include "emp_type.h"
#include "portmacro.h"
#include "systick.h"

#define SYSTICK_RELOAD_VALUE 80000              // 5 ms at 16 MHz
#define NVIC_INT_CTRL_PEND_SYST   0x04000000
#define NVIC_INT_CTRL_UNPEND_SYST 0x02000000
#define SYSTICK_PRIORITY    0x7E

extern void xPortSysTickHandler(void);


volatile int ticks = 0;
volatile unsigned long g_ulRunTimeCounter = 0;

void setupRuntimeStatsTimer(void) {
    g_ulRunTimeCounter = 0;
}

void SysTick_Handler(void) {
    g_ulRunTimeCounter++;
    xPortSysTickHandler();
    ticks++;
}

void init_systick(void) {
    NVIC_ST_CTRL_R &= ~NVIC_ST_CTRL_ENABLE;
    NVIC_ST_CURRENT_R = SYSTICK_RELOAD_VALUE;
    NVIC_ST_RELOAD_R = SYSTICK_RELOAD_VALUE;

    NVIC_INT_CTRL_R |= NVIC_INT_CTRL_UNPEND_SYST;

    NVIC_SYS_PRI3_R &= ~NVIC_SYS_PRI3_TICK_M;
    NVIC_SYS_PRI3_R |= (SYSTICK_PRIORITY << NVIC_SYS_PRI3_TICK_S);

    NVIC_ST_CTRL_R |= NVIC_ST_CTRL_CLK_SRC;
    NVIC_ST_CTRL_R |= NVIC_ST_CTRL_INTEN;
    NVIC_ST_CTRL_R |= NVIC_ST_CTRL_ENABLE;
}

