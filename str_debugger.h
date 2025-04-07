/*
 * str_debugger.h
 *
 *  Created on: 29 Mar 2025
 *      Author: linax
 */

#ifndef STR_DEBUGGER_H_
#define STR_DEBUGGER_H_


#include <stdint.h>
#include <stdarg.h>
#include "tm4c123gh6pm.h"
#include "emp_type.h"
#include "gpio.h"
#include "file.h"
#include "uart_config.h"


// Rename FILE to avoid stdio conflict
typedef INT32U EMP_FILE;

#define COM1 0  // UART file index

void putc1(EMP_FILE *fp, unsigned char ch);
void putStr(EMP_FILE *fp, char *str);
void putChars(EMP_FILE *fp, char *str, int len);
void putDec(EMP_FILE *fp, long val, int sign, int size, char filler);
void putHex(EMP_FILE *fp, long val, int size);

const void gprint(EMP_FILE *fp, const char *str, va_list vaArgP);
const void gfprintf(EMP_FILE fp, const char *str, ...);
const void gprintf(const char *str, ...);
const void gsprintf(INT8U *pstr, const char *str, ...);


#endif /* STR_DEBUGGER_H_ */
