/*
** EPITECH PROJECT, 2017
** 102architect
** File description:
** Main file.
*/

#include <stdlib.h>
#include "include/struct.h"
#include "include/error_management.h"
#include "include/transformations.h"
#include "include/display.h"

void get_transf(vector_t pos, double matx[3][3], char **av)
{
	int i = 3;

	while (av[i]) {
		switch (av[i][1]) {
		case 't' :
			translation(matx, atof(av[i + 1]), atof(av[i + 2]));
			i += 3;
			break;
		case 'h' :
			homothety(matx, atof(av[i + 1]), atof(av[i + 2]));
			i += 3;
			break;
		case 'r' :
			rotation(matx, atof(av[i + 1]));
			i += 2;
			break;
		case 's' :
			symmetry(matx, atof(av[i + 1]));
			i += 2;
		}
	}
}

vector_t get_image(vector_t pos_init, double matx[3][3])
{
	vector_t pos_image = {0, 0};

	pos_image.x += pos_init.x * matx[0][0];
	pos_image.x += pos_init.y * matx[0][1];
	pos_image.x += matx[0][2];
	pos_image.y += pos_init.x * matx[1][0];
	pos_image.y += pos_init.y * matx[1][1];
	pos_image.y += matx[1][2];
	return (pos_image);
}

int main(int ac, char **av)
{
	vector_t pos_init = {0};
	vector_t pos_image = {0};
	double matx[3][3] = {{1, 0, 0}, {0, 1, 0}, {0, 0, 1}};

	if (test_argv(ac, av) == 84)
		return (84);
	pos_init.x = atof(av[1]);
	pos_init.y = atof(av[2]);
	get_transf(pos_init, matx, av);
	pos_image = get_image(pos_init, matx);
	display_matrix(matx);
	display_image(pos_init, pos_image);
	return (0);
}
