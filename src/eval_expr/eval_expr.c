/*
** EPITECH PROJECT, 2021
** Be-Bop-A-Lula!
** File description:
** eval_expr
*/

#include "bistromatic.h"

static int create_struct(expr_t *expr, char *str)
{
    expr->i = 0;
    expr->clc = malloc(sizeof(char) * (my_strlen(str) + 1));
    expr->tmp = malloc(sizeof(char) * (my_strlen(str) + 1));
    expr->result = malloc(sizeof(char) * (my_strlen(str) + 3));
    if (!expr->clc || !expr->tmp)
        return 84;
    expr->tmp[my_strlen(str)] = '\0';
    expr->clc = my_strcpy(expr->clc, str);
    expr->final_clc = malloc(sizeof(char *) * (my_strlen(str) + 1));
    if (!expr->final_clc)
        return 84;
    expr->final_clc[(my_strlen(str))] = NULL;
    for (int i = 0; i < my_strlen(str); i++) {
        expr->final_clc[i] = malloc(sizeof(char) * ((my_strlen(str) * 2) + 1));
        if (!expr->final_clc[i])
            return 84;
        expr->final_clc[i][(my_strlen(str) * 2)] = '\0';
    }
    return 0;
}

static void fill_array(expr_t *expr)
{
    int j = 0;

    for (int i = 0; expr->clc[i]; ++i) {
        if (expr->clc[i] == ')') {
            expr->clc[i] = 'F';
            stock_in_tmp(expr, i);
        }
    }
    for (int i = 0; expr->clc[i]; i++) {
        if (expr->clc[i] != 'X') {
            expr->tmp[j] = expr->clc[i];
            expr->clc[i] = 'X';
            j++;
        }
    }
    expr->tmp[j] = '\0';
    choice_piority(expr);
    expr->final_clc[expr->i] = NULL;
}

int eval_expr(char *str, expr_t *expr)
{
    if (!expr)
        return 84;
    if (create_struct(expr, str) == 84)
        return 84;
    fill_array(expr);
    choice_clc(expr);
    return 0;
}
