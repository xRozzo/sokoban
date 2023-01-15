/*
** EPITECH PROJECT, 2022
** is_float
** File description:
** handle the precision
*/

#include "my.h"
#include <unistd.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <fcntl.h>
#include "../src/struct.h"
#include <ncurses.h>
#include <curses.h>

void reset_map(s_map *sMap, s_map *second_map)
{
    int i = 0;
    while (i < sMap->rows) {
        my_strcpy(sMap->map[i], second_map->map[i]);
        i++;
    }
}
