/*
** EPITECH PROJECT, 2019
** clean_str
** File description:
** clean_str
*/

#include "../../include/my.h"

int char_in_list(char c, char *list_char)
{
    for (int i = 0; list_char[i]; i++)
        if (list_char[i] == c)
            return (1);
    return (0);
}

int cs_tlsz(char *str, char *list_char)
{
    int i = 0;
    int len = 0;

    while (char_in_list(str[i], list_char))
        i++;
    while (str[i]) {
        if (!char_in_list(str[i], list_char))
            len++;
        else if (str[i + 1] && !char_in_list(str[i + 1], list_char))
            len++;
        i++;
    }
    return (len);
}

char *clean_str(char *str, char *list_char, char to_char)
{
    int i = 0;
    int j = 0;
    char *result;

    if ((result = malloc(sizeof(char) * (cs_tlsz(str, list_char) + 1))) == NULL)
        return (NULL);
    my_memset(&result, 0, cs_tlsz(str, list_char) + 1);
    while (char_in_list(str[i], list_char))
        i++;
    while (str[i]) {
        if (!char_in_list(str[i], list_char)) {
            result[j] = str[i];
            j++;
        } else if (str[i + 1] && !char_in_list(str[i + 1], list_char)) {
            result[j] = to_char;
            j++;
        }
        i++;
    }
    return (result);
}