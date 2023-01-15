/*
** EPITECH PROJECT, 2022
** is_float
** File description:
** handle the precision
*/

#include "my.h"

void display_usage(void)
{
    my_putstr("\033[0;35m");
    my_putstr("USAGE\n"
    "     ./my_sokoban map\n"
    "DESCRIPTION\n"
    "     map file representing the warehouse map, containing ‘#’ for walls,\n"
    "         ‘P’ for the player, ‘X’ for boxes and, "
    "‘O’ for storage locations.\n");
    my_putstr("\033[0m");
    exit(0);
}
