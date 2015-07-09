/*
 *  strlen.c - The strlen() function finds the length of a string.
 *
 *  Function prototype: size_t strlen(const char *s, size_t maxlen)
 *
 *  Parameters:
 *  str -- This is the string whose length is to be found.
 *
 *  Return Value:  
 *   The strlen() function returns the number of characters that precede the
 *   terminating NUL character.  The strnlen() function returns either the
 *   same result as strlen() or maxlen, whichever is smaller.
 *
 *  Included in <string.h>
 *
 *  Author: Evan Dorn
 *  Created: 1/19/15
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
#include <string.h>
#endif


/*
 * C standard string function: get length of a string
 */
size_t strlen(const char *str) {

    size_t length = 0;
    while(str[length]) {
        length++;
    }
    
    return length;
}
