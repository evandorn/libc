/*
 * atoi.c - The C library function atoi() converts the string argument to an integer 
 *
 * included in <stdlib.h>
 *
 * Function Prototype: int atoi(const char *str)
 *
 * Author: Evan Dorn
 * Created: 1/19/15
 *
 */


/*
 * This file is shared between libc and the kernel, so don't put anything
 * in here that won't work in both contexts.
 */
#ifdef _KERNEL
#include <types.h>
#include <lib.h>
#else
#include <stdlib.h>
#include <string.h>
#endif


/*
 * Standard C function: parse a string that represents a decimal integer.
 * Leading whitespace is allowed. Trailing gunk is allowed too. Doesn't
 * really report syntax errors in any useful way.
 */

int atoi(const char *str) {

  static const char digits[] = "0123456789";         // legal digits for atoi() in order
  unsigned value = 0;                                // value we are accumulating
  int isNegative = 0;                                // set to true if value is negative

  // Skip over whitespace in the string
  while(*str == ' ' || *str == '\t') {
    str++;
  }

  // Check for value sign
  if(*str == '-') {
    isNegative = 1;                                 // it's a negative value
    str++;
  }
  else if(*str == '+') {
    str++;
  }

  // Process each digit
  while(*str) {
    const char *position;
    unsigned digit;

    // Look for the digit in the list of digits
    position = strchr(digits, *str);
    if(position == NULL) {
      // end of string; not a digit, so break.
      break;
    }
    // Put the index into the digit list, which is the value
    digit = (position - digits);

    // (Could check for overflow here)

    // Shift the number over and add in the new digit
    value = value * 10 + digit;

    // Look at the next character
    str++;
  }

  // Handle negative numbers
  if(isNegative) {
    return -(value);
  }

  return value;
}
