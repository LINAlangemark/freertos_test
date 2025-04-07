/*
 * uart_rx_task.c
 *
 *  Created on: 19 Mar 2025
 *      Author: linax
 */


#include "uart_rx_task.h"


void vUartRxTask(void *pvParameters)
{
    Controller_t *ctrl = (Controller_t *)pvParameters;
    char txChar;
    for( ;; )
    {
        txChar = uart0_getc();
        xQueueSendToFront(ctrl->CtrlInput, &txChar, portMAX_DELAY);



        //to context switch to controller task
        vTaskDelay( pdMS_TO_TICKS( 1000) );

    }
}
