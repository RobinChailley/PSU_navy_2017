/*
** EPITECH PROJECT, 2017
** PSU_navy_2017
** File description:
** map_creation.c
*/

#include "my.h"

char			*my_strcpy(char *str)
{
	char *new_str = malloc(sizeof(char) * my_strlen(str));
	for (int i = 0; i < my_strlen(str); i++)
		new_str[i] = str[i];
	return (new_str);
}

char 			**create_map_empty(void)
{
	char **map = malloc(sizeof(char *) * 10);
	for (int i = 0; i < 10; i++)
		map[i] = malloc(sizeof(char) * 17);
	map[0] = my_strcpy(" |A B C D E F G H");
	map[1] = my_strcpy("-+---------------");
	map[2] = my_strcpy("1|. . . . . . . .");
	map[3] = my_strcpy("2|. . . . . . . .");
	map[4] = my_strcpy("3|. . . . . . . .");
	map[5] = my_strcpy("4|. . . . . . . .");
	map[6] = my_strcpy("5|. . . . . . . .");
	map[7] = my_strcpy("6|. . . . . . . .");
	map[8] = my_strcpy("7|. . . . . . . .");
	map[9] = my_strcpy("8|. . . . . . . .");
	return (map);
}

char 			*get_pos(int fd)
{
	char *s = malloc(sizeof(char) * 8);
	read(fd, s, 8);
	return (s);
}

void 			core_create_map(char *s, int x, int y, char **map)
{
	int direction = 0;

	if (s[3] == s[6])
		direction = 1;
	else
		direction = 2;
	for (int i = 0; i < s[0]-48; i++) {
		if (direction == 1) {
			y = 1+(s[3]-48);
			x = (2*(s[2]-64)+2*i);
			map[y][x] = s[0];
		} else if (direction == 2) {
			y = 1+(s[3]-48)+i;
			x = (2*(s[2]-64));
			map[y][x] = s[0];
		}
	}
}

char 			**create_map_with_boat(char *path)
{
	char **map = create_map_empty();
	int fd = open(path, O_RDONLY);
	char *s;
	int x = 0;
	int y = 0;

	error_management_map(path);

	for (int k = 0; k < 4; k++) {
		s = get_pos(fd);
		core_create_map(s, x, y, map);
	}
	return (map);
}