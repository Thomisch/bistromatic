/*
** EPITECH PROJECT, 2021
** AlbanZink
** File description:
** infin_add
*/

#ifndef INFIN_ADD_H_
    #define INFIN_ADD_H_

    #include <unistd.h>
    #include <stdlib.h>

    typedef struct infin_add_s {
        int neg;
        char *a;
        char *b;
        char *result;
        int a_len;
        int b_len;
    } infin_add_t;

#endif /* !INFIN_ADD_H_ */
