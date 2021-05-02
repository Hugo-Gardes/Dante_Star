/*
** EPITECH PROJECT, 2020
** #code 29_03_2021
** File description:
** my.h
*/

#ifndef __MY_H__
#define __MY_H__

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdbool.h>
#include <fcntl.h>

#include "../exe/str_to_word_array/str_to_word_array.h"

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

// struct

/* struct to keep pos on tab */
typedef struct {
    int x;
    int y;
} pos;

typedef struct {
    int up;
    int down;
    int right;
    int left;
}dir;

typedef struct {
    int *test;
    pos *posf;
    pos *position;
    int **map;
    int *rm;
} reduct;

typedef struct {
    dir direc;
    int **map;
    pos *position;
    pos size_max;
    int *distance;
} reduc_switch;

// end struct

//tab_handling.c

/* open a doc with given path */
char *open_read(char *path);

/* print a tab (must have a NULL line at end) */
void print_tab(char **tab);

/* free a tab (must have a NULL line at end) */
void free_tab(char **tab);

/* create a tab from the file give at argument */
char **tab_create(char *path);

/* transform p in o and b in * */
void reset_tab(char **tab);

//end tab_handling.c

// movement_handling.c

/* deplacement handling for character go down */
int depla_y_handling_down(pos *pos_, pos *preced, char **tab);

/* deplacement handling for character go up */
int depla_y_handling_up(pos *pos_, pos *preced, char **tab);

/* deplacement handling for character go right */
int depla_x_handling_up(pos *pos_, pos *preced, char **tab);

/* deplacement handling for character go left */
int depla_x_handling_down(pos *pos_, pos *preced, char **tab);

// end movement_handling.c

// text_color.c

/* funct to color text take macro in arg */
void textcolor(int attr, int fg, int bg);

// end textcolor.c

// gest_tab_int.c

/* free tab of int */
void free_tab_int(int **tab, int sizemax_y);

/* print tab of int */
void print_tab_int(int **tab, int sizemax_x, int sizemax_y);

/* init tab of int from char **tab */
int **make_int_tab(char **map, int sizemax_x, int sizemax_y);

// end gest_tab_int.c

//start depla_init_tab_handling.c

/* set possible dir */
dir init_direc(pos size_max, int **map, dir direc, pos position);

/* find lower number around actual pos */
void find_lower(int **map, pos *position, pos size_max, int *distance);

/* inbt pos from possible dir */
int **switch_init_tab(reduc_switch r);

//end depla_init_tab_handling.c

// start error_handling.c

/* lunch error handling */
void error_handling(int argc, char **argv);

// end error_handling.c

#endif