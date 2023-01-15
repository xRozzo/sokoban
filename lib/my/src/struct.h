/*
** EPITECH PROJECT, 2022
** struct.h
** File description:
** Contains the prototypes structs in sokoban
*/

#include "ncurses.h"

#ifndef STRUCTS_H_
    #define STRUCTS_H_

    typedef struct t_map {
        char **map;
        int rows;
    }s_map;

    typedef struct t_player_pos {
        int i;
        int j;
    }s_player_pos;


#endif
