/*
** EPITECH PROJECT, 2018
** my_strncpy
** File description:
** my_strncpy
*/



char *my_strncpy(char *dest, char const *src, int n)
{
    int i = 0;

    while (src[i] && i < n) {
        dest[i] = src[i];
        i++;
    }
    dest[i] = 0;
    return (dest);
}
