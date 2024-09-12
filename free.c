#include <stdio.h>
#include "malloc.h"

/**
 * _free - created by me
 *
 * @ptr: pointer to allocated chunk to free
 *
 * Return: nothing
 */
void _free(void *ptr)
{
	ptr = NULL;
	printf("%p\n", ptr);

}
