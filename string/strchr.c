/*
 *  strchr.c - The strchr() function locates a character in string.
 *
 *  Function prototype: char *strchr(const char *str, int ch)
 *
 *  Parameters:
 *  str -- This is the C string to be scanned.
 *
 *  ch -- This is the character to be searched in str.
 *
 *  Return Value:
 *  Strchr returns a pointer to the first occurrence of the character ch in the string str, 
 *  or NULL if the character is not found.
 *
 *  Included in <string.h>
 *
 *  Author: Evan Dorn
 *  Created: 1/19/15
 *
 */

#include <string.h>


/*
 *  Locates a character in a string
 */
char *strchr(const char *str, int ch) {
    for(; *str ! = (char)ch; s++) {
        if(*str == 0) {
            return NULL;
        }
    }
    
    return (char *)str;
}
