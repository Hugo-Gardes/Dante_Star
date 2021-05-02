/*
** EPITECH PROJECT, 2020
** B-CPE-200-MPL-2-1-dante-hugo.frango
** File description:
** gest_tabèint.c
*/

#include "my.h"

void print_tab_int(int **tab, int sizemax_x, int sizemax_y)
{
    for (int i = 0; i < sizemax_y; i++) {
        for (int j = 0; j < sizemax_x; j++) {
            if (tab[i][j] == 'X')
                textcolor(BRIGHT, RED, HIDDEN);
            else if (tab[i][j] == 'o')
                textcolor(BRIGHT, GREEN, HIDDEN);
            else
                textcolor(BRIGHT, BLACK, HIDDEN);
            printf("%c", tab[i][j]);
            textcolor(RESET, WHITE, HIDDEN);
        }
        printf("\n");
        fflush(stdout);
    }
}

void free_tab_int(int **tab, int sizemax_y)
{
    for (int i = 0; i < sizemax_y; i++)
        free(tab[i]);
    free(tab);
}

int **make_int_tab(char **map, int sizemax_x, int sizemax_y)
{
    int **tab_int = malloc(sizeof(int *) * sizemax_y);
    for (int i = 0; i < sizemax_y; i++) {
        tab_int[i] = malloc(sizeof(int) * sizemax_x);
        for (int j = 0; j < sizemax_x; j++) {
            tab_int[i][j] = map[i][j];
        }
    }
    free_tab(map);
    return (tab_int);
}