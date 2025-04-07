/*
 * led_task.h
 *
 *  Created on: 19 Mar 2025
 *      Author: linax
 */

#ifndef LED_TASK_H_
#define LED_TASK_H_

#include "FreeRTOS.h"    // Must be first – sets up configuration and core types
#include "task.h"        // Defines task-related types and functions
#include "queue.h"       // Defines queue-related types and functions

// Now include other project-specific headers that might use FreeRTOS types:
#include "emp_type.h"
#include "uart_config.h"

// Hardware-specific headers:
#include "tm4c123gh6pm.h"
#include "gpio.h"
#include "systick.h"
#include "led_state.h"

// Application-specific modules:
#include "sw_task.h"
#include "uart_rx_task.h"
#include "file.h"
#include "str_debugger.h"
#include "debugger.h"
#include "glob_def.h"
#include "controller_params.h"



void vLedTask(void *pvParameters);


#endif /* SLED_TASK_H_ */
