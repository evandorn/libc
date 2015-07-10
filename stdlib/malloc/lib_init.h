//
//  lib_init.h
//  MemoryAllocator
//
//  Created by Evan Dorn on 3/24/15.
//  Copyright (c) 2015 Evan Dorn. All rights reserved.
//

#ifndef __MemoryAllocator__lib_init__
#define __MemoryAllocator__lib_init__

/* function prototypes */
struct metadata *init(struct metadata *data, size_t size, int position);
struct metadata *init_next(struct metadata *data, size_t nb_pages);
struct metadata *first_fit(struct metadata *metadata_free, size_t size, int *new_);

#endif /* defined(__MemoryAllocator__lib_init__) */
