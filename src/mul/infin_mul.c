/*
** EPITECH PROJECT, 2021
** bistromatic
** File description:
** infin mul
*/

#include "../include/bistromatic.h"

static char *set_str_mem_in(char *result, int len)
{
    for (int i = 0; i < len; i++)
        result[i] = 0;
    return result;
}

static char *zero_checker(char *result)
{
    int nbz_bn = 0;
    for (int i = 0; result[i] != '\0'; i++) {
        if (result[i] == '0')  {
            nbz_bn++;
        }
        else if (result[i + 1] != '0') {
            break;
        }
        break;
    }
    for (int j = 0; result[j] != '\0'; j++) {
        result[j] = result[j + nbz_bn];
    }
    return result;
}

static char *do_mul(char *result, char *nb1, char *nb2)
{
    int i = -1;
    int j = -1;

    while (nb1[++i] != 0 * (j = -1))
        while (nb2[++j] != 0) {
            result[i + j] += (nb2[j] - '0') * (nb1[i] - '0');
            result[i + j + 1] += result [i + j] / 10;
            result[i + j] = result[i + j] % 10;
        }
    i = -1;
    return result;
}

static char *infin_mul_clc(char *nb1, char *nb2)
{
    nb1 = my_revstr(nb1);
    nb2 = my_revstr(nb2);
    int len = my_strlen(nb1) + my_strlen(nb2) + 1;
    char *result = malloc(sizeof(char) * (len + 1));

    if (result == NULL)
        return (NULL);
    set_str_mem_in(result, len + 1);
    result = do_mul(result, nb1, nb2);
    for (int i = 0; i < len - 1; i++)
        result[i] = result[i] + '0';
    my_revstr(result);
    result[len - 1] = '\0';
    if (result[0] == '0')
        result = zero_checker(result);
    return result;
}

char *infin_mul(char *a, char *b)
{
    if (a >= b)
        return (infin_mul_clc(a, b));
    else
        return (infin_mul_clc(b, a));
}
