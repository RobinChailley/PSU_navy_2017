/*
** EPITECH PROJECT, 2017
** PSU_navy_2017
** File description:
** sending_funcs.c
*/

#include "my.h"

void 			send_values_x_y(void)
{
	read(0, info.input, 3);
	sender(info.input[0] - 64);
	sleep(0.2);
	sender(info.input[1] - 48);
}

int 			get_value(void)
{
	info.recu = 0;
	while (info.recu == 0);
	info.value = get_value_from_binary(info.str);
	return (info.value);
}