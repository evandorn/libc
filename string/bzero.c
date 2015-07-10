/*
 *  NAME
 *  bzero -- write zeroes to a byte string
 *
 *  LIBRARY
 *  Standard C Library (libc, -lc)
 *
 *  SYNOPSIS
 *  #include <strings.h>
 *
 *  void bzero(void *s, size_t n);
 *
 *  DESCRIPTION
 *  The bzero() function writes n zeroed bytes to the string s.  If n is zero, bzero()
 *  does nothing.
 *
 *  SEE ALSO
 *  memset(3), swab(3)
 *
 */

void bzero(void *s, size_t n) {

    unsigned char *ptr = NULL;
    ptr = s;
    
    while(n > 0) {
        *ptr = 0;
        ptr++;
        n--;
    }
}
