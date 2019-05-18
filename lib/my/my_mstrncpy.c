/*
** EPITECH PROJECT, 2018
** my_mstrncpy
** File description:
** my_mstrncpy
*/

#include "../../include/my.h"

int my_mstrncpy(char **dest, char *src, int n)
{
    int i = 0;

    if ((*dest = malloc(sizeof(char) * (n + 1))) == NULL)
        return (1);
    my_memset(dest, 0, n + 1);
    while (src[i] && i < n) {
        (*dest)[i] = src[i];
        i++;
    }
    (*dest)[i] = 0;
    return (0);
}