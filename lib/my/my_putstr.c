/*
** EPITECH PROJECT, 2017
** my_putstr
** File description:
** Displays, one-by-one, the characters of a string
*/

#include <unistd.h>
#include "my.h"

int my_putstr(char const *str)
{
	int len = my_strlen(str);

	write(0, str, len);
	return (0);
}
