/*
 *  memset.c - The memset() function writes len bytes of value c
 *                 (converted to an unsigned char) to the string b.
 *
 *  Function prototype: void *memset(void *str, int c, size_t n)
 *
 *  Parameters:
 *  b -- This is pointer to the block of memory to fill.
 *
 *  c -- This is the value to be set. The value is passed as 
 *       an int, but the function fills the block of memory using 
 *        the unsigned char conversion of this value. *
 *
 *  len -- This is the number of bytes to be set to the value.
 *
 *  Return Value: The memset() function returns its first argument.
 *
 *  Included in <string.h>
 *
 *  Author: Evan Dorn
 *  Created: 1/19/15
 *
 */

#include <string.h>

/*
 * C standard function - initialize a block of memory
 */
void *memset(void *b, int c, size_t len) {
    char *src;
    
    src = (char *)b;                    // Note: not required to typecast a void ptr. Unless dereferencing it.
    
    while(len--) {
        *src = c;
    }
    
    return b;                           // returns a pointer to the memory area b
}
