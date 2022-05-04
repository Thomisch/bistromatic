/*
** EPITECH PROJECT, 2021
** Be-Bop-A-Lula!
** File description:
** choice_clc
*/

#include "bistromatic.h"

static void choice_clc_bis(expr_t *expr, int i)
{
    if (expr->final_clc[i][0] == '-' && !(expr->final_clc[i][1] >= '0'
        && expr->final_clc[i][1] <= '9')) {
        expr->final_clc[i] = my_strcpy(expr->final_clc[i], my_sub(expr, i));
    }
}

void choice_clc(expr_t *ex)
{
    for (int i = 0; ex->final_clc[i]; i++) {
        if (ex->final_clc[i][0] == '+')
            ex->final_clc[i] = my_strcpy(ex->final_clc[i], my_add(ex, i));
        if (ex->final_clc[i][0] == '/')
            ex->final_clc[i] = my_strcpy(ex->final_clc[i], my_div(ex, i));
        if (ex->final_clc[i][0] == '*')
            ex->final_clc[i] = my_strcpy(ex->final_clc[i], my_mul(ex, i));
        if (ex->final_clc[i][0] == '%')
            ex->final_clc[i] = my_strcpy(ex->final_clc[i], my_mod(ex, i));
        choice_clc_bis(ex, i);
        ex->result = ex->final_clc[i];
    }
}