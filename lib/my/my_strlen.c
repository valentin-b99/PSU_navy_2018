/*
** EPITECH PROJECT, 2018
** my_strlen
** File description:
** my_strlen
*/

int my_strlen(char *str)
{
    int i = 0;

    while (str[i])
        i++;
    return (i);
}
