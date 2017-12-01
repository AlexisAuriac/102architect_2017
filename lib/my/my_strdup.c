/*
** EPITECH PROJECT, 2017
** my_strdup
** File description:
** Allocates memory and copies the string given as argument in it.
*/

#include "my.h"

char *my_strdup(char const *src)
{
	int len = my_strlen(src);
	char *dest = NULL;

	dest = my_malloc(len + 1);
	my_strcpy(dest, src);
	return (dest);
}
