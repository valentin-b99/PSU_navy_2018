/*
** EPITECH PROJECT, 2019
** navy.h
** File description:
** for navy
*/

#include "../include/navy.h"

int main(int ac, char **av)
{
    if (ac != 2 && ac != 3) {
        my_puterror(ERR_BADARGS);
        return (FAILURE);
    }
    if (verif_file(av[ac - 1]) == PROBLEM) {
        return (FAILURE);
    } else if (ac == 2) {
        if (my_strcmp(av[1], CMD_HELP) == 0)
            return (help_msg());
        return (player_one(get_map(av[1])));
    } else {
        if (my_getnbr(av[1]) <= 0)
            return (pid_msg());
    }
    return (player_two(my_getnbr(av[1]), get_map(av[2])));
}