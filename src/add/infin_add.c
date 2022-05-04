/*
** EPITECH PROJECT, 2021
** AlbanZink
** File description:
** infin_add
*/

#include "bistromatic.h"

static int infin_add_clc_bis(infin_add_t *addinf, int retenu, int i)
{
    if (retenu >= 1) {
        addinf->result[i] = '1';
        i++;
    }
    if (addinf->neg == 2) {
        addinf->result[i] = '-';
        i++;
    }
    return (i);
}

void infin_add_clc(infin_add_t *addinf)
{
    int i = 0;
    int retenu = 0;

    addinf->a = my_revstr(addinf->a);
    addinf->b = my_revstr(addinf->b);
    if (addinf->neg == 2) {
        addinf->a[my_strlen(addinf->a) -1] = '\0';
        addinf->b[my_strlen(addinf->b) -1] = '\0';
    }
    for (int add; addinf->b[i]; i++) {
        add = (addinf->a[i] - 48) + (addinf->b[i] - 48) + retenu;
        addinf->result[i] = (add % 10) + 48;
        retenu = add / 10;
    }
    for (int add; addinf->a[i]; i++) {
        add = addinf->a[i] - 48 + retenu;
        addinf->result[i] = (add % 10) + 48;
        retenu = add / 10;
    }
    i = infin_add_clc_bis(addinf, retenu, i);
    addinf->result = my_revstr(addinf->result);
    addinf->result[i] = '\0';
}

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

static void clear_struct(infin_add_t *addinf)
{
    free(addinf->a);
    free(addinf->b);
    free(addinf->result);
    free(addinf);
}

char *infin_add(char *a, char *b)
{
    infin_add_t *addinf = malloc(sizeof (infin_add_t));
    char *r = malloc(sizeof (char) * (my_strlen(a) + my_strlen(b)));

    addinf->neg = 0;
    if (!addinf || !r)
        return ("0");
    if (a[0] == '-')
        addinf->neg++;
    if (b[0] == '-')
        addinf->neg++;
    fill_struct(a, b, addinf);
    if (addinf->neg != 1)
        infin_add_clc(addinf);
    else
        infin_sub_clc(addinf);
    r = my_strcpy(r, addinf->result);
    clear_struct(addinf);
    return (r);
}
