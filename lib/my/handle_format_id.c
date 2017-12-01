/*
** EPITECH PROJECT, 2017
** my_printf
** File description:
** Contains functions that will handle the format_id structure.
*/

#include "my.h"

format_id_t *init_format_id(void)
{
	format_id_t *fid = malloc(sizeof(format_id_t));

	fid->legit = 0;
	fid->length = 1;
	for (int i = 0 ; i < 6 ; i++)
		fid->flags[i] = 0;
	fid->nb_flag = 0;
	fid->min_width = 0;
	fid->precision = 0;
	fid->type = 0;
	return (fid);
}
