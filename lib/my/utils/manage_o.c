/*
** EPITECH PROJECT, 2022
** is_float
** File description:
** handle the precision
*/

#include "my.h"
#include "../src/struct.h"

int nb_of_hashtags(s_map *sMap, int i, int j)
{
    int nb_of_hashtags = 0;
    if (sMap->map[i][j + 1] == '#')
        nb_of_hashtags++;
    if (sMap->map[i][j - 1] == '#')
        nb_of_hashtags++;
    if (sMap->map[i - 1][j] == '#')
        nb_of_hashtags++;
    if (sMap->map[i + 1][j] == '#')
        nb_of_hashtags++;
    return (nb_of_hashtags);
}

s_player_pos *get_pos_x(s_map *sMap, int nb_o)
{
    int col = my_strlen(sMap->map[0]);
    int my_rows = sMap->rows;
    int i = 0;
    int j = 0;
    int z = 0;
    s_player_pos *array = NULL;
    array = malloc(sizeof(s_player_pos) * nb_o);
    while (i < my_rows) {
        while (j < col) {
            (sMap->map[i][j] == 'X') ?
            (array[z] = create_structures(i, j), j++, z++) : (j++);
        }
        i++;
        j = 0;
    }

    return (array);
}

int x_stucked(s_map *sMap, int nb_of_X)
{
    int hashtag_cnt = 0;
    int z = 0;
    s_player_pos *array = get_pos_x(sMap, nb_of_X);
    while (z < nb_of_X) {
        if (nb_of_hashtags(sMap, array[z].i, array[z].j) >= 2) {
            hashtag_cnt++;
        }
        z ++;
    }
    if (hashtag_cnt == nb_of_X)
        return (1);
    return (0);
}

int manage_o(s_map *sMap, s_player_pos *array, int nb_of_o)
{
    int z = 0;
    int j = 0;
    int objectives = 0;
    while (z < nb_of_o) {
        if (sMap->map[array[z].i][array[z].j] == ' ') {
            sMap->map[array[z].i][array[z].j] = 'O';
        }
        z++;
    }
    while (j < nb_of_o) {
        if (sMap->map[array[j].i][array[j].j] == 'X') {
            objectives++;
        }
        j++;
    }
    if (objectives == nb_of_o)
        return 0;
    if (x_stucked(sMap, nb_of_o) == 1)
        return (1);
    return (3);
}
