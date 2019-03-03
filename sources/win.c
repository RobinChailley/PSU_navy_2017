/*
** EPITECH PROJECT, 2017
** PSU_navy_2017
** File description:
** win.c
*/

#include "my.h"

int 			win(void)
{
	for (int y = 2; y < 10; y++) {
		for (int x = 2; x < 17 ; x++) {
			if (info.my_map[y][x] < '9' && info.my_map[y][x] > '0')
				return (0);
		}
	}
	return (1);
}