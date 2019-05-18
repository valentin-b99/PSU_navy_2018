/*
** EPITECH PROJECT, 2018
** my_strlowcase
** File description:
** my_strlowcase
*/

#include "../../include/my.h"

char *my_strlowcase(char *str)
{
    for (int i = 0; str[i]; i++)
        if (str[i] <= 90 && str[i] >= 65)
            str[i] = str[i] + 32;
    return (str);
}
