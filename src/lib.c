/*
** EPITECH PROJECT, 2019
** lib
** File description:
** for navy
*/

#include "../include/navy.h"

void my_puterror(char *str)
{
    int i = 0;

    while (str[i]) {
        write(2, &str[i], 1);
        i++;
    }
}

void my_putstrsp(char *str)
{
    int i = 0;

    while (str[i]) {
        write(1, &str[i], 1);
        if (str[i + 1])
            write(1, " ", 1);
        i++;
    }
}

int count_space(char *str, char c)
{
    int count = 1;
    int i = 0;

    if (my_strlen(str) == 0)
        return (1);
    while (str[i]) {
        if (str[i] == c || str[i] == '\t')
            count++;
        i++;
    }
    return (count);
}

char **cut_str(char *str, char c)
{
    int size = 0;
    char **res;
    int nb = 0;

    if ((res = malloc(sizeof(char *) * count_space(str, c) + 1)) == NULL)
        return (NULL);
    while (str[size]) {
        while (str[size] != c && str[size] != '\t' && str[size])
            size++;
        if ((res[nb] = malloc(sizeof(char) * size + 1)) == NULL)
            return (NULL);
        for (int k = 0; k < size; k++)
            res[nb][k] = str[k];
        res[nb][size] = 0;
        while ((str[size] == c || str[size] == '\t') && str[size])
            size++;
        str += size;
        size = 0;
        nb++;
    }
    return (res);
}

int get_size_array(char **prog)
{
    int i = 0;

    while (prog[i] != NULL)
        i++;
    return (i);
}