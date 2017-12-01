/*
** EPITECH PROJECT, 2017
** my_printf
** File description:
** Contains functions that will create the string to display using the format
** identifier and arguments given.
*/

#include "my.h"

static char *put_var_showstr(char *str, va_list ap)
{
	char const *arg = va_arg(ap, char *);
	char *cat = NULL;

	for (int i = 0 ; arg[i] ; i++) {
		if (arg[i] < 32 || arg[i] >= 127) {
			cat = put_nbr_to_base(arg[i], "01234567");
			while (my_strlen(cat) < 3)
				cat = my_insert_char(cat, '0', 0);
			cat = my_insert_char(cat, '\\', 0);
			str = my_pushstr_back(str, cat);
			free(cat);
		} else
			str = my_push_back(str, arg[i]);
	}
	return (str);
}

static char *put_var(char *str, format_id_t *fid, va_list ap)
{
	char const *types_nbr = "dioxXubp";

	if (in_str(fid->type, types_nbr))
		str = put_var_nbr(str, fid, ap);
	switch (fid->type) {
	case 'c' :
		str = my_push_back(str, va_arg(ap, int));
		break;
	case 's' :
		str = my_pushstr_back(str, va_arg(ap, char *));
		break;
	case 'S' :
		str = put_var_showstr(str, ap);
		break;
	case '%' :
		str = my_push_back(str, '%');
		break;
	}
	return (str);
}

static char *put_spaces(char *str, format_id_t *fid, int min_width)
{
	char fill = ' ';
	char *cat = my_strdup("");

	min_width -= my_strlen(str);
	if (in_str('0', fid->flags))
		fill = '0';
	for (int i = 0 ; i < min_width ; i++)
		cat = my_push_back(cat, fill);
	if (in_str('-', fid->flags))
		str = my_pushstr_back(str, cat);
	else
		str = my_insert_str(str, cat, 1);
	free(cat);
	return (str);
}

char *put_precision(char *cat, format_id_t const *fid, va_list ap)
{
	int precision = fid->precision;

	if (precision == -1)
		precision = va_arg(ap, int);
	while (my_strlen(cat) < precision)
		cat = my_insert_char(cat, '0', 0);
	return (cat);
}

int display_fid(format_id_t *fid, va_list ap, int *bytes)
{
	char *str = NULL;
	int spaces = 0;

	if (fid->legit == 0)
		return (0);
	str = my_strdup("");
	if (fid->min_width == -1)
		spaces = va_arg(ap, int);
	else
		spaces = fid->min_width;
	str = put_var(str, fid, ap);
	str = put_spaces(str, fid, spaces);
	*bytes += my_strlen(str) - 1;
	my_putstr(str);
	free(str);
	return (0);
}
