/*
** EPITECH PROJECT, 2019
** game
** File description:
** for navy
*/

#include "../include/navy.h"

int line_without_nb(char *line)
{
    for (int j = 0; j < 8; j++) {
        if (line[j] <= '9' && line[j] >= '0')
            return (PROBLEM);
    }
    return (SUCCESS);
}

int count_x_next(char enn, int *count)
{
    if (enn == 'x')
        *count += 1;
}

int count_x(char **enn)
{
    int count = 0;

    for (int i = 0; i < 8; i++)
        for (int j = 0; j < 8; j++)
            count_x_next(enn[i][j], &count);
    return (count);
}

void win(glob_t *src, int player)
{
    int winner1 = 1;
    int winner2 = 0;

    for (int i = 0; i < 8; i++) {
        if (line_without_nb(src->map->map[i]) != SUCCESS)
            winner1 = 0;
    }
    if (count_x(src->map->enn) == 14)
        winner2 = 1;
    if (winner1 != 0 || winner2 != 0) {
        if (winner2 != 0) {
            my_putstr(MSG_WIN);
            src->winner = 0;
        } else {
            my_putstr(MSG_LOSE);
            src->winner = 1;
        }
    }
}

void print_game(glob_t *src, int player)
{
    int line = 1;

    if (player == 1)
        my_putstr(MSG_MY_POS);
    else
        my_putstr(MSG_ENEMY_POS);
    my_putstr(LINE_GAME_POS);
    while (line < 9) {
        my_putstr(my_itoa(line));
        my_putstr("|");
        if (player == 1)
            my_putstrsp(src->map->map[line - 1]);
        else
            my_putstrsp(src->map->enn[line - 1]);
        my_putstr("\n");
        line++;
    }
    my_putstr("\n");
}