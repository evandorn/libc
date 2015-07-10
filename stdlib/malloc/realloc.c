//
//  realloc.c
//  MemoryAllocator
//
//  Created by Evan Dorn on 3/24/15.
//  Copyright (c) 2015 Evan Dorn. All rights reserved.
//

/*
 *  realloc:
 *  The C library function realloc() attempts to resize the memory block
 *  pointed to by ptr that was previously allocated with a call to malloc or calloc.
 *
 *  Parameters:
 *  *ptr --  Pointer to a memory block previously allocated with malloc, calloc or realloc to be
 *            reallocated. If this is NULL, a new block is allocated and a 
 *            pointer to it is returned by the function.
 *
 *  size --  The new size for the memory block, in bytes. If it is 0 and
 *            points to an existing block of memory, the memory block pointed
 *            by ptr is deallocated and a NULL pointer is returned.
 *
 *  Return Value:
 *  realloc() retuns a pointer to the newly allocated memory, or NULL if the request fails
 *
 */

#include "malloc.h"

void *realloc(void *ptr, size_t size) {

    if (size == 0 || ptr == NULL) {
        return ptr;
    }
    
    char *p = ptr;
    char *save = NULL;
    char *new_ptr = NULL;
    
    p = p - sizeof(struct metadata);
    
    void *t = p;
    struct metadata *mdata = t;
    if(mdata->size >= size) {
        return ptr;
    }
    mdata->is_used = FREE;
    save = move_ptr(mdata, sizeof(struct metadata));
    new_ptr = malloc(size);
    for(size_t i = 0; i < mdata->size; i++) {
        new_ptr[i] = save[i];
    }
    return new_ptr;
}
