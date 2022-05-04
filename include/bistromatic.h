/*
** EPITECH PROJECT, 2021
** infin_add
** File description:
** infinite add calculator
*/

#ifndef BISTROMATIC_H_
    #define BISTROMATIC_H_

    #include "my.h"
    #include "eval_expr.h"
    #include "infin_add.h"

int my_strlen(char const *str);
int my_put_nbr(int nb);
int eval_expr(char *str, expr_t *expr);
char *my_strcpy(char *dest, char const *src);
long long int my_atoi(char *str);
char *my_itoa(long long int nb);
void free_all(expr_t *expr, char *str);
void choice_piority(expr_t *expr);
void stock_in_tmp(expr_t *expr, int i);
void choice_clc(expr_t *expr);
char *my_add(expr_t *expr, int i);
char *my_div(expr_t *expr, int i);
char *my_mul(expr_t *expr, int i);
char *my_mod(expr_t *expr, int i);
char *my_sub(expr_t *expr, int i);
char *subd(char *neg);
char *infin_sub(char *a, char *b);
char *infin_mul(char *a, char *b);
char *infin_div(char *nb1, char *nb2);
char *infin_mod(char *nb1, char *nb2);
char *infin_add(char *a, char *b);
void infin_sub_clc(infin_add_t *addinf);
void infin_add_clc(infin_add_t *addinf);
int main_ev(char *clc);

#endif
