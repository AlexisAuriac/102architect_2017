/*
** EPITECH PROJECT, 2017
** my_printf
** File description:
** Contains the functions that get all the parts of the format identifiers.
*/

#include "my.h"

static char get_flag(char const *str, int const pos)
{
	switch (str[pos]) {
	case '-' :
		return ('-');
		break;
	case '0' :
		return ('0');
		break;
	case '+' :
		return ('+');
		break;
	case ' ' :
		return (' ');
		break;
	case '#' :
		return ('#');
		break;
	}
	return (0);
}

static int get_minimum_width(char const *str, int *pos)
{
	int min_width = 0;

	if (str[*pos] >= '0' && str[*pos] <= '9') {
		min_width = my_getnbr(&str[*pos]);
		min_width = ABS(min_width);
		(*pos) += find_power_10(min_width);
	}
	else if (str[*pos] == '*') {
		min_width = -1;
		(*pos)++;
	}
	return (min_width);
}

static int get_precision(char const *str, int *pos)
{
	int precision = 0;

	if (str[*pos] == '.') {
		(*pos)++;
		if (str[*pos] >= '0' && str[*pos] <= '9') {
			precision = my_getnbr(&str[*pos]);
			(*pos) += find_power_10(precision);
		}
		else if (str[*pos] == '*') {
			precision = -1;
			(*pos)++;
		}
		else
			precision = 0;
	}
	return (precision);
}

static format_id_t *get_type(format_id_t *fid, char const *str, int *pos)
{
	char const *handled_types = "dioxXucs%pmbS";

	for (int i = 0 ; handled_types[i] ; i++) {
		if (str[*pos] == handled_types[i]) {
			fid->legit = 1;
			fid->type = handled_types[i];
			(*pos)++;
			return (fid);
		}
	}
	return (fid);
}

format_id_t *get_format_id(char const *str, int pos)
{
	int pos_initial = pos;
	format_id_t *fid = init_format_id();

	while (get_flag(str, pos)) {
		if (!in_str(get_flag(str, pos), fid->flags)) {
			fid->flags[fid->nb_flag] = get_flag(str, pos);
			fid->nb_flag++;
		}
		pos++;
	}
	fid->min_width = get_minimum_width(str, &pos);
	fid->precision = get_precision(str, &pos);
	fid = get_type(fid, str, &pos);
	fid->length = pos - pos_initial;
	return (fid);
}
