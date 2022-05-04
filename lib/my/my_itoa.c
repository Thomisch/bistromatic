/*
** EPITECH PROJECT, 2021
** AlbanZink
** File description:
** my_itoa
*/

#include "my.h"

char *my_itoa(long long int nb)
{
    int len = 0;
    char *str = NULL;
    int neg = (nb < 0) ? -1 : 1;

    nb *= neg;
    if (nb == 0)
        return ("0");
    for (int tmp = nb ; tmp > 0; ++len)
        tmp /= 10;
    str = malloc(sizeof(char) * (len + 1));
    str[len] = '\0';
    if (neg == -1)
        str[0] = '-';
    for (; len--; nb /= 10) {
        if (neg == -1)
            str[len + 1] = nb % 10  + '0';
        else
            str[len] = nb % 10  + '0';
    }
    return (str);
}
