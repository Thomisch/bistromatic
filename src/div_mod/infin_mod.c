/*
** EPITECH PROJECT, 2021
** bistromatic
** File description:
** infin modulo&div
*/

#include "../include/bistromatic.h"

char *infin_div(char *nb1, char *nb2)
{
    char *div_res = malloc(sizeof(char) * (my_strlen(nb1) + 1));

    long long int int_first = my_atoi(nb1);
    long long int int_second = my_atoi(nb2);
    long long int div_result = int_first / int_second;

    div_res = my_itoa(div_result);

    return(div_res);
}

char *infin_mod(char *nb1, char *nb2)
{
    char *div_res = malloc(sizeof(char) * (my_strlen(nb1) + 1));

    long long int int_first = my_atoi(nb1);
    long long int int_second = my_atoi(nb2);
    long long int div_result = int_first / int_second;
    long long int mod_result = int_first - (div_result * int_second);

    div_res = my_itoa(mod_result);

    return(div_res);
}
