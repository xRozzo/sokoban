/*
** EPITECH PROJECT, 2022
** info_file
** File description:
** ls bootstrap
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

void move_left(s_map *sMap, int row, int col)
{
    move_map(sMap, 0, -1);
    print_map(sMap, row, col);
    refresh();
}

void move_right(s_map *sMap, int row, int col)
{
    move_map(sMap, 0, 1);
    print_map(sMap, row, col);
    refresh();
}

void move_up(s_map *sMap, int row, int col)
{
    move_map(sMap, -1, 0);
    print_map(sMap, row, col);
    refresh();
}

void move_down(s_map *sMap, int row, int col)
{
    move_map(sMap, 1, 0);
    print_map(sMap, row, col);
    refresh();
}

void play_game(s_map *sMap, int row, int col, s_map *second_map)
{
    int input = 0;
    int nb_o = get_nb_o(sMap);
    int game_over = 0;
    s_player_pos *array = get_pos_o(sMap, nb_o);
    while (1) {
        display(sMap, row, col);
        input = wgetch(stdscr);
        switch (input) {
            case KEY_LEFT: move_left(sMap, row, col); break;
            case KEY_RIGHT: move_right(sMap, row, col); break;
            case KEY_UP: move_up(sMap, row, col); break;
            case KEY_DOWN: move_down(sMap, row, col); break;
            case 32: reset_map(sMap, second_map);
        }
        game_over = manage_o(sMap, array, nb_o);
        (game_over == 0) ? (exit(0)) : (nb_o += 0);
        (game_over == 1) ? (exit(1)) : (nb_o += 0);
        refresh();
        wrefresh(stdscr);
    }
}
