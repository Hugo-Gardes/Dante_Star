/*
** EPITECH PROJECT, 2020
** B-CPE-200-MPL-2-1-dante-hugo.frango
** File description:
** include.h
*/

#ifndef __INCLUDE__
#define __INCLUDE__

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdbool.h>
#include <fcntl.h>
#include <time.h>

#define RESET		0
#define BRIGHT 		1
#define DIM		    2
#define UNDERLINE 	3
#define BLINK		4
#define REVERSE		7
#define HIDDEN		8

#define BLACK 		0
#define RED		    1
#define GREEN		2
#define YELLOW		3
#define BLUE		4
#define MAGENTA		5
#define CYAN		6
#define	WHITE		7

typedef struct {
    int x;
    int y;
} position;

typedef struct {
    long long int before;
    long long int before2;
    long long int after;
    long long int after2;
} stoc_char;

typedef struct {
    position pos;
    position size_max;
    stoc_char st;
    bool modif;
    bool is_perfect;
    long long int **map;
    char wall;
    char path;
} cont, *container;

void free_tab_int(long long int **tab, int sizemax_y);

void set_tab_alea(container map);

void set_path(container map);

void print_tab_int(container map);

void break_two(container map);

void set_path_bis(container map);

bool is_finished(container map);

void set_path_bis(container map);

void tab_create(container map);

// text_color.c

/* funct to color text take macro in arg */
void textcolor(int attr, int fg, int bg);

// end textcolor.c

#endif