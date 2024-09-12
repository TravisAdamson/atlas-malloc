#include <unistd.h>
#include "malloc.h"

/**
 * _malloc - malloc created by me
 *
 * @size: size of chunk to allocate
 *
 * Return: a ptr to allocated chunk
 */
void *_malloc(size_t size)
{
	void *ptr;

	ptr = sbrk(size);
	if (ptr == (void *) - 1)
		return (NULL);
	else
		return (ptr);

	return (NULL);
}
