/*
** EPITECH PROJECT, 2021
** Be-Bop-A-Lula!
** File description:
** clc
*/

#include "bistromatic.h"

char *my_add(expr_t *expr, int i)
{
    int j = 2;
    char *r;

    for (; expr->final_clc[i - j][0] == 'X'; j++);
    r = malloc(sizeof (char) * (my_strlen(expr->final_clc[i - j])
        + my_strlen(expr->final_clc[i - 1])));
    if (!r)
        return ("0");
    r = my_strcpy(r, infin_add(expr->final_clc[i - j],
        expr->final_clc[i - 1]));
    expr->final_clc[i - 1][0] = 'X';
    expr->final_clc[i - j][0] = 'X';
    return(r);
}

char *my_div(expr_t *expr, int i)
{
    int j = 2;
    char *r;

    for (; expr->final_clc[i - j][0] == 'X'; j++);
    r = malloc(sizeof (char) * (my_strlen(expr->final_clc[i - j])
        + my_strlen(expr->final_clc[i - 1])));
    if (!r)
        return ("0");
    r = my_strcpy(r, infin_div(expr->final_clc[i - j],
        expr->final_clc[i - 1]));
    expr->final_clc[i - 1][0] = 'X';
    expr->final_clc[i - j][0] = 'X';
    return(r);
}

char *my_mul(expr_t *expr, int i)
{
    int j = 2;
    char *r;

    for (; expr->final_clc[i - j][0] == 'X'; j++);
    r = malloc(sizeof (char) * (my_strlen(expr->final_clc[i - j])
        + my_strlen(expr->final_clc[i - 1])));
    if (!r)
        return ("0");
    r = my_strcpy(r, infin_mul(expr->final_clc[i - j],
        expr->final_clc[i - 1]));
    expr->final_clc[i - 1][0] = 'X';
    expr->final_clc[i - j][0] = 'X';
    return(r);
}

char *my_mod(expr_t *expr, int i)
{
    int j = 2;
    char *r;

    for (; expr->final_clc[i - j][0] == 'X'; j++);
    r = malloc(sizeof (char) * (my_strlen(expr->final_clc[i - j])
        + my_strlen(expr->final_clc[i - 1])));
    if (!r)
        return ("0");
    r = my_strcpy(r, infin_mod(expr->final_clc[i - j],
        expr->final_clc[i - 1]));
    expr->final_clc[i - 1][0] = 'X';
    expr->final_clc[i - j][0] = 'X';
    return(r);
}

char *my_sub(expr_t *expr, int i)
{
    int j = 2;

    for (; expr->final_clc[i - j][0] == 'X'; j++);
    return(infin_sub(expr->final_clc[i - j], expr->final_clc[i - 1]));
}
