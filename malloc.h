#ifndef _MALLOC_H_
#define _MALLOC_H_

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define BLOCK_SIZE sizeof(header_t)

/**
 * struct n_header_s - stores header data for each block
 * @total_bytes: total number of bytes allocated
*/
typedef struct n_header_s
{
	size_t total_bytes;
} n_header_t;

/**
 * struct header_s - stores header data for each block
 * @total_bytes: total number of bytes allocated
 * @used_bytes: number of bytes used
*/
typedef struct header_s
{
	size_t total_bytes;
	size_t used_bytes;
} header_t;

/**
 * struct heap_s - Struct for storing heap data
 * @first_block: pointer to first block of metadata
 * @heap_size: Total size of the heap in bytes
 * @heap_free: Amount of heap free to use in bytes
 * @total_blocks: The total number of blocks in the heap
*/
typedef struct heap_s
{
	header_t *first_block;
	size_t heap_size;
	size_t heap_free;
	size_t total_blocks;
} heap_t;

/**
 * struct n_heap_s - Struct for storing heap data
 * @first_block: pointer to first block of metadata
 * @heap_size: Total size of the heap in bytes
 * @heap_free: Amount of heap free to use in bytes
 * @total_blocks: The total number of blocks in the heap
*/
typedef struct n_heap_s
{
	n_header_t *first_block;
	size_t heap_size;
	size_t heap_free;
	size_t total_blocks;
} n_heap_t;

void *naive_malloc(size_t size);
header_t *n_move_block(size_t size);

void *_malloc(size_t size);
header_t *move_block(size_t size);

void _free(void *ptr);


#endif
