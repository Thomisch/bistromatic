/*
** EPITECH PROJECT, 2021
** AlbanZink
** File description:
** my_strlen
*/

#include "my.h"

int my_strlen(char const *str)
{
    int carac = 0;

    for (; str[carac]; carac++);
    return (carac);
}
