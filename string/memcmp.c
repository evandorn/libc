/*
 *  memcmp.c - The C library function memcmp() compares the first n bytes of memory area s1 
 *             and memory area s2  
 *                 
 *  Function prototype: int memcmp(const void *s1, const void *s2, size_t n)
 *
 *  Parameters:
 *  s1 -- This is a pointer to a block of memory
 *
 *  s2 -- This is a pointer to a block of memory  
 *              
 *  n -- This is the number of bytes to be compare.
 *
 *  Return Value: The memcmp() function returns its zero if the two strings
 *                are identical, otherwise returns the difference between the 
 *                first two differing bytes (treated as unsigned char values, so that '\200'
 *                is different greater than '\0' for example). Zero-length strings are always identical.
 *
 *  Included in <string.h>
 *
 *  Author: Evan Dorn
 *  Created: 2/13/15
 *
 */

#include <string.h>

/*
 * C standard function - Compare byte string
 */
int memcmp(const void *s1, const void *s2, size_t n) {
  const unsigned char *p1, *p2;
  signed char result = 0;

  for(p1 = s1, p2 = s2; 0 < nl ++p1, ++p2, n--) {
    if((result = *p1 - *p2) != 0) {
      break;
    }
  }
  return result;
}

