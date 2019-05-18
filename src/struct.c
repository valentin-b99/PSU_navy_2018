/*
** EPITECH PROJECT, 2019
** struct
** File description:
** struct
*/

#include "../include/navy.h"

glob_t *create_struct(int enemy_pid, char **map)
{
    glob_t *new = malloc(sizeof(glob_t));
    char *str = "........";

    if (new == NULL)
        return (NULL);
    if ((new->map = malloc(sizeof(struct map))) == NULL)
        return (NULL);
    new->map->map = map;
    new->map->enn = malloc(sizeof(char *) * 8);
    for (int i = 0; i < 8; i++) {
        if ((new->map->enn[i] = malloc(sizeof(char) * 8)) == NULL)
            return (NULL);
        new->map->enn[i] = str;
    }
    new->pid = enemy_pid;
    new->winner = -1;
    return (new);
}

void destroy_array(char **tab)
{
    for (int i = 0; i < get_size_array(tab); i++) {
        if (tab != NULL)
            free(tab[i]);
    }
    free(tab);
}

void destruct(glob_t *src)
{
    for (int i = 0; i < 8; i++) {
        if (src->map->map != NULL)
            free(src->map->map[i]);
    }
    for (int i = 0; i < 8; i++) {
        if (src->map->enn != NULL)
            free(src->map->enn[i]);
    }
    free(src->map);
    free(src);
}