/*****************************************************************************
* University of Southern Denmark
* Embedded Programming (EMP)
*
* MODULENAME.: systick.h
*
* PROJECT....: EMP
*
* DESCRIPTION: Initialize the systick interrupt.
*
* Change Log:
******************************************************************************
* Date    Id    Change
* YYMMDD
* --------------------
* 150215  MoH    Module created.
*
*****************************************************************************/

#ifndef SYSTICK_H_
#define SYSTICK_H_


/***************************** Include files *******************************/
#include <stdint.h>
#include "FreeRTOS.h"    // Must be first – sets up configuration and core types
#include "task.h"        // Defines task-related types and functions
#include "queue.h"       // Defines queue-related types and functions

// Now include other project-specific headers that might use FreeRTOS types:
#include "emp_type.h"
#include "uart_config.h"

// Hardware-specific headers:
#include "tm4c123gh6pm.h"
#include "gpio.h"
#include "led_state.h"

// Application-specific modules:
#include "led_task.h"
#include "sw_task.h"
#include "uart_rx_task.h"
#include "file.h"
#include "str_debugger.h"
#include "debugger.h"
#include "glob_def.h"
#include "controller_params.h"

/*****************************    Defines    *******************************/

/*****************************   Constants   *******************************/

/*****************************   Functions   *******************************/
void enable_global_int();
/*****************************************************************************
*   Input    : -
*   Output   : -
*   Function : Enable global interrupt.
******************************************************************************/


void disable_global_int();
/*****************************************************************************
*   Input    : -
*   Output   : -
*   Function : Disable global interrupt.
******************************************************************************/


void init_systick();
/*****************************************************************************
*   Input    : -
*   Output   : -
*   Function : Initialize the systick interrupt.
******************************************************************************/


/****************************** End Of Module *******************************/


extern volatile unsigned long g_ulRunTimeCounter;
void setupRuntimeStatsTimer(void);


#endif /*SYSTICK_H_*/


