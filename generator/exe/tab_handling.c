/*
** EPITECH PROJECT, 2020
** B-CPE-200-MPL-2-1-dante-hugo.frango
** File description:
** tab_handling.c
*/

#include <include.h>

void print_tab_int(container map)
{
    for (int i = 0; i < map->size_max.y; i++) {
        for (int j = 0; j < map->size_max.x; j++) {
            printf("%c", map->map[i][j]);
        }
        printf("\n");
        fflush(stdout);
    }
}

void free_tab_int(long long int **tab, int sizemax_y)
{
    for (int i = 0; i < sizemax_y; i++)
        free(tab[i]);
    free(tab);
}

void tab_create(container map)
{
    map->pos.x = 0;
    map->pos.y = 0;
    map->map = malloc(sizeof(long long int *) * (map->size_max.y + 1));

    for (int y = 0; y < map->size_max.y; y++) {
        map->map[y] = malloc(sizeof(long long int) * (map->size_max.x));
        for (int x = 0; x < map->size_max.x; x++)
            if ((x % 2 && x < map->size_max.x - 1) ||\
            (y % 2 && y < map->size_max.y - 1))
                map->map[y][x] = map->wall;
            else
                map->map[y][x] = map->path;
    }
}

void set_tab_alea(container map)
{
    long long int distance = 49;

    for (int y = 0; y < map->size_max.y; y++)
        for (int x = 0; x < map->size_max.x; x++) {
            if (distance == map->wall || distance == map->path)
                distance += 1;
            if (map->map[y][x] == map->path) {
                map->map[y][x] = distance;
                distance += 1;
            }
        }
}

bool is_finished(container map)
{
    char preced = map->map[0][0];

    for (int y = 0; y < map->size_max.y; y++)
        for (int x = 0; x < map->size_max.x; x++) {
            if (map->map[y][x] != preced && map->map[y][x] != map->wall)
                return (true);
        }
    return (false);
}