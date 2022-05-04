/*
** EPITECH PROJECT, 2021
** Be-Bop-A-Lula!
** File description:
** free_all
*/

#include "bistromatic.h"

void free_all(expr_t *expr, char *str)
{
    free(expr->clc);
    free(expr->tmp);
    for (int i = 0; i < my_strlen(str); ++i)
        free(expr->final_clc[i]);
    free(expr->final_clc);
    free(expr);
}