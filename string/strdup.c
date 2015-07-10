/*
 *
 * Created by Evan Dorn on 7/10/15
 *
 * NAME
 *  strdup, strndup -- save a copy of a string
 *
 * SYNOPSIS
 *  #include <string.h>
 *
 * char *strdup(const char *s1);
 *
 * DESCRIPTION
 *  The strdup() function allocates sufficient memory for a copy of the string s1,
 *  does the copy, and returns a pointer to it.  The pointer may subsequently be used
 *  as an argument to the function free(3).
 *
 *  If insufficient memory is available, NULL is returned and errno is set to ENOMEM.
 *
 *  SEE ALSO
 *  free(3), malloc(3)
 *
 */

char *strdup(const char *s1) {
    
    char *result = (char *)malloc(strlen(s) + 1);
    if(result == (char *) 0) {
        return (char *)0;
    }
    strcpy(result, s1);
    return result;
}
