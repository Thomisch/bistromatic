/*
** EPITECH PROJECT, 2021
** AlbanZink
** File description:
** my_atoi
*/

#include "my.h"

long long int my_atoi(char *str)
{
    long long int res = 0;
    int sign = (str[0] == '-') ? -1 : 1;

    for (int i = (str[0] == '-') ? 1 : 0; str[i]; ++i) {
        if (str[i] >= '0' && str[i] <= '9') {
            res *= 10;
            res += str[i] - '0';
        } else
            return (res);
    }
    return (res * sign);
}
