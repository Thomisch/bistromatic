/*
** EPITECH PROJECT, 2021
** AlbanZink
** File description:
** my_revstr
*/

#include "my.h"

char *my_revstr(char *str)
{
    int b = my_strlen(str) - 1;
    int c;

    for (int a = 0; a < b; a++) {
        c = str[a];
        str[a] = str[b] ;
        str[b] = c;
        b--;
    }
    return (str);
}
