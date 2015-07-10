//
//  malloc.c
//  MemoryAllocator
//
//  Created by Evan Dorn on 3/24/15.
//  Copyright (c) 2015 Evan Dorn. All rights reserved.
//

/*
 *  malloc:
 *  takes in a given number of bytes and allocates space for them on the heap,
 *  then returns a pointer to them. If there isn't enough memory available,
 *  it returns a null pointer.
 *
 *  Parameters:
 *  size -- This is the size of elements.
 *
 *  Return Value:
 *  malloc() returns returns a pointer to the allocated memory, or NULL if *the request fails.
 *
 */

#include "malloc.h"

struct metadata *metadata_free = NULL;      // initialize free list to NULL

int fd;                                     // file discriptor for mmap
static int dev_zero_called = 0;

// private function prototypes
static void *first_page(size_t size, size_t page_size, size_t num_pages);
static void *new_page(size_t size, size_t page_size, size_t *nb_pages);
static void *existing_page(struct metadata *metadata, int new_metadata, size_t size, size_t nb_pages);

// When /dev/zero is memory-mapped, e.g., with mmap, to the virtual address space,
// it is equivalent to using anonymous memory; i.e. memory not connected to any file.
// by memory mapping /dev/zero in your mmap call it lets the OS know that the memory isn't
// associated with any particular file.
void dev_zero_init() {
    if(dev_zero_called == 1) {
        return;
    }
    fd = open("/dev/zero", O_RDWR);     // open /dev/zero and set the file descriptor
    dev_zero_called = 1;                // set the called flag to true
}

/*
 *  Malloc the first page of memory
 */
static void *first_page(size_t size, size_t page_size, size_t num_pages) {
    void *ptr;
    // Ask the OS to map a page of virtual memory initialized to zero.
    // mmap the first page.
    metadata_free = mmap(NULL, page_size, PROT_READ | PROT_WRITE | PROT_EXEC, MAP_PRIVATE | MAP_ANON, fd, 0);
    if(metadata_free == MAP_FAILED && (errno = ENOMEM)) {
        return NULL;
    }
    metadata_free->previous = NULL;
    metadata_free = init(metadata_free, size, BEGIN);
    metadata_free = init_next(metadata_free, num_pages);
    ptr = move_ptr(metadata_free, sizeof(struct metadata));
    return ptr;
}

/*
 *  Malloc a new page after the first page
 */
static void *new_page(size_t size, size_t page_size, size_t *nb_pages) {
    void *ptr;
    struct metadata *previous_page = get_last(metadata_free);
    struct metadata *new_alloced_page = NULL;
    *nb_pages = *nb_pages + 1;
    // Ask the OS to map a page of virtual memory initialized to zero.
    // mmap the first page. mmap a new page after the first page
    new_alloced_page = mmap(NULL, page_size, PROT_READ | PROT_WRITE | PROT_EXEC, MAP_PRIVATE | MAP_ANON, fd, 0);
    if(new_alloced_page == MAP_FAILED && (errno == ENOMEM)) {
        return NULL;
    }
    previous_page->next = new_alloced_page;
    previous_page->position = END;
    new_alloced_page = init(new_alloced_page, size, BEGIN);
    new_alloced_page->previous = previous_page;
    new_alloced_page = init_next(new_alloced_page, *nb_pages);
    ptr = move_ptr(new_alloced_page, sizeof(struct metadata));
    return ptr;
}

/*
 *  Reallocate over an existing page
 */
static void *existing_page(struct metadata *data, int new_metadata, size_t size, size_t nb_pages) {
    void *ptr;
    if(new_metadata) {
        data = init(data, size, IN);
        data = init_next(data, nb_pages);
    } else {
        data->is_used = USED;
    }
    ptr = move_ptr(data, sizeof(struct metadata));
    return ptr;
}

void *malloc(size_t size) {
    if(size == 0) {                         // erroneous call: Can't malloc nothing
        return NULL;
    }
    dev_zero_init();                        // initialize dev zero
    void *ptr;
    int new_metadata = 0;
    struct metadata *metadata;
    static size_t nb_pages = 1;
    size_t page_size = 0;
    // malloc hasn't been called yet
    if(metadata_free == NULL) {                                                      // allocate first page
        page_size = size_page(size, &nb_pages);
        ptr = first_page(size, page_size, nb_pages);
    }
    else if((metadata = first_fit(metadata_free, size, &new_metadata)) != NULL) {    // it's an existing page
        ptr = existing_page(metadata, new_metadata, size, nb_pages);
    } else {                                                                         // it's a new page
        page_size = size_page(size, &nb_pages);
        ptr = new_page(size, page_size, &nb_pages);
    }
    return ptr;
}
