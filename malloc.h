#ifndef __MALLOC_H__
#define __MALLOC_H__

#include <stddef.h>
#include <inttypes.h>

/* Data Struct */
/**
 * struct mem_buffer_s - buffer to allocate
 *
 * @buf: buffer
 * @size: length of buffer
 * @prev_offset: previous location of memory chunk's head
 * @curr_offset: current location of memory chunk's head
 */
typedef struct mem_buffer_s
{
        char *buf;
        void *chunk;
        size_t size;
        uintptr_t prev_offset;
        uintptr_t curr_offset;
} mem_buffer_t;

/* Prototypes */
void *naive_malloc(size_t size);
void *_malloc(size_t size);
void _free(void *ptr);
#endif /*__MALLOC_H__*/
