/*
** EPITECH PROJECT, 2018
** my_strupcase
** File description:
** my_strupcase
*/

#include "../../include/my.h"

char *my_strupcase(char *str)
{
    for (int i = 0; str[i]; i++)
        if (str[i] <= 122 && str[i] >= 97)
            str[i] = str[i] - 32;
    return (str);
}
