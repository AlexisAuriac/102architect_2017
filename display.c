/*
** EPITECH PROJECT, 2017
** 102architect
** File description:
** Contains the functions that display the results of the program.
*/

#include <stdio.h>
#include "include/macro.h"
#include "include/struct.h"

void display_image(vector_t pos1, vector_t pos2)
{
	pos1.x = ABS_ZERO(pos1.x);
	pos1.y = ABS_ZERO(pos1.y);
	pos2.x = ABS_ZERO(pos2.x);
	pos2.y = ABS_ZERO(pos2.y);
	printf("(%.f,%.f) => (%.2f,%.2f)\n", pos1.x, pos1.y, pos2.x, pos2.y);
}

void display_matrix(double matrix[3][3])
{
	for (int i = 0; i < 3 ; i++) {
		printf("%-11.2f", ABS_ZERO(matrix[i][0]));
		printf("%-11.2f", ABS_ZERO(matrix[i][1]));
		printf("%.2f\n", ABS_ZERO(matrix[i][2]));
	}
}
