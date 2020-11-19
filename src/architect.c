/*
** EPITECH PROJECT, 2018
** architect
** File description:
** architect
*/

#include "my.h"

void display_matrix(float **matrix)
{
    int k = 0;

    for (int j = 0; j != 3 || k != 2;) {
        if (j == 3)
            break;
        if (matrix[j][k] > -0.01 && matrix[j][k] < 0)
            matrix[j][k] *= -1;
        printf("%.2f", matrix[j][k]);
        if (k == 2 && j < 3) {
            printf("\n");
            j++;
            k = 0;
        }
        else if (k < 2) {
            printf("\t");
            k++;
        }
    }
}

int check_flags(char **av, float **matrix, base *coo)
{
    if (my_strcmp(av[0], "-z") == 0) {
        scale_vector(matrix, coo, av);
        return (2);
    }
    else if (my_strcmp(av[0], "-t") == 0) {
        translate_vector(matrix, coo, av);
        return (2);
    }
    else if (my_strcmp(av[0], "-r") == 0)
        rotate_vector(matrix, coo, av);
    else if (my_strcmp(av[0], "-s") == 0)
        reflect_matrix(matrix, coo, av);
    return (1);
}

int compute_matrix(char **av)
{
    int x = strtod(av[1], NULL);
    int y = strtod(av[2], NULL);
    float **matrix = malloc(sizeof(float *) * 4);
    base *coo = init_coordinates(coo, av);

    for (int j = 0; j < 4; j++) {
        matrix[j] = malloc(sizeof(float) * 4);
        init_matrix(matrix[j]);
    }
    matrix[2][2] = 1;
    for (int i = 0; av[i];) {
        i += check_flags(av + i, matrix, coo);
    }
    display_matrix(matrix);
    printf("(%d, %d) => (%.2f, %.2f)\n", x, y, coo->a, coo->b);
    free(matrix);
    free(coo);
}

int architect(int ac, char **av)
{
    if (parse_error(ac, av))
        return (MY_EXIT_ERROR);
    compute_matrix(av);
    return (MY_EXIT_SUCCESS);
}
