/*
** EPITECH PROJECT, 2018
** my_strdup
** File description:
** my_strdup
*/

#include "../../include/my.h"

char *my_strdup(char *src)
{
    int i = 0;
    char *result;

    if ((result = malloc(sizeof(char) * (my_strlen(src) + 1))) == NULL)
        return (NULL);
    my_memset(&result, 0, my_strlen(src) + 1);
    while (src[i]) {
        result[i] = src[i];
        i++;
    }
    result[i] = 0;
    return (result);
}
