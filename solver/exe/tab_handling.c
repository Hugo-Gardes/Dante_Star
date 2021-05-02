/*
** EPITECH PROJECT, 2020
** #code 29_03_2021
** File description:
** open_handling.c
*/

#include "../include/my.h"

char *open_read(char *path)
{
    struct stat stru_stat;
    if (stat(path, &stru_stat) == -1)
        exit(84);
    int fd = open(path, O_RDONLY);
    char *str = malloc(sizeof(char) * (stru_stat.st_size + 1));
    if (fd == -1)
        exit(84);
    read(fd, str, stru_stat.st_size);
    str[stru_stat.st_size] = '\0';
    if (strlen(str) < 4)
        exit(84);
    close(fd);
    return (str);
}

char **tab_create(char *path)
{
    char *str = open_read(path);
    char **tab = my_str_t_w_a(str, "\n");
    tab[0][0] = 'o';
    free(str);
    return (tab);
}

void print_tab(char **tab)
{
    for (int i = 0; tab[i]; i++)
        printf("%s\n", tab[i]);
}

void free_tab(char **tab)
{
    for (int i = 0; tab[i]; i++)
        free(tab[i]);
}

void reset_tab(char **tab)
{
    for (int y = 0; tab[y]; y++) {
        for (int x = 0; tab[y][x]; x++)
            if (tab[y][x] == 'p')
                tab[y][x] = 'o';
        for (int x = 0; tab[y][x]; x++)
            if (tab[y][x] == 'b')
                tab[y][x] = '*';
    }
}