/*
** EPITECH PROJECT, 2022
** is_float
** File description:
** handle the precision
*/

#include <pwd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdint.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/sysmacros.h>
#include "dirent.h"
#include <sys/types.h>
#include <unistd.h>
#include <ncurses.h>
#include <curses.h>
#include "lib/my/utils/my.h"
#include "lib/my/src/struct.h"

void free_objects(s_map *Map, s_map *secondMap)
{
    free(Map->map);
    free(secondMap->map);
}

int main(int argc, char *argv[])
{
    keypad(initscr(), true);
    s_map sMap;
    s_map secondMap;
    if (argc == 1)
        exit(84);
    if (argc > 1 && argv[1][0] == '-'
    && argv[1][1] == 'h')
        display_usage();
    init_map(&sMap, argc, argv);
    init_map(&secondMap, argc, argv);
    int row;
    int col;
    noecho();
    getmaxyx(stdscr,row,col);
    play_game(&sMap, row, col, &secondMap);
    refresh();
    free_objects(&sMap, &secondMap);
    return (0);
}
