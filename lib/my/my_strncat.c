/*
** EPITECH PROJECT, 2017
** my_strcat
** File description:
** Concatenates two strings.
*/

#include "my.h"

char *my_strncat(char *dest, char const *src, int n)
{
	int dest_len = my_strlen(dest);
	int i;

	for (i = 0 ; i < dest_len && src[i] != '\0' ; i++)
		dest[dest_len + i] = src[i];
	dest[dest_len + i] = '\0';
	return (dest);
}
