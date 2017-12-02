/*
** EPITECH PROJECT, 2017
** my_ls
** File description:
** Tests the arguments to make sure they are valid.
*/

#include "include/my.h"

static int test_one(char **av, int *i)
{
	(*i)++;
	if (!my_str_isnum(av[*i]))
		return (0);
	return (1);
}

static int test_two(char **av, int *i)
{
	*i += 2;
	if (!my_str_isnum(av[*i]) || !my_str_isnum(av[*i - 1]))
		return (0);
	return (1);
}

int test_argv(int ac, char **av)
{
	int (*test)(char **, int *) = NULL;

	if (ac < 4)
		return (84);
	if (!my_str_isnum(av[1]) || !my_str_isnum(av[2]))
		return (84);
	for (int i = 3 ; av[i] ; i++) {
		if (my_strlen(av[i]) != 2 || av[i][0] != '-')
			return (84);
		if (av[i][1] == 'r' || av[i][1] == 's')
			test = &test_one;
		else if (av[i][1] == 't' || av[i][1] == 'h')
			test = &test_two;
		else
			return (84);
		if (!(*test)(av, &i))
			return (84);
	}
	return (0);
}
