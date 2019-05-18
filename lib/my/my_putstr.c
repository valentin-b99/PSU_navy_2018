/*
** EPITECH PROJECT, 2019
** my_putstr
** File description:
** my_putstr
*/

#include "../../include/my.h"

int my_putstr(char *str)
{
    return (write(1, str, my_strlen(str)));
}