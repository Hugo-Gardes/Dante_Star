/*
** EPITECH PROJECT, 2020
** #code 29_03_2021
** File description:
** str_to_word_array.h
*/

#ifndef __MY_STR_TO_WORD_ARRAY_H__
#define __MY_STR_TO_WORD_ARRAY_H__

int as_double(char *str, char const *comp);
char **set_tab(char **dest, char *src, int *size, char const *sep);
int match(char const *str, char const *sep, int size);
int ma(char const *str, char const *sep, int *size);
char **my_str_t_w_a(char *str, char const *sep);
int size_word(char *str, char const *sep);
int size_tab(char *s, char const *sep);

#endif