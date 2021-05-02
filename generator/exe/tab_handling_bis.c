/*
** EPITECH PROJECT, 2020
** B-CPE-200-MPL-2-1-dante-hugo.frango
** File description:
** tab_handling_bies.c
*/

#include <include.h>

void reset_tab(container map)
{
    for (int y = 0; y < map->size_max.y; y++) {
        for (int x = 0; x < map->size_max.x; x++) {
            if (map->map[y][x] == map->wall)
                map->map[y][x] = 'X';
            else
                map->map[y][x] = '*';
        }
    }
}

void set_path(container map)
{
    map->st = (stoc_char){0, 0, 0, 0};
    srand(time(NULL));
    break_two(map);
    while (is_finished(map)) {
        map->modif = true;
        set_path_bis(map);
    }
    reset_tab(map);
}