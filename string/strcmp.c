/*
 *  strcmp.c - The C library function int strcmp(const char *str1, const char *str2) compares the string 
 *             pointed to by str1 to the string pointed to by str2.
 *
 *   Parameters:
 *   str1 -- This is the first string to be compared.
 *   
 *  str2 -- This is the second string to be compared.
 *
 *  Return Value:
 *   if Return value < 0 then it indicates str1 is less than str2
 *
 *   if Return value > 0 then it indicates str1 is greater than str2
 *
 *   if Return value = 0 then it indicates str1 is equal to str2
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
 * Standard C string function: compare two strings and return their
 * sort order.
 */
int strcmp(const char *str1, const char *str2) {
    
    int result;
    
    while(1) {
        result = *str1 - *str2++;
        
        if((result != 0) || (*str1++ == 0)) {
            break;
        }
    }
    return result;
}
