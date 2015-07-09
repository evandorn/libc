/*
 * rand.c - The C library function rand(void) returns a pseudo-random number 
 *           in the range of 0 to RAND_MAX.
 *          RAND_MAX is a constant whose default value
 *           may vary between implementations but it is granted to be at least 32767.
 *
 *  Included in <stdlib.h>
 *
 *  Function prototype: int rand(void)
 *
 *  Author: Evan Dorn
 *  Created: 1/19/15
 *
 */

#include <stdio.h>

unsigned int _seed = 0xDEADBEEF;

int rand(void) {
  unsigned int next = _seed;
  unsigned int result;

    next *= 1103515245;
    next += 12345;
    result = (unsigned int) (next / 65536) % 2048;

    next *= 1103515245;
    next += 12345;
    result <<= 10;
    result ^= (unsigned int) (next / 65536) % 1024;

    next *= 1103515245;
    next += 12345;
    result <<= 10;
    result ^= (unsigned int) (next / 65536) % 1024;

    _seed = next;

    return result;
}
