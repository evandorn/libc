/*
 *  strstr.c - The C library function char *strstr(const char *s1, const char *s2)
 *             locates the first occurance of a substring inside of a string
 *
 *  Function prototype: char *strstr(const char *s1, const char *s2)
 *
 *  Parameters:
 *  s1 -- This is the input string to parse.
 *
 *  s1 -- This is the substring to search for.
 *
 *  Return Value: If s2 is an empty string, s1 is returned; if s2 occurs nowhere in s1, NULL is returned;
 *                otherwise a pointer to the first character of the first occurrence of s2 is returned.
 *
 *  Included in <string.h>
 *
 *  Author: Evan Dorn
 *  Created: 2/13/15
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
 * Standard C string function: locate a substring in a string
 */
char *strstr(const char *s1, const char *s2) {

  int len1;
  int len2;

  len2 = strlen(s2);               // length of the substring

  if(!len2) {
    return (char *)s1;           
  }

  len1 = strlen(s1);              // length of the input string

  while(len1 >= len2) {
    len1--;

    if(!memcmp(s1, s2, len2)) {
      return (char *)s1;
    }
    s1++;
  }

  return NULL;
}
