#include "malloc.h"

/**
 * _free - Function to free a piece of memory
 * @ptr: pointer to block of memory to free
*/
void _free(void *ptr)
{
	header_t *mem_block;

	if (ptr == NULL)
		return;
	mem_block = (header_t *)ptr;
	mem_block--;
	mem_block->used_bytes = 0;
}
