/*
** EPITECH PROJECT, 2020
** B-CPE-200-MPL-2-1-dante-hugo.frango
** File description:
** generator.c
*/

#include <include.h>

bool match(char *to_comp, char *comp)
{
    if (strlen(to_comp) != strlen(comp))
        return (false);
    for (int i = 0; to_comp[i]; i++)
        if (to_comp[i] != comp[i])
            return (false);
    return (true);
}

int main(int argc, char **argv)
{
    cont map;
    if (argc != 3)
        if (argc == 4 && match(argv[3], "perfect"))
            map.is_perfect = true;
        else {
            exit(84);
        }
    else
        map.is_perfect = false;
    map.size_max = (position){atoi(argv[1]), atoi(argv[2])};
    if (map.size_max.x % 2 == 0 || map.size_max.y % 2 == 0)
        return (84);
    map.wall = 1;
    map.path = 0;
    tab_create(&map);
    set_tab_alea(&map);
    set_path(&map);
    print_tab_int(&map);
    free_tab_int(map.map, map.size_max.y);
    return (0);
}