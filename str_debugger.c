/*
 * str_debugger.c
 *
 *  Created on: 29 Mar 2025
 *      Author: linax
 */



/*
 * string.c
 *
 *  Created on: 26/12/2011
 *      Author: Morten
 *  Updated by ChatGPT: 2025 — modern C and FILE conflict resolved
 */

#include "str_debugger.h"


/*void putc1(EMP_FILE *fp, unsigned char ch) {
  if ((uintptr_t)(*fp) < 0x20000000) { // It's a device (UART)
    put_file(*fp, ch);
    // put_queue(Q_LCD, ch, 1); // Optional
  } else {                             // It's a memory pointer
    **fp = ch;
    (*fp)++;
  }
}*/


void putc1(EMP_FILE *fp, unsigned char ch) {
  if (*fp < MAX_FILES && pof[*fp].put) {
    pof[*fp].put(ch);
  }
}

void putStr(EMP_FILE *fp, char *str) {
  while (*str)
    putc1(fp, *str++);
}

void putChars(EMP_FILE *fp, char *str, int len) {
  while (len--)
    putc1(fp, *str++);
}

void putDec(EMP_FILE *fp, long val, int sign, int size, char filler) {

    if (val == 0) {
      putc1(fp, '0');
      return;
    }
    if (val == 1) {
      putc1(fp, '1');
      return;
    }

long weight = 1, digit;
  int i;

  if (sign == NEGATIVE) {
    size--;
    if (filler == '0') {
      putc1(fp, '-');
      sign = POSITIVE;
    }
  }

  if (size == 0) {
    while (weight < val) {
      weight *= 10;
      size++;
    }
    size = size ? size : 1;
    weight /= 10;
  } else {
    i = size - 1;
    while (i-- > 0)
      weight *= 10;
  }

  while (size-- > 0) {
    digit = val / weight;
    if (digit == 0)
      putc1(fp, filler);
    else {
      if (sign == NEGATIVE) {
        putc1(fp, '-');
        sign = POSITIVE;
      }
      putc1(fp, digit + '0');
      filler = '0';
    }
    val %= weight;
    weight /= 10;
  }
}

void putHex(EMP_FILE *fp, long val, int size) {
  unsigned long weight = 1, digit;
  int i;

  if (size == 0)
    size = sizeof(long) * 2;

  i = size - 1;
  while (i-- > 0)
    weight *= 16;

  while (size-- > 0) {
    digit = val / weight;
    putc1(fp, (digit < 10) ? (digit + '0') : (digit + '7'));
    val %= weight;
    weight /= 16;
  }
}

const void gprint(EMP_FILE *fp, const char *str, va_list vaArgP) {
  long val;
  int i, done, size, len, sign, adjust = RIGHT;
  char *substr, preChar;

  while (*str) {
    i = 0;
    while (str[i] && str[i] != '%')
      i++;

    putChars(fp, (char *)str, i);
    str += i;

    if (*str == '%') {
      str++;
      size = 0;
      done = 0;
      preChar = ' ';

      while (!done) {
        switch (*str) {
          case '%':
            putc1(fp, '%');
            done = 1;
            break;
          case '-':
            adjust = LEFT;
            str++;
            break;
          case '0' ... '9':
            if (*str == '0' && size == 0)
              preChar = '0';
            size = size * 10 + (*str - '0');
            str++;
            break;
          case 'c':
            val = va_arg(vaArgP, int);
            putc1(fp, (char)val);
            done = 1;
            break;
          case 'd':
            val = va_arg(vaArgP, int);
            sign = (val < 0) ? NEGATIVE : POSITIVE;
            if (sign == NEGATIVE) val = -val;
            putDec(fp, val, sign, size, preChar);
            done = 1;
            break;
          case 'u':
            val = va_arg(vaArgP, unsigned int);
            putDec(fp, val, POSITIVE, size, preChar);
            done = 1;
            break;
          case 'x':
          case 'X':
          case 'p':
            val = va_arg(vaArgP, unsigned long);
            putHex(fp, val, size);
            done = 1;
            break;
          case 's':
            substr = va_arg(vaArgP, char *);
            len = 0;
            while (substr[len])
              len++;
            if (adjust == RIGHT)
              while (size-- > len)
                putc1(fp, ' ');
            putStr(fp, substr);
            if (adjust == LEFT)
              while (size-- > len)
                putc1(fp, ' ');
            done = 1;
            break;
          default:
            putStr(fp, "???");
            done = 1;
        }
        str++;
      }
    }
  }
}

const void gfprintf(EMP_FILE fp, const char *str, ...) {
  va_list vaArgP;
  va_start(vaArgP, str);
  gprint(&fp, str, vaArgP);
  va_end(vaArgP);
}
/*
const void gprintf(const char *str, ...) {
  va_list vaArgP;
  EMP_FILE std = (EMP_FILE)COM1; // UART
  va_start(vaArgP, str);
  gprint(&std, str, vaArgP);
  va_end(vaArgP);
}*/

const void gprint(EMP_FILE *fp, const char *str, va_list vaArgP);  // keep this
const void gprintf(const char *str, ...) {
    va_list vaArgP;
    EMP_FILE std = COM1;
    va_start(vaArgP, str);
    gprint(&std, str, vaArgP);
    va_end(vaArgP);
}


const void gsprintf(INT8U *pstr, const char *str, ...) {
  va_list vaArgP;
  va_start(vaArgP, str);
  gprint((EMP_FILE *)&pstr, str, vaArgP);
  putc1((EMP_FILE *)&pstr, '\0');
  va_end(vaArgP);
}

