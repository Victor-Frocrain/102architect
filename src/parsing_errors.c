/*
** EPITECH PROJECT, 2018
** parsing_errors
** File description:
** parsing_errors
*/

#include "my.h"

void read_help(void)
{
    int fd = open("help", O_RDONLY);
    char *buff = malloc(sizeof(char) * 500);

    if (buff == NULL)
        exit(MY_EXIT_ERROR);
    memset(buff, 0, 500);
    read(fd, buff, 500);
    printf("%s\n", buff);
    free(buff);
    close(fd);
}

bool check_chars(char *str)
{
    for (int i = 0; str[i]; i++) {
        if ((str[i] < '0' || str[i] > '9') && str[i] != '-')
            return (true);
    }
    return (false);
}

bool check_arg_flags(char **av)
{
    if ((strcmp(av[0], "-t") == 0 || strcmp(av[0], "-z") == 0) &&
        (!av[1] || !av[2] || check_chars(av[1]) == true ||
        check_chars(av[2]) == true))
	return (true);
    if ((strcmp(av[0], "-r") == 0 || strcmp(av[0], "-s") == 0) &&
        (!av[1] || check_chars(av[1]) == true))
        return (true);
    return (false);
}

bool parse_error(int ac, char **av)
{
    if (ac == 2 && my_strcmp(av[1], "-h") == 0) {
        read_help();
        return (true);
    }
    for (int i = 1; av[i]; i++) {
        if (my_strcmp(av[i], "-t") != 0 && my_strcmp(av[i], "-z") != 0 &&
            my_strcmp(av[i], "-r") != 0 && my_strcmp(av[i], "-s") != 0 &&
            check_chars(av[i]) == true)
            return (true);
        if (check_arg_flags(av + i) == true)
            return (true);
    }
    if (ac < 5)
        return (true);
    return (false);
}
