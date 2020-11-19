/*
** EPITECH PROJECT, 2018
** test
** File description:
** test unitaire 102architect
*/

#include "my.h"
#include <criterion/criterion.h>
#include <criterion/redirect.h>

void redirect_all_std(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(architect, test01, .init = redirect_all_std)
{
    int ac = 6;
    char *av[6];

    av[0] = "./102architect";
    av[1] = "5";
    av[2] = "0";
    av[3] = "-t";
    av[4] = "-1";
    av[5] = "1";
    architect(ac, av);
    fflush(stdout);
    fflush(stderr);
    cr_assert_stdout_eq_str("Translation along vector \
(-1, 1)\n1.00\t0.00\t-1.00\n0.00\t1.00\t1.00\n0.00\t0.00\
\t1.00\n(5, 0) => (4.00, 1.00)\n");
}

Test(architect, test02, .init = redirect_all_std)
{
    int ac = 6;
    char *av[6];

    av[0] = "./102architect";
    av[1] = "2";
    av[2] = "2";
    av[3] = "-z";
    av[4] = "-1";
    av[5] = "1";
    architect(ac, av);
    fflush(stdout);
    fflush(stderr);
    cr_assert_stdout_eq_str("Scaling by factors -1 and 1\n\
-1.00\t0.00\t0.00\n0.00\t1.00\t0.00\n0.00\t0.00\t1.00\n\
(2, 2) => (-2.00, 2.00)\n");
}

Test(architect, test03, .init = redirect_all_std)
{
    int ac = 5;
    char *av[5];

    av[0] = "./102architect";
    av[1] = "1";
    av[2] = "0";
    av[3] = "-r";
    av[4] = "90";
    architect(ac, av);
    fflush(stdout);
    fflush(stderr);
    cr_assert_stdout_eq_str("Rotation by a 90 degree angle\n\
0.00\t-1.00\t0.00\n1.00\t0.00\t0.00\n0.00\t0.00\t1.00\n\
(1, 0) => (0.00, 1.00)\n");
}

Test(architect, test04, .init = redirect_all_std)
{
    int ac = 5;
    char *av[5];

    av[0] = "./102architect";
    av[1] = "3";
    av[2] = "-1";
    av[3] = "-s";
    av[4] = "270";
    architect(ac, av);
    fflush(stdout);
    fflush(stderr);
    cr_assert_stdout_eq_str("Reflection over an axis with an \
inclination angle of 270 degrees\n-1.00\t0.00\t0.00\n0.00\t\
1.00\t0.00\n0.00\t0.00\t1.00\n(3, -1) => (-3.00, -1.00)\n");
}

Test(architect, test05, .init = redirect_all_std)
{
    int ac = 13;
    char *av[13];

    av[0] = "./102architect";
    av[1] = "1";
    av[2] = "2";
    av[3] = "-t";
    av[4] = "2";
    av[5] = "3";
    av[6] = "-z";
    av[7] = "1";
    av[8] = "-2";
    av[9] = "-r";
    av[10] = "45";
    av[11] = "-s";
    av[12] = "30";
    architect(ac, av);
    fflush(stdout);
    fflush(stderr);
    cr_assert_stdout_eq_str("Translation along vector (2, 3)\n\
Scaling by factors 1 and -2\nRotation by a 45 degree angle\n\
Reflection over an axis with an inclination angle of 30 degrees\n\
0.97\t-0.52\t0.38\n0.26\t1.93\t6.31\n0.00\t0.00\t1.00\n\
(1, 2) => (0.31, 10.44)\n");
}
