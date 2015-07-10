//
//  malloc.h
//  MemoryAllocator
//
//  Created by Evan Dorn on 3/24/15.
//  Copyright (c) 2015 Evan Dorn. All rights reserved.
//

#ifndef __MemoryAllocator__malloc__
#define __MemoryAllocator__malloc__

# define _BSD_SOURCE

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>
#include <fcntl.h>              // for open
#include <unistd.h>             // for close
#include <errno.h>

#include <sys/mman.h>

#include "helper_functions.h"
#include "lib_init.h"
#include "free.h"
#include "calloc.h"
#include "realloc.h"

#define PAGE_SIZE sysconf(_SC_PAGE_SIZE)
#define END 5
#define IN 4
#define BEGIN 3
#define USED 1
#define FREE 0

struct metadata {
    int position;
    int is_used;
    size_t size;
    struct metadata *next;
    struct metadata *previous;
};

extern struct metadata *metadata_free;

/* function prototypes */
void *malloc(size_t size);

#endif /* defined(__MemoryAllocator__malloc__) */
