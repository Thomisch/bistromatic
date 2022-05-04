/*
** EPITECH PROJECT, 2021
** bistromatic
** File description:
** infin div calc
*/

#include "../include/bistromatic.h"

void fill_power_of_two(char ***two, int i, char **result)
{
    char *r = "1";
    int j = 1;

    for (; j <= i; j++) {
        (*two)[j] = malloc(sizeof(char) * (my_strlen(infinmul(r, "2"))));
        (*two)[j] = infinmul(r, "2");
        r = infinmul(r, "2");
    }
    (*two)[j] = NULL;
}

void fill_world_of_nbr(char ***nb, char **two, int i, char *n2)
{
    char *tmp = NULL;

    for (int j = 0; j <= i; j++) {
        tmp = infinmul(two[i], n2);
        (*nb)[j] = malloc(sizeof(char) * (my_strlen(tmp + 1)));
        (*nb)[j] = infinmul(n2, two[i]);
    }
    (*nb)[i] = 'NULL';
}

char *egyptian_theorem(char **nbr, char **two, int i, char *nb1)
{
    char *result = my_strdup(two[i - 1]);
    char *cmp = my_strdup(nbr[i - 1]);

    if (my_strcmp(result, nb1) == 0)
        return result;
    if (my_strcmp(result, nb1) < 0)
        return "0";
    for (int j = i - 1; my_strcmp(cmp, nb1) < 0; j++) {
        cmp = infinadd(cmp, nbr[j - 1]);
        result = infinadd(result, two[j - 1]);
        if (my_strcmp(cmp, nb1) > 0) {
            cmp = calc_sub(cmp, nbr[j - 1], my_strlen(cmp));
            result = calc_sub(result, two[j - 1], my_strlen(result));
            return result;
        }
    }
    return result;
}

void print_array(char **array, char *str)
{
    for (int i = 0; array[i] != NULL; i++)
        printf("%s %s\n", str, array[i]);
}

int is_the_biggest_number(char *nb1, char *nb2)
{
    char *tmp1 = my_strdup(nb1);
    char *tmp2 = my_strdup(nb2);
    int a = 0;
    int b = 0;

    tmp1 = my_revstr(tmp1);
    tmp2 = my_revstr(tmp2);
    if (my_strlen(nb1) > my_strlen(nb2))
        return 1;
    for (int i = 0; tmp1[i] != '\0' && tmp2[i] != '\0'; i++) {
        if (tmp1[i] != tmp2[i]) {
            a = tmp1[i] - '0';
            b = tmp2[i] - '0';
            printf("a = %d b = %d\n", a, b);
            return b - a;
        }
    }
    return 0;
}

char *infindiv(char *nb1, char *nb2)
{
    char **world_of_two = NULL;
    char **world_of_nbr = NULL;
    char *result = "1";
    int i = 0;

    if (is_the_biggest_number(nb2, nb1) == 1) {
        return "0";
    }
    if (is_the_biggest_number(nb1, nb2) == 0) {
        return "1";
    }
    for (;is_the_biggest_number(infinmul(result, nb2), nb1) < 0; i++) {
        result = infinmul(result, "2");
    }
    result = "1";
    world_of_two = malloc(sizeof(char *) * (i + 1));
    world_of_nbr = malloc(sizeof(char *) * (i + 1));
    world_of_two[0] = result;
    fill_power_of_two(&world_of_two, i, &result);
    print_array(world_of_two, "world_of_two =");
    fill_world_of_nbr(&world_of_nbr, world_of_two, i, nb2);
    print_array(world_of_nbr, "world_of_nbr =");
    result = egyptian_theorem(world_of_nbr, world_of_two, i, nb1);
    return result;
}

void main()
{
    my_putstr(infindiv("93", "7"));
}