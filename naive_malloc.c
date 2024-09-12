#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <inttypes.h>
#include "malloc.h"

/**
 * align - check memory alignement
 *
 * @ptr: ptr to chunk to test
 *
 * Return: either the mem chunk unchanged or the aligned chunk
 */
uintptr_t align(uintptr_t ptr)
{
	if ((ptr % 2) == 0)
		return (ptr);
	return (ptr - 1);
}

/**
 * naive_malloc - simple version of malloc using sbrk
 *
 * @size: size to allocate
 *
 * Return: pointer to allocated chunk
 */
void *naive_malloc(size_t size)
{
	mem_buffer_t *mem;

	mem = NULL;

	mem->size = size + sizeof(size_t);
	mem->chunk = sbrk(mem->size);

	if (mem == (void *) -1)
		return (NULL);
	mem->curr_offset = mem->size;

	if (mem->size < size)
	{
		mem->prev_offset = mem->curr_offset;
		mem->size = size + sizeof(size_t);
		mem->chunk = sbrk(mem->size);

		if (mem == (void *) -1)
			return (NULL);

		mem->curr_offset = align(mem->size);
	}
	return (mem->chunk);
}
