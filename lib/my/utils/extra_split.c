/*
** EPITECH PROJECT, 2022
** str_split
** File description:
** splits the str into an array of string
*/

#include <stdlib.h>
#include <stddef.h>
#include <stdio.h>
#include <unistd.h>
#include "my.h"

int is_alpha_char(char my_char, char my_split_char)
{
    if (my_char == my_split_char) {
        return (1);
    }
    return (0);
}

int separate_str(char const *string, char split)
{
    int index = 1;
    int cnt_three = 0;
    while (string[index]) {
        if (is_alpha_char(string[index], split) == 0 &&
        is_alpha_char(string[index +1], split) == 1)
            cnt_three++;
        index++;
    }
    return (cnt_three);
}

int split_num(char const *string, int index, int cnt, char split)
{
    while (string[index]) {
        if (is_alpha_char(string[index], split) == 0) {
            cnt++;
        }
        index++;
        if (is_alpha_char(string[index], split) == 1) {
            break;
        }
    }
    return (cnt);
}

char **my_split(char const *str, char split)
{
    int z = 0;
    int cnt_one = separate_str(str, split);
    int count_two = 0;
    int cnt_three;
    char **array = malloc(((1 +cnt_one) * sizeof(char*)));
    for (int i = 0; i <= cnt_one; i++)
        array[i] = NULL;
    while (count_two <= cnt_one) {
        cnt_three = 0;
        array[count_two] = malloc(sizeof(char)
            * split_num(str, z, cnt_one, split) + 1);
        array[count_two][0] = '\0';
        while (str[z] && is_alpha_char(str[z], split) == 0) {
            array[count_two][cnt_three++] = str[z++];
        }
        array[count_two++][cnt_three] = '\0';
        z++;
    }
    array[cnt_one] = NULL;
    return (array);
}
