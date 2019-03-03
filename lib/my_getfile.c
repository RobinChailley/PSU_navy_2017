/*
** EPITECH PROJECT, 2017
** LIB
** File description:
** my_getfile.c
*/

#include "my.h"

char 		*my_getfile(char *path)
{
	int fd;
	int ret;
	char *buffer = NULL;
	char *file = NULL;

	fd = open(path, O_RDONLY);
	if (fd == -1)
		return ("error");
	buffer = malloc(sizeof(char) * SIZE_BLOCK + 1);
	while ((ret = read(fd, buffer, SIZE_BLOCK)) != 0) {
		if (ret == -1)
			return ("error");
		buffer[ret] = '\0';
		file = my_strcat(file, buffer);
	}
	free(buffer);
	return (file);
}