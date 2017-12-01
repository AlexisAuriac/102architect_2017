/*
** EPITECH PROJECT, 2017
** my_printf
** File description:
** Reproduces the behavior of the printf function.
*/

#include "my.h"

int my_printf(char *str, ...)
{
	int bytes = 0;
	format_id_t *fid;
	va_list ap;

	va_start(ap, str);
	for (int i = 0 ; str[i] ; i++, bytes++) {
		if (str[i] == '%') {
			fid = get_format_id(str, i + 1);
			if (fid->legit == 1) {
				display_fid(fid, ap, &bytes);
				i += fid->length;
			} else
				my_putchar('%');
			free(fid);
		} else
			my_putchar(str[i]);
	}
	va_end(ap);
	return (bytes);
}
