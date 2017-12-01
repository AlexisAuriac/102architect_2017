/*
** EPITECH PROJECT, 2017
** my_str_isnum
** File description:
** Returns 1 if the string passed as parameter only contains digits and 0
** otherwise.
*/

#include "my.h"

static int my_rec_str_isnum(char const *str, int i)
{
	if (str[i] == '\0')
		return (1);
	if ((str[i] < '0' || str[i] > '9') && str[i] != '-')
		return (0);
	return (my_rec_str_isnum(str, i + 1));
}

int my_str_isnum(char const *str)
{
	int result = 0;

	if (str != NULL)
		result = my_rec_str_isnum(str, 0);
	return (result);
}
