/*
** EPITECH PROJECT, 2018
** concat_params
** File description:
** concat_params
*/

#include "../../include/my.h"

int cp_total_size(int ac, char **av)
{
    int len = 0;

    for (int i = 0; i < ac; i++)
        len += my_strlen(av[i]) + 1;
    return (len);
}

char *concat_params(int ac, char **av)
{
    char *result;

    if ((result = malloc(sizeof(char) * cp_total_size(ac, av))) == NULL)
        return (NULL);
    my_memset(&result, 0, cp_total_size(ac, av));
    for (int i = 0; i < ac; i++)
        result = my_strcat(my_strcat(result, av[i]), "\n");
    return (result);
}