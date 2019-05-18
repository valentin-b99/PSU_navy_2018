/*
** EPITECH PROJECT, 2019
** use_map
** File description:
** for navy
*/

#include "../include/navy.h"

char *modif_line(char *line, int j, char c)
{
    char *str = malloc(sizeof(char) * 9);
    int i = 0;

    if (str == NULL)
        return (NULL);
    while (line[i]) {
        if (i == j)
            str[i] = c;
        else
            str[i] = line[i];
        i++;
    }
    str[i] = 0;
    return (str);
}

void write_map(glob_t *src, char *input, int choice, char let)
{
    int i = input[0] - 65;
    int j = input[1] - 49;

    if (choice == 1)
        src->map->map[j] = modif_line(src->map->map[j], i, let);
    else if (src->map->enn[j][i] != 'x')
        src->map->enn[j] = modif_line(src->map->enn[j], i, let);
}

int test_char_map(char c, char *list)
{
    for (int i = 0; list[i]; i++)
        if (c == list[i])
            return (1);
    return (0);
}

int find_in_map(char *input, glob_t *src)
{
    if (input == NULL)
        return (FAILURE);
    my_putstr(my_strcat(input, ": "));
    usleep(10000);
    if (test_char_map(src->map->map[input[1] - 49][input[0] - 65], "2345")) {
        my_putstr(MSG_HIT);
        write_map(src, input, 1, 'x');
        kill(src->pid, SIGUSR1);
    } else {
        my_putstr(MSG_MISSED);
        write_map(src, input, 1, 'o');
        kill(src->pid, SIGUSR2);
    }
    return (SUCCESS);
}