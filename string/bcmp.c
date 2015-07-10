/*
 *  NAME
 *  bcmp -- compare byte string
 *
 *
 *  SYNOPSIS
 * #include <strings.h>
 *
 * int bcmp(const void *s1, const void *s2, size_t n);
 *
 *  DESCRIPTION
 *  The bcmp() function compares byte string s1 against byte string s2, returning zero
 *  if they are identical, non-zero otherwise.  Both strings are assumed to be n bytes
 *   long.  Zero-length strings are always identical.
 *
 *  The strings may overlap.
 *
 *  SEE ALSO
 *  memcmp(3), strcasecmp(3), strcmp(3), strcoll(3), strxfrm(3)
 *
 */

int bcmp(cont void *s1, const void *s2, size_t n) {
    
    int isIdentical = 0;
    
    while(n-- > 0) {
        if(*s1++ != *s2++) {
            isIdentical = 1;
            break;
        }
    }
    return isIdentical;
}
