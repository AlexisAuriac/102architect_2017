/*
** EPITECH PROJECT, 2017
** 102architect
** File description:
** Trasformations.c header file.
*/

#ifndef TRANSFORMATIONS_H
#define TRANSFORMATIONS_H

void multiplie_matx(double matx1[3][3], double matx2[3][3]);
void translation(double matx[3][3], double vector_x, double vector_y);
void homothety(double matx[3][3], double vector_x, double vector_y);
void rotation(double matx[3][3], double angle);
void symmetry(double matx[3][3], double angle);

#endif


