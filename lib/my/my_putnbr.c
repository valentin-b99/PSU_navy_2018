/*
** EPITECH PROJECT, 2018
** my_putnbr
** File description:
** my_putnbr
*/

#include "../../include/my.h"

int my_putnbr(int nb)
{
    int len = 0;

    if (nb < 0) {
        len += my_putchar('-');
        nb = nb * (-1);
    }
    if (nb >= 0 && nb <= 9)
        len += my_putchar(nb + 48);
    if (nb == -2147483648) {
        len += write(1, "2147483648", 10);
    } else if (nb > 9) {
        len += my_putnbr(nb / 10);
        len += my_putchar(nb % 10 + 48);
    }
    return (len);
}
