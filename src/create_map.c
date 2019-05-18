/*
** EPITECH PROJECT, 2019
** create_map
** File description:
** create_map
*/

#include "../include/navy.h"

int scan_file(char **tab, int i)
{
    if (tab[i][0] != i + 2 + 48 || tab[i][1] != ':' || tab[i][2] < 'A' ||
        tab[i][2] > 'H' || tab[i][3] < '1' || tab[i][3] > '8' ||
        tab[i][4] != ':' || tab[i][5] < 'A' || tab[i][5] > 'H' ||
        tab[i][6] < '1' || tab[i][6] > '8' ||
        (tab[i][7] != '\n' && tab[i][7] != '\0'))
        return (PROBLEM);
    return (SUCCESS);
}

char **tab_map_next(char **tab, int i, int y, char **rules)
{
    for (int x = rules[i][2] - 65; x <= rules[i][5] - 65; x++)
        if (tab[y][x] == '.')
            tab[y][x] = rules[i][0];
        else
            return (NULL);
    return (tab);
}

char **tab_map(char **tab, int i, char **rules)
{
    for (int y = rules[i][3] - 49; y <= rules[i][6] - 49; y++)
        if ((tab = tab_map_next(tab, i, y, rules)) == NULL)
            return (NULL);
    return (tab);
}

char **create_map(char **tab, char *buff)
{
    char **rules = cut_str(buff, '\n');

    if (get_size_array(rules) != 4) {
        my_puterror(ERR_WG_FILE);
        return (NULL);
    }
    for (int i = 0; i < 4; i++) {
        if ((tab = tab_map(tab, i, rules)) == NULL) {
            my_puterror(ERR_WG_MAP);
            return (NULL);
        }
    }
    destroy_array(rules);
    return (tab);
}

char **get_map(char *path)
{
    int fic = open(path, O_RDONLY);
    char *buff = malloc(sizeof(char) * 32);
    char *str = "........";
    int len = 1;
    int size = 0;
    char **tab = malloc(sizeof(char[9]) * 8);

    if (fic == -1 || tab == NULL || buff == NULL)
        return (NULL);
    while (len > 0) {
        len = read(fic, buff + size, len);
        size += len;
    }
    for (int i = 0; i < 8; i++)
        tab[i] = my_strdup(str);
    if ((tab = create_map(tab, buff)) == NULL)
        return (NULL);
    free(buff);
    close(fic);
    return (tab);
}