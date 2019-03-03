/*
** EPITECH PROJECT, 2017
** my_putnubr
** File description:
** my_put_nbr
*/

#include "my.h"

void	my_putnbr(int nb)
{
	int m;

	if (nb < 0) {
		my_putchar('-');
		nb = nb * -1;
	}
	if (nb >= 0) {
		if (nb >= 10) {
			m = (nb % 10);
			nb = (nb - m) / 10;
			my_putnbr(nb);
			my_putchar(m + 48);
		} else {
			my_putchar(48 + (nb % 10));
		}
	}
}
