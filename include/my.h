/*
** EPITECH PROJECT, 2018
** PSU_2017_navy
** File description:
** my.h
*/

#ifndef MY_H_
#define MY_H_

#include <sys/types.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <fcntl.h>

typedef struct	info_s
{
	struct 	sigaction sa;
	int 	received;
	int 	host;
	int 	enemy_pid;
	int 	connected;
	char 	**my_map;
	char 	**enemy_map;
	char 	*str;
	int 	i;
	int 	value;
	char 	*input;
	int 	recu;
}		info_t;

info_t info;

//LIB//
int 			my_strlen(char *str);
int			my_getnbr(char *str);
void 			my_putchar(char c);
void 			my_putstr(char *str);
void 			my_putnbr(int nb);
void 			my_strcat(char *s1, char *s2);
char 			*my_getfile(char *path);

//DISPLAY//
void 			display_map(char **map);
int			print_usage(int ac, char **av);
void 			display_two_map(void);
void 			print_miss_or_hit_for_no_host(int x, int y);
void 			print_miss_or_hit_for_host(int x, int y);

//MAP_CREATION//
char 			**create_map_with_boat(char *path);
char 			*get_pos(int fd);
char 			**create_map_empty(void);
char			*my_strcpy(char *str);
void 			core_create_map_with_boat(int direction, int y, int x, int i, char *s);

//INIT//
void 			handler_sigaction(int sig, siginfo_t *siginfo, void *a);
void 			get_enemy_pid(void);
void 			create_info(int ac, char **av);

//SEND//
void 			sender(int nb);
int 			get_value_from_binary(char *str);
void 			send_third_and_fourth_bit(int nb);
void 			send_first_and_second_bit(int nb);

//CONNECTION//
void 			establish_connection(char **av);
void 			new_handler(int sig, siginfo_t *siginfo, void *a);

//MAIN//
char 			*remove_last_return(char *str);

//LOOP_GAME//
int 			loop_game_no_host(void);
int 			loop_game_host(void);
int 			loop_game(void);

//SENDING_FUNCS//
void 			send_values_x_y(void);
int 			get_value(void);

//WIN//
int 			win(void);

//ERROR_MANAGEMENT_MAP//
int 			error_management_map(char *path);


#endif /* !MY_H_ */
