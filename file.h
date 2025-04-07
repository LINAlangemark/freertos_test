#ifndef FILE_H_
#define FILE_H_

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

#include "str_debugger.h"
#include "debugger.h"
#include "glob_def.h"
#include "controller_params.h"

typedef INT32U EMP_FILE;

#define MAX_FILES 8
#define COM1 0  // UART
#define COM2 1  // LCD
#define COM3 2  // Keyboard

typedef struct {
  BOOLEAN (*put)(INT8U);
  BOOLEAN (*get)(INT8U*);
} fcb;

extern fcb pof[MAX_FILES];   // declare, not define
extern INT8U init_files();
BOOLEAN put_file(EMP_FILE, INT8U);

#endif /* FILE_H_ */
