/*
** EPITECH PROJECT, 2021
** my_putstr
** File description:
** c pool day 4
*/

#include "my.h"

void my_putstr(char const *str)
{
    write(1, str, my_strlen(str));
}

void my_puterrstr(char *str)
{
    write(2, str, my_strlen(str));
}
