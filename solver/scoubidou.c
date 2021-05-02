/*
** EPITECH PROJECT, 2020
** B-CPE-200-MPL-2-1-dante-hugo.frango
** File description:
** scoubidou.c
*/

#include "my.h"

int size_y(char **map)
{
    int size = 0;
    for (; map[size]; size++);
    return(size);
}

bool as_possibility(int **map, pos poss)
{
    if (poss.x - 1 >= 0)
        if (map[poss.y][poss.x - 1] == '*')
            return (false);
    if (poss.y - 1 >= 0)
        if (map[poss.y - 1][poss.x] != '*')
            return (false);
    return (true);
}

int **init_tab_dist(int **map, pos size_max)
{
    pos position = {size_max.x, size_max.y};
    int distance = 0;
    dir direc = {0, 0, 0, 0};

    while (map[0][0] == '*') {
        direc = (dir){0, 0, 0, 0};
        direc = init_direc(size_max, map, direc, position);
        map = switch_init_tab((reduc_switch){direc,\
        map, &position, size_max, &distance});
        if (position.x == size_max.x && position.y == size_max.y &&\
        !as_possibility(map, position)) {
            printf("no solution found\n");
            exit(84);
        }
        if (distance == '*' || distance == 'o' || distance == 'X')
            distance += 1;
        map[position.y][position.x] = distance;
    }
    return (map);
}

int **init_map_path(int **map, int u, int v)
{
    if (map[u][v] == '*') 
        map[u][v] = 2147483646;
    else if (map[u][v] == 'X')
        map[u][v] = 2147483647;
    return (map);
}

int **restor_map(int **map, int u, int v)
{
    if (map[u][v] == 2147483647)
        map[u][v] = 'X';
    if (map[u][v] == 2147483646)
        map[u][v] = '*';
    if (map[u][v] != 'o' && map[u][v] != 'X' && map[u][v] != '*')
        map[u][v] = '*';
    return (map);
}

int **find_path(int **map, pos max_size)
{
    pos position = {0, 0};
    int temp = 0;

    for (int u = 0; u < max_size.y + 1; u++)
        for (int v = 0; v < max_size.x + 1; v++)
            map = init_map_path(map, u, v);
    map[position.y][position.x] = 'o';
    while (position.x != max_size.x || position.y != max_size.y) {
        temp = map[position.y][position.x];
        find_lower(map, &position, max_size, &temp);
        map[position.y][position.x] = 'o';
    }
    map[position.y][position.x] = 'o';
    for (int u = 0; u < max_size.y + 1; u++)
        for (int v = 0; v < max_size.x + 1; v++)
            map = restor_map(map, u, v);
    return (map);
}

void solveur(int **map, int sizemax_x, int sizemax_y)
{
    pos position = {sizemax_x - 1, sizemax_y - 1};
    int distance = 48;
    map[position.y][position.x] = distance;
    map = init_tab_dist(map, position);
    map = find_path(map, position);
    print_tab_int(map, sizemax_x, sizemax_y);
}

int main(int argc, char **argv)
{
    error_handling(argc, argv);
    char **map = my_str_t_w_a(open_read(argv[1]), " \n");
    int size_x = strlen(map[0]);
    int size_y_y = size_y(map);
    int **tab_int = make_int_tab(map, size_x, size_y_y);
    solveur(tab_int, size_x, size_y_y);
    free_tab_int(tab_int, size_y_y);
    return (0);
}