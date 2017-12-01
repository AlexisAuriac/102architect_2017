/*
** EPITECH PROJECT, 2017
** 102architect
** File description:
** Contains functions that perform geometric transformations to a matrix.
*/

#include <stdio.h>
#include <math.h>
#include "include/macro.h"
#include "include/struct.h"

void multiplie_matx(double matx1[3][3], double matx2[3][3])
{
	double result[3][3] = {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}};

	for (int i = 0 ; i < 3 ; i++) {
		for (int j = 0 ; j < 3 ; j++) {
			for (int k = 0 ; k < 3 ; k++)
				result[i][j] += matx1[k][j] * matx2[i][k];
		}
	}
	for (int i = 0 ; i < 3 ; i++) {
		for (int j = 0 ; j < 3 ; j++)
			matx1[i][j] = result[i][j];
	}
}

void translation(double matx[3][3], double vector_x, double vector_y)
{
	double matx_trans[3][3] = {{1, 0, 0}, {0, 1, 0}, {0, 0, 1}};

	matx_trans[0][2] = vector_x;
	matx_trans[1][2] = vector_y;
	multiplie_matx(matx, matx_trans);
	vector_x = ABS_ZERO(vector_x);
	vector_y = ABS_ZERO(vector_y);
	printf("Translation by the vector (%.f, %.f)\n", vector_x, vector_y);
}

void homothety(double matx[3][3], double vector_x, double vector_y)
{
	double matx_homo[3][3] = {{1, 0, 0}, {0, 1, 0}, {0, 0, 1}};

	matx_homo[0][0] = vector_x;
	matx_homo[1][1] = vector_y;
	multiplie_matx(matx, matx_homo);
	vector_x = ABS_ZERO(vector_x);
	vector_y = ABS_ZERO(vector_y);
	printf("Homothety by the ratios %.f and %.f\n", vector_x, vector_y);
}

void rotation(double matx[3][3], double angle)
{
	double matx_rot[3][3] = {{1, 0, 0}, {0, 1, 0}, {0, 0, 1}};

	angle = RAD(angle);
	matx_rot[0][0] = cos(angle);
	matx_rot[0][1] = -sin(angle);
	matx_rot[1][0] = sin(angle);
	matx_rot[1][1] = cos(angle);
	multiplie_matx(matx, matx_rot);
	angle = ABS_ZERO(angle);
	printf("Rotation at a %.f degree angle\n", DEGREE(angle));
}

void symmetry(double matx[3][3], double angle)
{
	double matx_sym[3][3] = {{1, 0, 0}, {0, 1, 0}, {0, 0, 1}};

	angle = RAD(angle);
	matx_sym[0][0] = cos(2 * angle);
	matx_sym[0][1] = sin(2 * angle);
	matx_sym[1][0] = sin(2 * angle);
	matx_sym[1][1] = -cos(2 * angle);
	multiplie_matx(matx, matx_sym);
	angle =	ABS_ZERO(angle);
	printf("Symmetry about an axis inclined with an angle of ");
	printf("%.f degrees\n", DEGREE(angle));
}
