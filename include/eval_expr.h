/*
** EPITECH PROJECT, 2021
** Be-Bop-A-Lula!
** File description:
** eval_expr
*/

#ifndef EVAL_EXPR_H_
    #define EVAL_EXPR_H_

    #include <unistd.h>
    #include <stdlib.h>

    typedef struct expr_s {
        char *clc;
        char *tmp;
        char **final_clc;
        int i;
        char *result;
    } expr_t;

#endif
