/*
** EPITECH PROJECT, 2021
** Be-Bop-A-Lula!
** File description:
** main
*/

#include "bistromatic.h"

static int valid_calc(char *str)
{
    int c = str[my_strlen(str) - 1];

    if (!(c <= '9' && c >= '0') && c != '(' && c != ')')
        return -1;
    for (int i = 0; str[i]; i++) {
        if (str[i] == '(' && str[i - 1] && (str[i - 1] <= '9'
            && str[i - 1] >= '0'))
            return -1;
        if (str[i] == ')' && str[i - 1] && (str[i + 1] <= '9'
            && str[i + 1] >= '0'))
            return -1;
        if ((str[i] == '(' && str[i - 1] && str[i + 1] == ')')
            || (str[i] == '/' && str[i + 1] && str[i + 1] == '0'))
            return -1;
        if (str[i] == '(' && str[i + 1] && (str[i + 1] == '+'
            || str[i + 1] == '/' || str[i + 1] == '*' || str[i + 1] == '%'))
            return -1;
    }
    return 0;
}

static int count_parent(char *str)
{
    int start = 0;
    int end = 0;

    for (int i = 0; str[i]; i++) {
        if (str[i] == '(')
            start++;
        if (str[i] == ')')
            end++;
        if (end > start)
            return -1;
    }
    if (start != end)
        return -1;
    return 0;
}

static int only_valid_crc(char *str)
{
    for (int i = 0; str[i]; i++) {
        if (!(str[i] <= '9' && str[i] >= '0') && str[i] != '+' && str[i] != '-'
            && str[i] != '*' && str[i] != '/' && str[i] != '%' && str[i] != '('
            && str[i] != ')')
            return -1;
    }
    for (int i = 0; str[i]; i++) {
        if ((!(str[i] <= '9' && str[i] >= '0') && str[i] != '('
            && str[i] != ')') && str[i + 1] && (!(str[i + 1] <= '9'
            && str[i + 1] >= '0') && str[i + 1] != '(' && str[i + 1] != ')'))
            return -1;
    }
    return 0;
}

static int error_handling(char *clc)
{
    if (only_valid_crc(clc) == -1) {
        write(2, "Invalid character.\n", 20);
        return -1;
    }
    if (count_parent(clc) == -1) {
        write(2, "Invalid counting parenthesis.\n", 31);
        return -1;
    }
    if (valid_calc(clc) == -1) {
        write(2, "Invalid calcul.\n", 17);
        return -1;
    }
    return 0;
}

int main_ev(char *clc)
{
    expr_t *expr = malloc(sizeof(expr_t));

    if (!expr)
        return 84;
    if (error_handling(clc) == -1)
        return 84;
    if (eval_expr(clc, expr) == 84)
        return 84;
    my_putstr(expr->result);
    free_all(expr, clc);
    return 0;
}
