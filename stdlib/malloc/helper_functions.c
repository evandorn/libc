//
//  helper_functions.c
//  MemoryAllocator
//
//  Created by Evan Dorn on 3/24/15.
//  Copyright (c) 2015 Evan Dorn. All rights reserved.
//

#include "malloc.h"

/*
 * my_bzero writes n zeroed bytes to the string s.
 * If n is zero, bzero() does nothing.
 *
 */
void my_bzero(void *s, size_t n) {
    unsigned char *ptr = NULL;
    ptr = s;
    
    while(n > 0) {
        *ptr = 0;
        ptr++;
        n--;
    }
}

/*
 *  Helper allocation function
 */
void *my_memalloc(size_t size) {
    void *ptr = NULL;
    ptr = 0;
    
    if(size == 0) {
        return NULL;
    } else {
        ptr = malloc(size);
        if(!ptr) {
            return NULL;
        } else {
            my_bzero(ptr, size);
            return ptr;
        }
    }
}

/*
 * Helper free function
 */
void my_memdelete(void **ptr) {
    if(*ptr && ptr) {
        free(*ptr);
        *ptr = NULL;
    }
}

/*
 *  Move a pointer by a number of bytes
 */
void *move_ptr(void *src, int num_bytes) {
    char *ptr = src;
    ptr += num_bytes;
    return ptr;
}

/*
 *  Align a block of memory
 */
size_t align(size_t size) {
    if(size % 8 == 0) {
        return size;
    }
    return ((size / sizeof(size_t)) + 1) * sizeof(size_t);
}

/*
 * Function to get the last of the metadata from the free list
 */
struct metadata *get_last(struct metadata *mdata) {
    struct metadata *current = mdata;
    while(current->next != NULL) {
        current = current->next;
    }
    return current;
}

/*
 *  Function to return size of a page
 */
size_t size_page(size_t size, size_t *num_pages) {
    size_t max_size = PAGE_SIZE - 2 * sizeof(struct metadata);
    if(size > max_size) {
        *num_pages = *num_pages + size / max_size;
        return(size / max_size + 1) * PAGE_SIZE;
    }
    return PAGE_SIZE;
}

/*
 *  Function ot return the total number of free blocks
 */
size_t number_of_frees(struct metadata *metadata_free) {
    struct metadata *current = metadata_free;
    int total_frees = 0;
    while(current != NULL) {
        if(current->is_used == FREE) {
            total_frees++;
        }
        current = current->next;
    }
    return total_frees;
}
