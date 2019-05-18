/*
** EPITECH PROJECT, 2018
** my_str_islower
** File description:
** my_str_islower
*/

#include "../../include/my.h"

int my_str_islower(char const *str)
{
    for (int i = 0; str[i]; i++)
        if (str[i] >= 65 && str[i] <= 90)
            return (0);
    return (1);
}
