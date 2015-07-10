/*
 *   Created by Evan Dorn on 7/10/15
 *
 *   NAME
 *    strrchr -- return pointer to last occurance of a character
 *
 *  SYNOPSIS
 *    char *strrchr (const char *s, int c)
 *
 *  DESCRIPTION
 * 	 Returns a pointer to the last occurance of character C in
 * 	 string S, or a NULL pointer if no occurance is found.
 *
 *
 */

char *strrchr(register const char *s, int c) {
    
    char *rtchar = 0;
    
    do {
        if(*s == c) {
            rtchar = (char *)s;
        } while(*s++);
    }
    return rtchar;
}
