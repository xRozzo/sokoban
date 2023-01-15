/*
** EPITECH PROJECT, 2022
** is_float
** File description:
** handle the precision
*/
#include "my.h"
#include "../src/struct.h"

//! coding style

void calculate(int *numbers, int rows)
{
    int j = 1;
    while (j < rows - 1) {
        if (numbers[j] != numbers[j - 1]) {
            exit(84);
        }
        j ++;
    }
}

void init_map(s_map *sMap, int argc, char *argv[])
{
    int i = 0;
    int j = 0;
    int len = 0;
    char **map_char_format = scan_map(argc, argv);
    int rows = my_array_len(map_char_format) + 1;
    int col = my_strlen(map_char_format[0]);
    int *numbers = malloc(sizeof(int) * rows);
    while (j < rows) {
        numbers[j] = my_strlen(map_char_format[j]);
        j ++;
    }
    calculate(numbers, rows);
    sMap->map = malloc(sizeof (char *) * rows + 1);
    sMap->rows = rows;
    while (i < rows) {
        sMap->map[i] = malloc(sizeof(char) * col + 1);
        my_strcpy(sMap->map[i], map_char_format[i]);
        i++;
    }
}
