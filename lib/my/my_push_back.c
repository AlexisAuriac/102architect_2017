/*
** EPITECH PROJECT, 2017
** my_push_back
** File description:
** Adds a string or character at the end of a string.
*/

#include <stdlib.h>
#include "my.h"

char *my_push_back(char *str, char const cat)
{
	int new_len = 0;

	new_len = my_strlen(str) + 2;
	str = my_realloc(str, new_len);
	str[new_len - 2] = cat;
	return (str);
}

char *my_pushstr_back(char *str, char const *cat)
{
	int len_cat = 0;
	int new_len = 0;

	if (str == NULL)
		return (my_strdup(cat));
	if (cat != NULL) {
		len_cat = my_strlen(cat);
		new_len = my_strlen(str) + len_cat + 1;
		str = my_realloc(str, new_len);
		str = my_strcat(str, cat);
	}
	return (str);
}

char *my_insert_char(char *str, char const cat, int const pos)
{
	int initial_len = my_strlen(str);
	char *before = NULL;
	char *after = NULL;

	after = my_strdup(&str[pos]);
	str = my_revstr(str);
	before = my_strdup(&str[initial_len - pos]);
	before = my_revstr(before);
	free(str);
	str = NULL;
	str = my_pushstr_back(str, before);
	str = my_push_back(str, cat);
	str = my_pushstr_back(str, after);
	free(before);
	free(after);
	return (str);
}

char *my_insert_str(char *str, char const *cat, int const pos)
{
	int initial_len = my_strlen(str);
	char *before = NULL;
	char *after = NULL;

	if (str == NULL)
		return (my_strdup(cat));
	if (cat != NULL) {
		after =	my_strdup(&str[pos]);
		str = my_revstr(str);
		before = my_strdup(&str[initial_len - pos]);
		before = my_revstr(before);
		free(str);
		str = NULL;
		str = my_pushstr_back(str, before);
		str = my_pushstr_back(str, cat);
		str = my_pushstr_back(str, after);
		free(before);
		free(after);
	}
	return (str);
}
