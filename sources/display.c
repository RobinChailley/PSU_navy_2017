/*
** EPITECH PROJECT, 2017
** PSU_navy_2017
** File description:
** sources/display.c
*/

#include "my.h"

int			print_usage(int ac, char **av)
{
	if (ac == 2) {
		if (av[1][0] == '-' && av[1][1] == 'h') {
			my_putstr("USAGE\n\t./navy [first_player_pid]");
			my_putstr(" navy positions\nDESCRIPTION\n\tfisrt_");
			my_putstr("player_pid: only for the 2nd player.");
			my_putstr(" pid of the first player\n");
			my_putstr("\tnavy_positions: file representing");
			my_putstr(" the positions of the ships.\n");
			return (1);
		}
	}
	return (0);
}

void 			display_map(char **map)
{
	for (int i = 0; i < 10; i++) {
		my_putstr(map[i]);
		my_putstr("\n");
	}
}

void 			display_two_map(void)
{
	my_putstr("\nmy_positions:\n");
	display_map(info.my_map);
	my_putstr("\nenemy's position\n");
	display_map(info.enemy_map);
}

void 			print_miss_or_hit_for_no_host(int x, int y)
{
	while (info.recu == 0);
	info.value = get_value_from_binary(info.str);
	if (info.value == 1) {
		my_putstr(remove_last_return(info.input));
		my_putstr(": hit\n");
		info.enemy_map[y+1][x*2] = 'x';
	} else if (info.value == 2) {
		my_putstr(remove_last_return(info.input));
		my_putstr(": missed\n");
		info.enemy_map[y+1][x*2] = 'o';
	}
}

void 			print_miss_or_hit_for_host(int x, int y)
{
	my_putchar(x+64);
	my_putchar(y+48);
	if (info.my_map[y+1][x*2] != '.') {
		my_putstr(": hit\n");
		sender(1);
		info.my_map[y+1][x*2] = 'x';
	} else {
		sender(2);
		my_putstr(": missed\n");
		info.my_map[y+1][x*2] = 'o';
	}
}