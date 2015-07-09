/*
 *  Included in <string.h>
 *
 *  Author: Evan Dorn
 *  Created: 2/13/15
 *
 */

#include <string.h>

static char *strtok_context;

/*
 *  The C library function strtok() tokenizes strings
 */
char *strtok(char *s, const char *delim) {
  return strtok_r(s, delim, &strtok_context);
}
