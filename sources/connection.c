/*
** EPITECH PROJECT, 2017
** PSU_navy_2017
** File description:
** connection.c
*/

#include "my.h"

void 			establish_connection(char **av)
{
	if (info.host == -1) {
		my_putstr("my_pid : ");
		my_putnbr(getpid());
		my_putchar('\n');
		kill(my_getnbr(av[1]), SIGUSR1);
		while (info.connected == 0);
		my_putstr("successfully connected\n");
	} else if (info.host == 1) {
		my_putstr("my_pid : ");
		my_putnbr(getpid());
		my_putchar('\n');
		my_putstr("waiting for enemy connection...\n");
		while (info.connected == 0);
		kill(info.enemy_pid, SIGUSR1);
		my_putstr("\nenemy connected\n");
	}
}

void 			new_handler(int sig, siginfo_t *siginfo, void *a)
{
	if (sig == 12)
		info.str[info.i] = '0';
	else if (sig == 10)
		info.str[info.i] = '1';
	info.i++;
	if (info.i == 4) {
		info.i = 0;
		info.recu = 1;
	}
}
