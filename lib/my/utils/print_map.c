/*
** EPITECH PROJECT, 2022
** print_map.c
** File description:
** print map
*/
#include "my.h"
#include <unistd.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <fcntl.h>
#include <ncurses.h>


void print_map(s_map *sMap, int row, int col)
{
    int len = sMap->rows;
    int i = 0;
    int j = 0;
    while (i < len) {
        mvprintw
        (row / 3 + j, (col - my_strlen(sMap->map[i])) / 2,
        "%s\n", sMap->map[i]);
        i ++;
        j ++;
    }
}
