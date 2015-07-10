//
//  lib_init.c
//  MemoryAllocator
//
//  Created by Evan Dorn on 3/24/15.
//  Copyright (c) 2015 Evan Dorn. All rights reserved.
//

#include "malloc.h"

static size_t remaining_size(struct metadata *data, size_t nb_pages);

/*
 *  Initialize the metadata struct
 */
struct metadata *init(struct metadata *data, size_t size, int position) {
    data->is_used = USED;
    data->position = position;
    data->size = align(size);
    data->next = move_ptr(data, sizeof(struct metadata) + align(size));
    return data;
}

/*
 *  Initialize next node in the struct
 */
struct metadata *init_next(struct metadata *data, size_t num_pages) {
    data->next->is_used = FREE;
    data->next->position = IN;
    data->next->previous = data;
    data->next->size = remaining_size(data->next, num_pages) - sizeof(struct metadata);
    data->next->next = NULL;
    return data;
}

/*
 *  Use first first algorithm for data structure
 */
struct metadata *first_fit(struct metadata *metadata_free, size_t size, int *new_) {
    struct metadata *current = metadata_free;
    size_t size_metadata = sizeof(struct metadata);
    while(current != NULL) {
        if(current->is_used == FREE) {
            if(current->next == NULL && current->size >= align(size) + size_metadata) {
                *new_ = 1;
                return current;
            }
            if(current->next != NULL && current->size >= size) {
                *new_ = 0;
                return current;
            }
        }
        current = current->next;
    }
    return NULL;
}

static size_t remaining_size(struct metadata *data, size_t num_pages) {
    size_t size = 0;
    struct metadata *current = metadata_free;
    while (current != data) {
        size += sizeof (struct metadata) + current->size;
        current = current->next;
    }
    return (num_pages * PAGE_SIZE) - size;
}