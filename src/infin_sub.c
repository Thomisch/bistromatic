/*
** EPITECH PROJECT, 2021
** infinadd
** File description:
** sub part
*/

#include "bistromatic.h"

static void fill_struct(char *a, char *b, infin_add_t *addinf)
{
    addinf->a_len = my_strlen(a);
    addinf->b_len = my_strlen(b);
    if (a[0] == '-')
        addinf->a_len--;
    if (b[0] == '-')
        addinf->b_len--;
    if (addinf->a_len >= addinf->b_len) {
        addinf->a = malloc(sizeof (char) * (addinf->a_len) + 1);
        addinf->a = my_strcpy(addinf->a, a);
        addinf->b = malloc(sizeof (char) * (addinf->b_len) + 1);
        addinf->b = my_strcpy(addinf->b, b);
        addinf->result = malloc(sizeof (char) * (addinf->a_len) + 3);
    } else if (addinf->a_len < addinf->b_len) {
        addinf->a = malloc(sizeof (char) * (addinf->b_len) + 1);
        addinf->a = my_strcpy(addinf->a, b);
        addinf->b = malloc(sizeof (char) * (addinf->a_len) + 1);
        addinf->b = my_strcpy(addinf->b, a);
        addinf->result = malloc(sizeof (char) * (addinf->b_len) + 3);
    }
}

char *infin_sub(char *a, char *b)
{
    infin_add_t *addinf = malloc(sizeof (infin_add_t));

    addinf->neg = 0;
    if (a[0] == '-')
        addinf->neg++;
    if (b[0] == '-')
        addinf->neg++;
    fill_struct(a, b, addinf);
    addinf->result = my_itoa(my_atoi(a) - my_atoi(b));
    return (addinf->result);
}