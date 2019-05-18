/*
** EPITECH PROJECT, 2018
** getnextline
** File description:
** src
*/

#include "../../include/my.h"
#include "../../include/get_next_line.h"

int my_charsearch(char *str, char c)
{
    for (int i = 0; str[i]; i++)
        if (str[i] == c)
            return (1);
    return (0);
}

int read_line(int fd, char **str, int *i_buffer)
{
    char *buffer = malloc(sizeof(char) * (READ_SIZE + 1));
    int len = 0;

    if (buffer == NULL)
        return (84);
    while ((len = read(fd, buffer , READ_SIZE)) > 0) {
        buffer[len] = '\0';
        if ((*str = my_strncat(*str, buffer, my_strlen(buffer))) == NULL)
            return (84);
        if (fd == 0 && my_charsearch(*str, '\n'))
            fd = -1;
    }
    *str = *str + *i_buffer;
    if (fd != -1) {
        *i_buffer = 0;
        if ((*str)[*i_buffer] == '\n')
            *i_buffer = 1;
    }
    while ((*str)[*i_buffer] != '\n' && (*str)[*i_buffer])
        *i_buffer += 1;
    return (0);
}

char *get_next_line(int fd)
{
    static int i_buffer = 0;
    static char *str = "";
    char *result = "";

    if (fd == -1)
        return (NULL);
    if (fd == 0) {
        str = "";
        i_buffer = 0;
    }
    if (read_line(fd, &str, &i_buffer) == 84 ||
        (result = malloc(sizeof(char) * (i_buffer + 1))) == NULL)
        return (NULL);
    result = "";
    if ((result = my_strncat(result, str, i_buffer)) == NULL)
        return (NULL);
    i_buffer++;
    if (result[0] == 0)
        return (NULL);
    return (result);
}