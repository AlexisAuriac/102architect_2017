/*
** EPITECH PROJECT, 2017
** in_str
** File description:
** Tests if char is in str and returns its position.
*/

#include "my.h"

int in_str(char const c, char const *str)
{
	for (int i = 0 ; str[i] ; i++) {
		if (c == str[i])
			return (i + 1);
	}
	return (0);
}
