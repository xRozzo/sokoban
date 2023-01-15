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

char **read_map(int argc, char* argv[], struct stat sb, char *buff)
{
    char **map_char_format;
    int fd = open(argv[argc - 1], O_RDONLY);
    if (fd == -1)
        exit(84);
    int offset = 0;
    int len;
    stat(argv[1], &sb);
    buff = malloc(sizeof(char) * sb.st_size + 1);
    buff[0] = '\0';
    if (fd != -1) {
        while ((len = read(fd, buff + offset, sb.st_size - offset)) > 0)
            offset = offset + len;
        buff[offset] = '\0';
    }
    if (buff != NULL)
        (map_char_format = my_split(buff, '\n'));
    else {
        exit(84);
    }
    return (map_char_format);
}

char **scan_map(int argc, char *argv[])
{
    char **map_char_format;
    struct stat sb;
    char *buff;
    if (argc > 2)
        exit(84);
    else {
        map_char_format = read_map(argc, argv, sb, buff);
    }
    return (map_char_format);
}
