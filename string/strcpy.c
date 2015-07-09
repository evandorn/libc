/*
 *  strcpy.c - The C library function char *strcpy(char *dest, const char *src) 
 *              copies the string pointed to by src to dest.
 *
 *  Function prototype: char *strcpy(char *dest, const char *src)
 *
 *  Parameters:
 *  str1 -- This is the first string to be compared.
 *
 *  str2 -- This is the second string to be compared.
 *
 *  Return Value: Return a pointer to the destination string dest.
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
 * Standard C string function: copy one string to another
 */
char *strcpy(char *dest, const char *src) {

    while(*src != '\0') {
        *dest = *src;
        dest++;
        src++;
    }
    *dest = '\0';                            // add the null terminator
    
    return dest;
}
