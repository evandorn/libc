//
//  helper_functions.h
//  MemoryAllocator
//
//  Created by Evan Dorn on 3/24/15.
//  Copyright (c) 2015 Evan Dorn. All rights reserved.
//

#ifndef __MemoryAllocator__helper_functions__
#define __MemoryAllocator__helper_functions__

/* function prototypes */
void my_bzero(void *s, size_t n);

void *my_memalloc(size_t size);

void my_memdelete(void **ptr);

void *move_ptr(void *src, int num_bytes);

size_t align(size_t size);

struct metadata *get_last(struct metadata *mdata);

size_t size_page(size_t size, size_t *num_pages);

size_t number_of_frees(struct metadata *metadata_free);

#endif /* defined(__MemoryAllocator__helper_functions__) */
