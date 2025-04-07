

#include "uart_tx_task.h"
/*
 * uart_tx_task.c
 *
 *  Created on: 19 Mar 2025
 *      Author: linax
 */




void vUartTxTask(void *pvParameters)
{
    Controller_t *ctrl = (Controller_t *)pvParameters;
    char rxChar;
    //const TickType_t xDelay300ms = pdMS_TO_TICKS( 300 );

    for(;;)
    {

        // control should be released from listening tasks if buffer is full
        if (xQueueReceive(ctrl->CtrlOutput, &rxChar, portMAX_DELAY))
        {

            uart0_putc(rxChar);
            ctrl->Feedback = rxChar;

          //DELAY
          vTaskDelay( pdMS_TO_TICKS( 1000) );
        }


    }
}
