/*
 * uart_config.h
 *
 *  Created on: 19 Mar 2025
 *      Author: linax
 */

#ifndef UART_CONFIG_H_
#define UART_CONFIG_H_

#include "FreeRTOS.h"    // Must be first – sets up configuration and core types
#include "task.h"        // Defines task-related types and functions
#include "queue.h"       // Defines queue-related types and functions

// Now include other project-specific headers that might use FreeRTOS types:
#include "emp_type.h"

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

extern BOOLEAN uart0_put_q(INT8U ch);
extern BOOLEAN uart0_get_q(INT8U *pch);
extern BOOLEAN uart0_rx_rdy();
extern INT8U uart0_getc();
extern BOOLEAN uart0_tx_rdy();
extern void uart0_putc( INT8U ch );
INT32U lcrh_databits( INT8U antal_databits );
INT32U lcrh_stopbits( INT8U antal_stopbits );
INT32U lcrh_parity( INT8U parity );
extern void uart0_fifos_enable();
void uart0_fifos_disable();

extern void uart0_init( INT32U, INT8U, INT8U, INT8U );
/*****************************************************************************
*   Input    : -
*   Output   : -
*   Function : Initialize uart 0
******************************************************************************/

/****************************** End Of Module *******************************/


#endif /* UART_CONFIG_H_ */
