/*
** EPITECH PROJECT, 2018
** my_sqrt
** File description:
** my_sqrt
*/

#include "../../include/my.h"

int my_sqrt(int nb)
{
    int i = 1;
    int i_result = 0;

    while (i_result < nb) {
        i_result = i * i;
        if (i_result == nb) {
            return (i);
        } else if (i > 46340) {
            return (0);
        } else {
            i = i + 1;
        }
    }
    return (0);
}
