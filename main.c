/*
** EPITECH PROJECT, 2018
** PSU_2017_navy
** File description:
** my.h
*/

#include "my.h"

info_t info;

char 			*remove_last_return(char *str)
{
	char *new_str = malloc(sizeof(char) * my_strlen(str));
	for (int i = 0; i < my_strlen(str) - 1; i++)
		new_str[i] = str[i];
	return (new_str);

}

int 			main(int ac, char **av)
{
	create_info(ac, av);
	establish_connection(av);
	info.sa.sa_sigaction = new_handler;
	sigaction(SIGUSR1, &info.sa, NULL);
	sigaction(SIGUSR2, &info.sa, NULL);

	loop_game();
}