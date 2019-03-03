/*
** EPITECH PROJECT, 2017
** PSU_navy_2017
** File description:
** send.c
*/

#include "my.h"

void 			send_first_and_second_bit(int nb)
{
	if (nb == 8)
		kill(info.enemy_pid, SIGUSR1);
	else
		kill(info.enemy_pid, SIGUSR2);

	sleep(0.1);

	if (nb >= 4 && nb != 8)
		kill(info.enemy_pid, SIGUSR1);
	else
		kill(info.enemy_pid, SIGUSR2);

	sleep(0.1);
}

void 			send_third_and_fourth_bit(int nb)
{
	if (nb == 6 || nb == 2 || nb == 3 || nb == 7)
		kill(info.enemy_pid, SIGUSR1);
	else
		kill(info.enemy_pid, SIGUSR2);

	sleep(0.1);

	if (nb % 2 == 1)
		kill(info.enemy_pid, SIGUSR1);
	else
		kill(info.enemy_pid, SIGUSR2);

	sleep(0.1);
}

void 			sender(int nb)
{
	send_first_and_second_bit(nb);
	send_third_and_fourth_bit(nb);
}

int 			get_value_from_binary(char *str)
{
	int nb = 0;
	if (str[0] == '1')
		nb += 8;
	if (str[1] == '1')
		nb += 4;
	if (str[2] == '1')
		nb += 2;
	if (str[3] == '1')
		nb += 1;
	return (nb);
}