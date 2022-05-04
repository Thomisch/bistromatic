/*
** EPITECH PROJECT, 2021
** AlbanZink
** File description:
** infin_add
*/

#include "bistromatic.h"

static int infin_sub_clc_bis(infin_add_t *addinf, int retenu, int i, int n)
{

    for (int add; addinf->a[i]; i++) {
        add = addinf->a[i] - 48 + retenu;
        addinf->result[i] = (add % 10) + 48;
        retenu = add / 10;
    }
    if (retenu >= 1) {
        addinf->result[i] = '1';
        i++;
    }
    if (n == 1 && addinf->result[i - 1] != '0') {
        addinf->result[i] = '-';
        i++;
    }
    return (i);
}

void infin_sub_clc(infin_add_t *addinf)
{
    int i = 0;
    int retenu = 0;
    int n = 0;

    addinf->a = my_revstr(addinf->a);
    addinf->b = my_revstr(addinf->b);
    if (addinf->a[my_strlen(addinf->a) - 1] == '-') {
        addinf->a[my_strlen(addinf->a) - 1] = '\0';
        n = 1;
    }
    if (addinf->b[my_strlen(addinf->b) - 1] == '-')
        addinf->b[my_strlen(addinf->b) - 1] = '\0';
    for (int add; addinf->b[i]; i++) {
        add = (addinf->a[i] - 48) - (addinf->b[i] - 48) + retenu;
        addinf->result[i] = ((add + 10) % 10) + 48;
        retenu = add / 10;
    }
    i = infin_sub_clc_bis(addinf, retenu, i, n);
    addinf->result = my_revstr(addinf->result);
    addinf->result[i] = '\0';
}
