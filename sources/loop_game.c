/*
** EPITECH PROJECT, 2017
** PSU_navy_2017
** File description:
** loop_game.c
*/

#include "my.h"

void 			send_win_or_lose(void)
{
	if (win() == 0) {
		sender(0);
	}
	if (win() == 1) {
		display_two_map();
		my_putstr("\nEnemy won\n");
		sender(1);
	}
}

int 			receive_win_or_lose(void)
{
	info.recu = 0;
	while (info.recu == 0);
	info.value = get_value_from_binary(info.str);
	if (info.value == 1) {
		display_two_map();
		my_putstr("\nI won\n");
		return(1);
	}
	return (0);
}

int 			loop_game_no_host(void)
{
	info.recu = 0;
	display_two_map();
	my_putstr("\nattack: ");
	send_values_x_y();
	print_miss_or_hit_for_no_host(info.input[0] - 64, info.input[1] - 48);
	send_win_or_lose();
	if (receive_win_or_lose() == 1)
		return (1);
	return (0);
}

int 			loop_game_host(void)
{
	display_two_map();
	my_putstr("\nwaiting for enemy's attack...\n");
	int x = get_value();
	int y = get_value();
	print_miss_or_hit_for_host(x, y);
	if (receive_win_or_lose() == 1)
		return (1);
	send_win_or_lose();
	return (0);
}

int 			loop_game(void)
{
	while (win() == 0) {
		if (info.host == -1) {
			if (loop_game_no_host() == 1)
				return (1);
		} else if (info.host == 1) {
			if (loop_game_host() == 1)
				return (1);
		}
		info.host *= -1;
	}
	return (0);
}