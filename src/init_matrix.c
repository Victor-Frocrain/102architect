/*
** EPITECH PROJECT, 2018
** inti_matrix
** File description:
** init_matrix
*/

#include "my.h"

void init_matrix(float *matrix)
{
    for (int i = 0; i < 3; i++)
        matrix[i] = 0;
}

base *init_coordinates(base *coo, char **av)
{
    coo = malloc(sizeof(base));
    coo->a = strtof(av[1], NULL);
    coo->b = strtof(av[2], NULL);
}
