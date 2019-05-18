/*
** EPITECH PROJECT, 2018
** my_pow
** File description:
** my_pow
*/

int my_pow(int nb, int p)
{
    int result;

    if (p < 0)
        return (0);
    else if (p == 0)
        return (1);
    else
        result = nb * my_pow(nb, p - 1);
    return (result);
}
