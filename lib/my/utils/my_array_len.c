/*
** EPITECH PROJECT, 2022
** is_float
** File description:
** handle the precision
*/
#include "my.h"

int my_array_len(char** array)
{
    int i = 0;
    while (array[i]) {
        i++;
    }
    i--;
    return (i);
}
