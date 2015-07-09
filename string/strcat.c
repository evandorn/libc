/*
 *  strcat.c - The strcat() function append a copy of the null-terminated
 *             string s2 to the end of the null-terminated string s1, 
 *             then add a terminating `\0'. The string s1 must have 
 *             sufficient space to hold the result.
 *             The source and destination strings should not overlap,
 *             as the behavior is undefined.
 *
 *
 *  Function prototype: size_t strlen(const char *s, size_t maxlen)
 *
 *  Parameters:
 *  dest -- This is pointer to the destination array, which should contain a C string, 
 *          and be large enough to contain the concatenated resulting string.
 *
 *  src -- This is the string to be appended. This should not overlap destination.
 *
 *
 *  Return Value:   This function return a pointer to the resulting string dest.
 *
 *  Included in <string.h>
 *
 *  Author: Evan Dorn
 *  Created: 1/19/15
 *
 */

#include <string.h>

/*
 *  The strcat() function concatenates strings.
 */
char *strcat(char *dest, const char *src) {
    char *temp = dest;
    
    while(*dest) {
        dest++;
    }
    while((*dest++ = *src++) != 0);
    
    return temp;
}
