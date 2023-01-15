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
#include "my.h"
#include <unistd.h>
#include <ncurses.h>
#include <curses.h>
#include "../src/struct.h"
#include "my.h"


void display(s_map *sMap, int row, int col)
{
    char *str = "Enlarge your terminal";
    int colum;
    int rows;
    getmaxyx(stdscr,colum,rows);
    if (colum - 5 < sMap->rows) {
        wclear(stdscr);
        mvprintw(row / 3, (col - (my_strlen(str))) / 2, "%s\n", str);
    } else {
        wclear(stdscr);
        print_map(sMap, row, col);
    }
}
