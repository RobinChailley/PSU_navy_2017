/*
** EPITECH PROJECT, 2017
** PSU_navy_2017
** File description:
** init.c
*/

#include "my.h"

void 			handler_sigaction(int sig, siginfo_t *siginfo, void *a)
{
	info.enemy_pid = siginfo->si_pid;
	info.connected = 1;
}

void 			get_enemy_pid(void)
{
	info.sa.sa_sigaction = handler_sigaction;
	sigemptyset(&info.sa.sa_mask);
	info.sa.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &info.sa, NULL);
	sigaction(SIGUSR2, &info.sa, NULL);
}

void 			create_info(int ac, char **av)
{
	if (ac == 2) {
		info.host = 1;
		info.my_map = create_map_with_boat(av[1]);
	} else if (ac == 3) {
		info.host = -1;
		info.my_map = create_map_with_boat(av[2]);
	}
	info.i = 0;
	info.str = malloc(sizeof(char) * 8);
	info.str[4] = '\0';
	info.enemy_map = create_map_empty();
	info.connected = 0;
	info.input = malloc(sizeof(char) * 10);
	get_enemy_pid();
}