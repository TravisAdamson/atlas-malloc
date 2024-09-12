#include "malloc.h"

static heap_t heap = {NULL, 0, 0, 0};

/**
 * _malloc - Allocates memory in the heap
 * @size: size of memory to allocate
 * Return: returns a pointer to the allocated memory
*/

void *naive_malloc(size_t size)
{
	static int flag;
	size_t aligned_sz = ((size + 7) / 8) * 8;
	header_t *ptr = NULL;

	if (!flag)
	{
		heap.first_block = sbrk(0);
		while (heap.heap_size < (aligned_sz + BLOCK_SIZE))
		{
			/*Sets end of heap address*/
			sbrk(getpagesize());
			heap.heap_size += getpagesize(), heap.heap_free += getpagesize();
		}
		/*Sets members of data struct*/
		heap.first_block->total_bytes = aligned_sz;
		heap.first_block->used_bytes = aligned_sz;
		heap.heap_free = heap.heap_size - (BLOCK_SIZE + aligned_sz);
		heap.total_blocks = 1;
		ptr = heap.first_block + 1;
		flag = 1;
		return ((void *) ptr);
	}
	/*When not enough free memory, allocates more*/
	while ((aligned_sz + BLOCK_SIZE) > heap.heap_free)
	{
		sbrk(getpagesize());
		heap.heap_size += getpagesize(), heap.heap_free += getpagesize();
	}
	/*Traversing Header Blocks and adjusting data structs*/
	ptr = move_block((BLOCK_SIZE + aligned_sz));
	heap.total_blocks++;
	heap.heap_free -= (BLOCK_SIZE + aligned_sz);
	return ((void *) ++ptr);
}


/**
 * move_block - Function for traversing the header blocks
 * @size: Size user requests plus block header
 * Return: pointer to big enough chunk for size
*/
header_t *move_block(size_t size)
{
	size_t iter = 0, total = 0, used = 0;
	header_t *current;

	for (current = heap.first_block; iter < heap.total_blocks; iter++)
	{
		if (current->total_bytes >= (size - BLOCK_SIZE) && !current->used_bytes)
			return (current);
		total = current->total_bytes;
		used = current->used_bytes;
		if (size <= (current->total_bytes - current->used_bytes))
		{
			current = (header_t *)((char *)current + sizeof(header_t) + total);
			current->total_bytes = total - used - BLOCK_SIZE;
			current->used_bytes = size - BLOCK_SIZE;
			return (current);
		}
		current = (header_t *)((char *)current + sizeof(header_t) + total);
	}
	current->total_bytes = size - BLOCK_SIZE;
	current->used_bytes = size - BLOCK_SIZE;
	return (current);
}
