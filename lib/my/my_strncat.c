/*
** EPITECH PROJECT, 2018
** my_strncat
** File description:
** my_strncat
*/

#include "../../include/my.h"

char *my_strncat(char *str1, char *str2, int n)
{
    int str1_len = my_strlen(str1);
    char *result;

    if ((result = malloc(sizeof(char) *
        (str1_len + my_strlen(str2) + 1))) == NULL)
        return (NULL);
    my_memset(&result, 0, str1_len + my_strlen(str2) + 1);
    for (int i = 0; str1[i]; i++)
        result[i] = str1[i];
    for (int i = 0; str2[i] && i < n; i++)
        result[str1_len + i] = str2[i];
    return (result);
}
