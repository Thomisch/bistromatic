/*
** EPITECH PROJECT, 2021
** AlbanZink
** File description:
** infin_add
*/

#include "bistromatic.h"

int main(int ac, char **av)
{
    char *buff = malloc(sizeof (char) * my_atoi(av[3]));

    if (!buff)
        return 84;
    if (ac != 4)
        return 84;
    read(0, buff, my_atoi(av[3]));
    main_ev(buff);
    return 0;
}