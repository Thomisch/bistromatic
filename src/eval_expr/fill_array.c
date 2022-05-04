/*
** EPITECH PROJECT, 2021
** Be-Bop-A-Lula!
** File description:
** fill_array
*/

#include "bistromatic.h"

static void stock_in_array_bis(expr_t *expr, int i, int tmp_i, int j)
{
    if (expr->tmp[i + 1] && expr->tmp[i + 1] != 'X' && expr->tmp[i + 1] != 'O'
        && expr->tmp[i + 1] != 'F') {
        for (i += 1; expr->tmp[i] && (expr->tmp[i] >= '0'
            && expr->tmp[i] <= '9'); ++i, j++) {
            expr->final_clc[expr->i][j] = expr->tmp[i];
            expr->tmp[i] = 'X';
        }
        if (expr->final_clc[expr->i][0] != '\0')
            expr->i++;
        j = 0;
    }
    if (expr->tmp[tmp_i] != 'O' && expr->tmp[tmp_i] != 'F') {
        expr->final_clc[expr->i][0] = expr->tmp[tmp_i];
        expr->tmp[tmp_i] = 'X';
        expr->i++;
    }
}

static void stock_in_array(expr_t *ex, int i, int tmp_i, int j)
{
    if ((ex->tmp[i - 1] && ex->tmp[i - 1] != 'X') || i == 0) {
        for (i -= 1; i != 0 && (ex->tmp[i] >= '0' && ex->tmp[i] <= '9'); --i);
        if (ex->tmp[i] >= '0' && ex->tmp[i] <= '9')
            i--;
        if ((i == 0 || ex->tmp[i - 1] == 'F') && ex->tmp[i] == '-') {
            ex->final_clc[ex->i][j] = ex->tmp[i];
            ex->tmp[i] = 'X';
            j++;
        }
        for (i += 1; i < tmp_i; i++, j++) {
            ex->final_clc[ex->i][j] = ex->tmp[i];
            ex->tmp[i] = 'X';
        }
        ex->final_clc[ex->i][j] = '\0';
        if (ex->final_clc[ex->i][0] != '\0')
            ex->i++;
    }
    stock_in_array_bis(ex, i, tmp_i, 0);
}

void choice_piority(expr_t *expr)
{
    for (int i = 0; expr->tmp[i]; ++i) {
        if (expr->tmp[i] == '*' || expr->tmp[i] == '/'
            || expr->tmp[i] == '%')
            stock_in_array(expr, i, i, 0);
    }
    for (int i = 0; expr->tmp[i]; ++i) {
        if ((expr->tmp[i] == '-' && i != 0 && expr->tmp[i - 1] != 'F')
            || expr->tmp[i] == '+') {
            stock_in_array(expr, i, i, 0);
        }
    }
}

static void except(expr_t *ex, int i)
{
    int tmp_i = i;
    int j = 0;

    for (i -= 1; ex->clc[i] && (ex->clc[i] >= '0' && ex->clc[i] <= '9'); i--);
    if (ex->clc[i] == '-' && (i == 0 || ex->clc[i - 1] == '('))
        i--;
    for (i += 1; i != tmp_i + 1; i++, j++) {
        ex->tmp[j] = ex->clc[i];
        ex->clc[i] = 'X';
    }
    ex->tmp[j] = '\0';
    choice_piority(ex);
}

void stock_in_tmp(expr_t *expr, int i)
{
    int i_tmp = i;
    int j = 0;
    int excep = 0;

    for (; expr->clc[i] != '('; --i);
    expr->clc[i] = 'O';
    if (expr->clc[i - 1] && (expr->clc[i - 1] == '*' || expr->clc[i - 1] == '%'
        || expr->clc[i - 1] == '/'))
        excep = i - 1;
    for (i += 1; i != i_tmp; ++i) {
        for (; expr->clc[i] == 'X'; ++i);
        expr->tmp[j] = expr->clc[i];
        if (expr->clc[i] != 'O' || expr->clc[i] != 'F')
            expr->clc[i] = 'X';
        j++;
    }
    choice_piority(expr);
    if (excep != 0)
        except(expr, excep);
}
