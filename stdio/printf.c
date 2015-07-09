/*
 * printf.c - The C library function printf() sends formatted output to stdout
 *
 * included in <stdio.h>
 *
 * Function Prototype: int printf(const char *format, ...)
 *
 * Parameters: format -- This is the string that contains the text to be written to stdout.It can optionally
 *                       contain embedded format tags that are replaced by the values specified in subsequent 
 *                       additional arguments and formatted as requested. Format tags prototype is %[flags]
 *                       [width][.precision][length]specifier, 
 *
 * Return Value:
 *  If successful, the total number of characters written is returned.
 *  On failure, a negative number is returned.
 *
 * Author: Evan Dorn
 * Created: 1/19/15
 *
 */

#include <stdio.h>
#include <stdarg.h>     // for type va_list


/*
 * printf - C Standard I/O function that prints a string to stdout. 
 */


/*
 *  Function passed to __vprintf to preform the actual output to stdout
 */
static void __printf_send(void *mydata, const char *data, size_t len) {
    (void)mydata;       // not needed
    
    for(unsigned int i = 0; i < len; i++) {
        putchar(data[i]);
    }
}

/*
 *  printf: send the result to vprintf for output
 */
int printf(const char *format, ...) {
    int chars;
    va_list args;
    va_start(format, args);
    va_end(args);
    return chars;
}

/*
 * vprintf: call __vprintf() to do everything
 *          Note: va_list = variable argument list
 */
int vprintf(const char *format, va_list args) {
    return __vprintf(__printf_send, NULL, format, args);
}
