/*
** EPITECH PROJECT, 2017
** LIB
** File description:
** my.h
*/

#ifndef MY_H_
#define MY_H_

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define SIZE_BLOCK 4096

int		my_getnbr(char *str);
void		my_putchar(char c);
void 		my_putnbr(int nb);
void 		my_putstr(char *str);
char 		*my_strcat(char *s1, char *s2);
int 		my_strlen(char *str);
char 		*my_getfile(char *path);

#endif /* !MY_H_ */
