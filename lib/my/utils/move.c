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

int get_nb_o(s_map *sMap)
{
    int i = 0;
    int j = 0;
    int cnt = 0;
    int col = my_strlen(sMap->map[0]);
    int my_rows = sMap->rows;
    while (i < my_rows) {
        while (j < col) {
            (sMap->map[i][j] == 'O') ? (cnt++, j ++) : (j ++);
        }
        i++;
        j = 0;
    }
    return cnt;
}

s_player_pos *get_pos_o(s_map *sMap, int nb_o)
{
    int col = my_strlen(sMap->map[0]);
    int my_rows = sMap->rows;
    int i = 0;
    int j = 0;
    int z = 0;
    s_player_pos *array = NULL;
    array = malloc(sizeof (s_player_pos) * nb_o);
    while (i < my_rows) {
        while (j < col) {
            (sMap->map[i][j] == 'O') ? (array[z] =
            create_structures(i, j), j++, z++) : (j++);
        }
        i++;
        j = 0;
    }
    return (array);
}

int is_a_hashtag(s_map *sMap, int plus_i, int plus_j, s_player_pos sPlayerPos)
{
    if (sMap->map[sPlayerPos.i + plus_i][sPlayerPos.j + plus_j] == '#')
        return (1);
    return (0);
}

s_player_pos get_pos_player(s_map *sMap)
{
    s_player_pos sPlayerPos;
    int i = 0;
    int j = 0;
    int col = my_strlen(sMap->map[0]);
    int my_rows = sMap->rows;
    while (i < my_rows) {
        while (j < col) {
            (sMap->map[i][j] == 'P') ?
            (sPlayerPos.i = i, sPlayerPos.j = j, j ++) : (j ++);
        }
        i++;
        j = 0;
    }
    return sPlayerPos;
}

void move_map(s_map *sMap, int p_i, int p_j)
{
    int n = 0;
    int c = 0;
    s_player_pos sPp = get_pos_player(sMap);
    int h = is_a_hashtag(sMap, p_i, p_j, sPp);
    (h == 1) ?
    (sMap->map[sPp.i][sPp.j] = 'P', n++) : (c++);
    (h == 0 && sMap->map[sPp.i + p_i][sPp.j + p_j] != 'X')
    ? (sMap->map[sPp.i][sPp.j] = ' ',
    sMap->map[sPp.i + p_i] [sPp.j + p_j] = 'P', n++)
    : (c++);
    (h == 0 && sMap->map[sPp.i + p_i][sPp.j + p_j] == 'X'
    && (sMap->map[sPp.i + (p_i * 2)][sPp.j +
    (p_j * 2)] == ' '
    || sMap->map[sPp.i + (p_i * 2)] [sPp.j + (p_j * 2)] == 'O'))
    ? ( sMap->map[sPp.i][sPp.j] = ' ',
    sMap->map[sPp.i + p_i][sPp.j + p_j] = 'P'
    , sMap->map[sPp.i + (p_i * 2)][sPp.j +
    (p_j * 2)] = 'X', n++) : (c++);
    if (n == 0)
        sMap->map[sPp.i][sPp.j] = 'P';
}
