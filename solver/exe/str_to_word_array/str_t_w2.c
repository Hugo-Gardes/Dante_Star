/*
** EPITECH PROJECT, 2020
** B-PSU-101-MPL-1-1-minishell1-hugo.gardes
** File description:
** str_t_w2.c
*/

#include "str_to_word_array.h"

int as_double(char *str, char const *comp)
{
    int dooble = 0;
    for (int y = 0; str[y + 1]; y++)
        if (str[y] == str[y + 1] && match(str, comp, y) == 1)
            dooble++;
    return (dooble);
}

char **set_tab(char **dest, char *src, int *size, char const *sep)
{
    int pos = 0;
    int siz = 0;
    int u = 0;
    int save_size = *size;

    for (; src[pos] && ma(&src[pos], sep, &siz) == 1; pos++);
    for (; *size; *size -= 1) {
        for (u = 0; src[pos] && ma(src + pos, sep, &siz) == -1; pos++, u++) {
            dest[save_size - *size][u] = src[pos];
            dest[save_size - *size][u + 1] = 0;
        }
        if (match(src, sep, pos) == 1 && match(src, sep, pos - 1) == 1)
            save_size--;
        pos++;
    }
    dest[save_size - *size] = 0;
    return (dest);
}