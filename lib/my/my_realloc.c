/*
** EPITECH PROJECT, 2019
** my_realloc
** File description:
** my_realloc
*/

#include "../../include/my.h"

int my_realloc(char **str, int size)
{
    char *str_cpy;

    if (my_mstrcpy(&str_cpy, *str))
        return (1);
    if ((*str = malloc(sizeof(char) * (size + 1))) == NULL)
        return (1);
    my_memset(str, 0, size + 1);
    if (my_mstrncpy(str, str_cpy, size))
        return (1);
    return (0);
}