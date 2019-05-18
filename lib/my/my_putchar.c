/*
** EPITECH PROJECT, 2018
** my_putchar
** File description:
** my_putchar
*/

#include "../../include/my.h"

int my_putchar(char c)
{
    return (write(1, &c, 1));
}
