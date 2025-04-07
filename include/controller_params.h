/*
 * controller_params.h
 *
 *  Created on: 18 Mar 2025
 *      Author: linax
 */

#ifndef CONTROLLER_PARAMS_H_
#define CONTROLLER_PARAMS_H_
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
#include "led_task.h"
#include "sw_task.h"
#include "uart_rx_task.h"
#include "file.h"
#include "str_debugger.h"
#include "debugger.h"
#include "glob_def.h"




/*
#define KP    (1.0f)
#define KI    (0.5f)
#define KD    (0.1f)
#define TF    (0.05f)
#define TAW   (0.1f)
#define H     (0.01f)  // 10 ms
*/



#define CTRL_IDLE  0
#define CTRL_RUNNING 1

extern xQueueHandle xUartRxQueue;
extern xQueueHandle xUartTxQueue;

typedef struct {
    BaseType_t CtrlState;
    unsigned char Feedback;
    xQueueHandle CtrlInput;
    xQueueHandle CtrlOutput;
} Controller_t;


extern Controller_t Controller;



void vControllerTask(void *pvParameters);

#endif /* CONTROLLER_PARAMS_H_ */
