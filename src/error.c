/*
** EPITECH PROJECT, 2019
** error
** File description:
** for navy
*/

#include "../include/navy.h"

int verif_size(char *line)
{
    int nb = line[0] - 49;

    if (line[2] == line[5] && line[3] - line[6] != nb &&
        line[3] - line[6] != -nb) {
        return (PROBLEM);
    } else if (line[3] == line[6] && line[2] - line[5] != nb &&
        line[2] - line[5] != -nb) {
        return (PROBLEM);
    } else
        return (SUCCESS);
}

int verif_pattern(char **tab)
{
    int returned_value = SUCCESS;

    for (int i = 0; i < 4; i++) {
        returned_value = scan_file(tab, i);
        if (verif_size(tab[i]) == PROBLEM)
            returned_value = PROBLEM;
        if (returned_value == PROBLEM)
            return (PROBLEM);
    }
    return (SUCCESS);
}

int verif_file(char *path)
{
    int fic = open(path, O_RDONLY);
    char *buff = malloc(sizeof(char) * 32);
    int len = 1;
    char **tab;
    int size = 0;

    if (fic == -1 || buff == NULL) {
        my_puterror(ERR_WG_FILE);
        return (PROBLEM);
    }
    while (len > 0) {
        len = read(fic, buff + size, len);
        size += len;
    }
    tab = cut_str(buff, '\n');
    if (get_size_array(tab) != 4 || verif_pattern(tab) == PROBLEM)
        return (fic_msg());
    close(fic);
    free(buff);
    destroy_array(tab);
    return (SUCCESS);
}

int fic_msg(void)
{
    my_puterror(ERR_ERR_FILE);
    return (PROBLEM);
}

int help_msg(void)
{
    my_putstr(MSG_HELP);
    return (SUCCESS);
}