/*
** EPITECH PROJECT, 2020
** B-CPE-200-MPL-2-1-dante-hugo.frango
** File description:
** path_handling.c
*/

#include <include.h>

void recur(container map, int y)
{
    map->map[map->pos.y][map->pos.x] = map->st.after;

    for (int x = 0; x < map->size_max.x; x++)
        if (map->map[y][x] == map->st.before)
            map->map[y][x] = map->st.after;
}

void if_y_1(container map)
{
    if (map->pos.x + 1 < map->size_max.x &&\
    map->map[map->pos.y][map->pos.x + 1] != map->wall)
        map->st.before = map->map[map->pos.y][map->pos.x + 1];
    else
        map->modif = false;
    if (map->pos.x - 1 >= 0 && map->map[map->pos.y]\
    [map->pos.x - 1] != map->wall)
        map->st.after = map->map[map->pos.y][map->pos.x - 1];
    else
        map->modif = false;
}

void init_befor_after(container map)
{
    if (map->pos.y - 1 >= 0 && map->map\
    [map->pos.y - 1][map->pos.x] == map->wall) {
        if_y_1(map);
    } else {
        if (map->pos.y + 1 < map->size_max.x &&\
        map->map[map->pos.y + 1][map->pos.x] != map->wall)
            map->st.before = map->map[map->pos.y + 1][map->pos.x];
        else
            map->modif = false;
        if (map->pos.y - 1 >= 0 &&\
        map->map[map->pos.y - 1][map->pos.x] != map->wall)
            map->st.after = map->map[map->pos.y - 1][map->pos.x];
        else
            map->modif = false;
    }
}

void break_two(container map)
{
    map->modif = true;
    map->st.before = map->map[0][0];
    if (rand() % 2) {
        map->st.after = map->map[0][2];
        map->map[0][1] = map->st.after;
    } else {
        map->st.after = map->map[2][0];
        map->map[1][0] = map->st.after;
    }
    if (map->st.before != map->st.after && map->modif) {
        map->map[map->pos.y][map->pos.x] = map->st.after;
        for (int y = 0; y < map->size_max.y; y++) {
            recur(map, y);
        }
    }
}

void set_path_bis(container map)
{
    do {
        map->pos.x = ((rand() % ((map->size_max.x))));
        if (!map->pos.x % 2)
            map->pos.x += 1;
        map->pos.y = rand() % (map->size_max.y);
    } while (map->map[map->pos.y][map->pos.x] != map->wall);
    init_befor_after(map);
    if (map->st.before != map->st.after && map->modif) {
        map->map[map->pos.y][map->pos.x] = map->st.after;
        for (int y = 0; y < map->size_max.y; y++) {
            recur(map, y);
        }
    }
}