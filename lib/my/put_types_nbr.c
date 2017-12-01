/*
** EPITECH PROJECT, 2017
** my_printf
** File description:
** Contains functions to display types of numbers.
*/

#include "my.h"

static char *put_var_int(format_id_t const *fid, va_list ap)
{
	char *cat = 0;

	cat = int_str(va_arg(ap, int));
	cat = put_precision(cat, fid, ap);
	if (in_str('+', fid->flags) && cat[0] != '-')
		cat = my_insert_char(cat, '+', 0);
	if (in_str(' ', fid->flags) && cat[0] != '-' && cat[0] != '+')
		cat = my_insert_char(cat, ' ', 0);
	return (cat);
}

static char *put_var_oct(format_id_t const *fid, va_list ap)
{
	int arg = 0;
	char *cat = 0;

	arg = va_arg(ap, int);
	cat = put_nbr_to_base(ABS(arg), "01234567");
	cat = put_precision(cat, fid, ap);
	if (in_str('#', fid->flags))
		cat = my_insert_char(cat, '0', 0);
	return (cat);
}

static char *put_var_hex(format_id_t const *fid, va_list ap)
{
	long arg = 0;
	char *cat = 0;

	arg = va_arg(ap, long);
	if (fid->type == 'x' || fid->type == 'p') {
		cat = put_nbr_to_base(ABS(arg), "0123456789abcdef");
		cat = put_precision(cat, fid, ap);
		if (in_str('#', fid->flags) || fid->type == 'p')
			cat = my_insert_str(cat, "0x", 0);
	}
	else if (fid->type == 'X') {
		cat = put_nbr_to_base(ABS(arg), "0123456789ABCDEF");
		cat = put_precision(cat, fid, ap);
		if (in_str('#', fid->flags))
			cat = my_insert_str(cat, "0X", 0);
	}
	return (cat);
}

static char *put_var_unsigned(format_id_t const *fid, va_list ap)
{
	unsigned int arg = 0;
	char *cat = 0;

	arg = va_arg(ap, unsigned int);
	if (fid->type == 'u')
		cat = int_str(ABS(arg));
	if (fid->type == 'b')
		cat = put_nbr_to_base(ABS(arg), "01");
	cat = put_precision(cat, fid, ap);
	return (cat);
}

char *put_var_nbr(char *str, format_id_t const *fid, va_list ap)
{
	char *cat = 0;

	switch (fid->type) {
	case 'i' :
	case 'd' :
		cat = put_var_int(fid, ap);
		break;
	case 'o' :
		cat = put_var_oct(fid, ap);
		break;
	case 'p' :
	case 'x' :
	case 'X' :
		cat = put_var_hex(fid, ap);
		break;
	default :
		cat = put_var_unsigned(fid, ap);
	}
	str = my_pushstr_back(str, cat);
	free(cat);
	return (str);
}
