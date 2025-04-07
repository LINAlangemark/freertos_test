/*
 * runtime_stats.c
 *
 *  Created on: 31 Mar 2025
 *      Author: linax
 */
#include "emp_type.h"

// Define the runtime counter
volatile unsigned long g_ulRunTimeCounter = 0;

// Called during FreeRTOS setup
void setupRuntimeStatsTimer(void) {
    // No timer config needed if incrementing in SysTick
    g_ulRunTimeCounter = 0;
}

// Add this in SysTick_Handler (if you're not already doing it)
void SysTick_Handler(void) {
    g_ulRunTimeCounter++;  // increment runtime counter
    xPortSysTickHandler(); // keep FreeRTOS tick working
}




