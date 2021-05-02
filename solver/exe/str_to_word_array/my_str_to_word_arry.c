/*
** EPITECH PROJECT, 2020
** B-CPE-110-MPL-1-1-BSQ-hugo.gardes
** File description:
** my_str_to_word_arry.c
*/

#include <stdlib.h>
#include "str_to_word_array.h"

int match(char const *str, char const *sep, int size)
{
    for (int u = 0; sep[u]; u++) {
        if (str[size] == sep[u])
            return (1);
    }
    return (-1);
}

int ma(char const *str, char const *sep, int *size)
{
    for (int u = 0; sep[u] && str[*size + 1]; u++) {
        if (str[*size] == str[*size + 1] && str[*size] == sep[u])
            return (1);
        if (*size - 1 >= 0 && str[*size] == str[*size - 1] && str[*size] == sep[u])
            return (1);
        if (str[*size] == sep[u] && str[*size - 1] != sep[u])
            return (1);
    }
    return (-1);
}

int size_tab(char *s, char const *sep)
{
    int u = 1;
    int size = 1;
    for (; s[u]; u++)
        if (ma(s, sep, &u) == 1)
            size++;
    if (match(s, sep, u - 1) == 1)
        s[u - 1] = 0;
    return (size);
}

int size_word(char *str, char const *sep)
{
    int size = 0;
    if (ma(str + size, sep, &size) == 1)
        size++;
    for (; str[size] && ma(str, sep, &size) == -1; size++);
    if (match(str, sep, size - 1) == 1 && str[size] == 0)
        str[size - 1] = 0;
    return (size);
}

char **my_str_t_w_a(char *str, char const *sep)
{
    int size_tab_ = size_tab(str, sep);
    int index = 0;
    char **tab = malloc(sizeof(char *) * (size_tab_ + 10));
    for (int i = 0; size_tab_ > i; i++){
        tab[i] = malloc(sizeof(char) * (size_word(str + index, sep) + 999));
        index += size_word(str + index, sep);
    }
    tab = set_tab(tab, str, &size_tab_, sep);
    return (tab);
}