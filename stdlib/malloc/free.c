//
//  free.c
//  MemoryAllocator
//
//  Created by Evan Dorn on 3/24/15.
//  Copyright (c) 2015 Evan Dorn. All rights reserved.
//

/*
 *  free:
 *  Put a block in the free list. Takes a pointer to
 *  a segment of memory allocated by malloc or calloc,
 *  and returns it for later use by the program or the operating system.
 *
 *  Parameters:
 *  *ptr -- Pointer to a memory block previously allocated with malloc, calloc or realloc to be 
 *           deallocated. If a null pointer is passed as argument, no action occurs.
 *
 *  Return Value:
 *  Free() does not return any value.
 */

#include "malloc.h"

/*
 *  Start of metadata
 */
static struct metadata *page_initial_metadata(struct metadata *mdata) {
    struct metadata *current = mdata;
    while(current != NULL) {
        if(current->position == BEGIN) {
            return current;
        }
        current = current->previous;
    }
    return NULL;
}

/*
 *  End of metadata
 */
static struct metadata *page_last_metadata(struct metadata *mdata) {
    struct metadata *current = mdata;
    while(current != NULL) {
        if(current->position == END) {
            return current;
        }
        if(current->is_used == FREE && current->next == NULL) {
            return current;
        }
        current = current->next;
    }
    return NULL;
}

static void free_page(struct metadata *first, struct metadata *last) {
    if(first != metadata_free) {
        first->previous->next = last->next;
        last->next->previous = first->previous;
    } else {
        metadata_free = last->next;
        metadata_free->previous = NULL;
    }
    munmap(first, PAGE_SIZE);                           // unmap the first page, when you’re done.
}

/*
 *  free up unused memory.
 */
static void free_unused_page(struct metadata *mdata) {
    struct metadata *first = page_initial_metadata(mdata);
    struct metadata *last = page_last_metadata(mdata);
    if(last->is_used == USED) {
        return;
    }
    struct metadata *current = first;
    while(current != last) {
        if(current->is_used == USED)  {         // if block is used do nothing
            return;
        }
        current = current->next;                // go to next block in the list
    }
    if(last->next == NULL) {                    // Last page in the list
        if(first != metadata_free) {
            first->previous->next = NULL;
        } else {
            metadata_free = NULL;
            munmap(first, PAGE_SIZE);           // unmap the first page to free it, when you’re done.
        }
    } else {
        free_page(first, last);                 // free up the pages
    }
}

void free(void *ptr) {
    if (ptr == NULL) {                             // Erroneous call: Can't call free on a null pointer
        return;
    }
    char *p = ptr;
    p = p - sizeof(struct metadata);
    void *t = p;
    struct metadata *mdata = t;
    if(mdata->is_used == USED) {
        mdata->is_used = FREE;
    }
    free_unused_page(mdata);
}
