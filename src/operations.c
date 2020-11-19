/*
** EPITECH PROJECT, 2018
** operations
** File description:
** operations
*/

#include "my.h"

void translate_vector(float **matrix, base *coo, char **av)
{
    float a = strtof(av[1], NULL);
    float b = strtof(av[2], NULL);

    printf("Translation along vector (%.0f, %.0f)\n", a, b);
    matrix[0][0] += 1;
    matrix[1][1] += 1;
    matrix[0][2] += a;
    matrix[1][2] += b;
    coo->a += matrix[0][2];
    coo->b += matrix[1][2];
}

void scale_vector(float **matrix, base *coo, char **av)
{
    float a = strtof(av[1], NULL);
    float b = strtof(av[2], NULL);

    printf("Scaling by factors %.0f and %.0f\n", a, b);
    matrix[0][0] += a;
    matrix[1][1] += b;
    coo->a *= matrix[0][0];
    coo->b *= matrix[1][1];
}

void rotate_vector(float **matrix, base *coo, char **av)
{
    float a = strtof(av[1], NULL);

    printf("Rotation by a %.0f degree angle\n", a);
    matrix[0][0] += cosf(a * M_PI / 180);
    matrix[0][1] += sinf(a * M_PI / 180) * (-1);
    matrix[1][0] += sinf(a * M_PI / 180);
    matrix[1][1] += cosf(a * M_PI / 180);
    coo->a += matrix[0][0] + matrix[0][1];
    coo->b += matrix[1][0] + matrix[1][1];
}

void reflect_matrix(float **matrix, base *coo, char **av)
{
    float a = strtof(av[1], NULL);

    printf("Reflection over an axis with an \
inclination angle of %.0f degrees\n", a);
    matrix[0][0] += cosf(2 * a * M_PI / 180);
    matrix[0][1] += sinf(2 * a * M_PI / 180);
    matrix[1][0] += sinf(2 * a * M_PI / 180);
    matrix[1][1] += cosf(2 * a * M_PI / 180) * (-1);
    coo->a *= (matrix[0][0] + matrix[0][1]);
    coo->b *= (matrix[1][0] + matrix[1][1]);
}
