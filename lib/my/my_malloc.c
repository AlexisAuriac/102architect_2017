/*
** EPITECH PROJECT, 2017
** my_malloc
** File description:
**
*/

#include "my.h"

void *my_malloc(int size)
{
	char *result = malloc(sizeof(char) * size);

	if (result == NULL)
		exit(0);
	for (int i = 0 ; i < size ; i++) {
		result[i] = '\0';
	}
	return (result);
}
