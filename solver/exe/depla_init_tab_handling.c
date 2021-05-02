/*
** EPITECH PROJECT, 2020
** B-CPE-200-MPL-2-1-dante-hugo.frango
** File description:
** depla_init_tab_handling.c
*/

#include "my.h"

dir init_direc(pos size_max, int **map, dir direc, pos position)
{
    if (position.x - 1 >= 0)
        if (map[position.y][position.x - 1] == '*')
            direc.left = 1;
    if (position.x + 1 < size_max.x)
        if (map[position.y][position.x + 1] == '*')
            direc.right = 1;
    if (position.y + 1 < size_max.y)
        if (map[position.y + 1][position.x] == '*')
            direc.down = 1;
    if (position.y - 1 >= 0)
        if (map[position.y - 1][position.x] == '*')
            direc.up = 1;
    return (direc);
}

void find_lower_bis_bis(reduct pute, pos size_max)
{
    if (pute.position->y + 1 <= size_max.y) {
        if (pute.map[pute.position->y + 1][pute.position->x] < *pute.test) {
            *pute.test = pute.map[pute.position->y + 1][pute.position->x];
            *pute.posf = *pute.position;
            pute.posf->y += 1;
            if (pute.map[pute.position->y + 1][pute.position->x] >= '0'\
            && pute.map[pute.position->y + 1][pute.position->x] <= '9') {
                *pute.rm = -1;
            }else
                *pute.rm = 1;
        }
    }
}

void find_lower_bis(reduct pute, pos size_max)
{
    find_lower_bis_bis(pute, size_max);
    if (pute.position->y - 1 >= 0) {
        if (pute.map[pute.position->y - 1][pute.position->x] < *pute.test) {
            *pute.test = pute.map[pute.position->y - 1][pute.position->x];
            *pute.posf = *pute.position;
            pute.posf->y -= 1;
            if (pute.map[pute.position->y - 1][pute.position->x] >= '0'\
            && pute.map[pute.position->y - 1][pute.position->x] <= '9')
                *pute.rm = -1;
            else
                *pute.rm = 1;
        }
    }
}

void find_lower_bis_bis_biss(reduct p, pos size_max)
{
    if (p.position->x + 1 <= size_max.x)
        if (p.map[p.position->y][p.position->x + 1] < *p.test) {
            *p.test = p.map[p.position->y][p.position->x + 1];
            *p.posf = *p.position;
            p.posf->x += 1;
            if (p.map[p.position->y][p.position->x + 1] >= '0'\
            && p.map[p.position->y][p.position->x + 1] <= '9')
                *p.rm = -1;
            else
                *p.rm = 1;
        }
}

void find_lower_bis_bis_bis(reduct p)
{
    if (p.position->x - 1 >= 0)
        if (p.map[p.position->y][p.position->x - 1] < *p.test) {
            *p.test = p.map[p.position->y][p.position->x - 1];
            *p.posf = *p.position;
            p.posf->x -= 1;
            if (p.map[p.position->y][p.position->x - 1] >= '0'\
            && p.map[p.position->y][p.position->x - 1] <= '9')
                *p.rm = -1;
            else
                *p.rm = 1;
        }
}

void find_lower(int **map, pos *position, pos size_max, int *distance)
{
    int test = map[position->y][position->x];
    pos posf = *position;
    int rm = 1;

    find_lower_bis_bis_bis((reduct){&test, &posf,\
    position, map, &rm});
    find_lower_bis_bis_biss((reduct){&test, &posf,\
    position, map, &rm}, size_max);
    find_lower_bis((reduct){&test, &posf, position, map, &rm}, size_max);
    position->x = posf.x;
    position->y = posf.y;
    *distance += rm;
}

bool switch_init_tab_bis(reduc_switch *r)
{
    if (r->direc.up) {
        r->map[r->position->y][r->position->x] = *r->distance;
        r->position->y -= 1;
        *r->distance += 1;
        return (true);
    }
    if (r->direc.down) {
        r->map[r->position->y][r->position->x] = *r->distance;
        r->position->y += 1;
        *r->distance += 1;
        return (true);
    }
    return (false);
}

int **switch_init_tab(reduc_switch r)
{
    if (r.direc.left) {
        r.map[r.position->y][r.position->x] = *r.distance;
        r.position->x -= 1;
        *r.distance += 1;
        return (r.map);
    }
    if (r.direc.right) {
        r.map[r.position->y][r.position->x] = *r.distance;
        r.position->x += 1;
        *r.distance += 1;
        return (r.map);
    }
    if (switch_init_tab_bis(&r))
        return (r.map);
    find_lower(r.map, r.position, r.size_max, r.distance);
    return (r.map);
}