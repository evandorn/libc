//
//  calloc.c
//  MemoryAllocator
//
//  Created by Evan Dorn on 3/24/15.
//  Copyright (c) 2015 Evan Dorn. All rights reserved.
//

/*
 *  calloc.c:
 *  The C library function calloc() allocates the requested memory and returns a pointer to it.
 *  The difference in malloc and calloc is that calloc sets allocated memory to zero,
 *  where as malloc does not.
 *
 *  Parameters:
 *  count -- This is the number of elements to be allocated.
 *  size -- This is the size of elements.
 *
 *  Return Value:
 *  Calloc() returns a pointer to the allocated memory, or NULL if the request fails.
 *
 */

#include "malloc.h"

void *calloc(size_t count, size_t size) {
    // error checking
    if(count == 0 || size == 0) {
        return NULL;
    }
    void *memory_result = NULL;
    
    // use malloc to get the memory
    memory_result = malloc(count * size);
    
    // clear the memory on successful allocation
    if(memory_result != NULL) {
        memset(memory_result, 0x00, count * size);
    }
    
    // return the resulting memory
    return memory_result;
}
