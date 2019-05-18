/*
** EPITECH PROJECT, 2018
** my_strcpy
** File description:
** my_strcpy
*/

#include "../../include/my.h"

char *my_strcpy(char *src)
{
    int i = 0;
    char *dest = malloc(sizeof(char) * my_strlen(src) + 1);

    if (dest == NULL)
        return (NULL);
    while (src[i]) {
        dest[i] = src[i];
        i++;
    }
    dest[i] = 0;
    return (dest);
}
