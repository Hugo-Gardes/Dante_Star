/*
** EPITECH PROJECT, 2020
** B-CPE-200-MPL-2-1-dante-hugo.frango
** File description:
** error_handling.c
*/

#include <my.h>

void error_handling(int argc, char **argv)
{
    char *str;
    char **tab;
    if (argc != 2)
        exit(84);
    str = open_read(argv[1]);
    for (int x = 0; str[x]; x++)
        if (str[x] != 'X' && str[x] != '\n' && str[x] != '*')
            exit(84);
    tab = my_str_t_w_a(str, "\n");
    for (int y = 1; tab[y]; y++)
        if (strlen(tab[y]) != strlen(tab[y - 1]))
            exit(84);
    free_tab(tab);
    free(str);
}