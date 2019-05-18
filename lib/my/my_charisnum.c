/*
** EPITECH PROJECT, 2018
** my_charisnum
** File description:
** my_charisnum
*/

#include "../../include/my.h"

int my_charisnum(char const str)
{
    if (str < 48 || str > 57)
        return (0);
    return (1);
}
