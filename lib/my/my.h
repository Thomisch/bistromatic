/*
** EPITECH PROJECT, 2021
** my_h
** File description:
** my_h
*/

#ifndef MY_H_
    #define MY_H_
    #include <stdlib.h>
    #include <stdio.h>
    #include <stddef.h>
    #include <unistd.h>

long long int my_atoi(char *str);
int my_getnbr(char *str);
char *my_itoa(long long int nb);
int my_put_nbr(int nb);
void my_putchar(char c);
void my_putstr(char const *str);
void my_puterrstr(char *str);
char *my_revstr(char *str);
int  my_str_isnum(char const *str);
int my_strcmp(char *s1, char const *s2);
char *my_strcpy(char *dest, char const *src);
char *my_strdup(char const *src);
int my_strlen(char const *str);

#endif
