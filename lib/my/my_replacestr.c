/*
** EPITECH PROJECT, 2019
** my_replacestr
** File description:
** my_replacestr
*/

#include "../../include/my.h"

char *my_replacestr(char *str, char *fromstr, char *tostr)
{
    for (int i = 0; str[i]; i++)
        if (!my_strncmp(str + i, fromstr, my_strlen(fromstr) - 1))
            str = my_strnncat(i, i + my_strlen(fromstr), str, tostr);
    return (str);
}