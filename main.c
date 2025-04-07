/*
 * main.c
 *
 *  Created on: 18 Mar 2025
 *      Author: linax
 */
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
#include "controller_params.h"


//Priority Defines
#define Prio_Debug 2 //high
#define Prio_Uart_Tx 1
#define Prio_Controller 3
#define Prio_Uart_Rx 2
#define Prio_Led 1
#define Prio_Sw 2 //low

// Task Handles
TaskHandle_t vControllerTaskHandle;
TaskHandle_t vLedTaskHandle;
TaskHandle_t vSwitchTaskHandle;
TaskHandle_t vUartRxTaskHandle;
TaskHandle_t vUartTxTaskHandle;
TaskHandle_t vDebugTaskHandle;

static void setupHardware(void)
/*****************************************************************************
*   Input    :  -
*   Output   :  -
*   Function :
*****************************************************************************/
{

  init_systick(); //ny systick handler til rtos??
  uart0_init(9600, 8, 1, 'n');
  uart0_fifos_disable(); //dunno
  init_gpio();
  init_files();

  GPIO_PORTF_DATA_R &= ~(0x0E);   // reset LEDs


}

int main(void)
{
        setupHardware(); //rename

        xUartRxQueue = xQueueCreate( 1, sizeof(char)); //add semaphore/mutex
        xUartTxQueue = xQueueCreate( 1, sizeof(char)); //add semaphore/mutex
        uart0_putc('M');


        Controller.CtrlInput = xUartRxQueue;
        Controller.CtrlOutput = xUartTxQueue;



        gprintf("=== MAIN===\n"); //dummies??

        xTaskCreate( vControllerTask,"CONTROLLER    ", 200, (void*)&Controller, Prio_Controller, &vControllerTaskHandle);

        xTaskCreate( vUartTxTask,"UART_TX", 200, (void*)&Controller, Prio_Uart_Tx, &vUartTxTaskHandle);

        xTaskCreate( vLedTask, "LED_TASK", 200, NULL, Prio_Led, &vLedTaskHandle);

        xTaskCreate( vUartRxTask, "UART_RX",  200,(void*)&Controller, Prio_Uart_Rx, &vUartRxTaskHandle);

        xTaskCreate( vSwitchTask, "SW_TASK", 200, NULL, Prio_Sw, &vSwitchTaskHandle);

        xTaskCreate(vDebugTask, "DEBUG", 256, NULL, Prio_Debug, &vDebugTaskHandle);

        vTaskStartScheduler();

        for(;;);

}


