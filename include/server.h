/*
** EPITECH PROJECT, 2018
** 
** File description:
** 
*/

#ifndef _SERVER_H_
#define _SERVER_H_

#include <sys/time.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <sys/ioctl.h>
#include <sys/poll.h>
#include <netdb.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define CMD_HELP "-help"
#define OVERFLOW "2147483648"

#define USAGE "USAGE: ./server port"
#define E_MALLOC "Error : Malloc fail."
#define E_PORT_NEG "Wrong port. Port has to be positif."
#define E_PORT_OVERFLOW "Wrong port. Port overflow."

#define ERROR 84
#define SUCCESS 0

#define MAXEVENTS 5

typedef struct users_s {
	char *chanel;
	char *nickname;
	char *pseudo;
	char *host_name;
	char *buffer;
	int fd;
	int port;
	int dead;
	struct users_s *next;
} users_t;

typedef struct chan_s {
	char *name;
	users_t *users;
	struct chan_s *next;
} chan_t;

typedef struct server_s {
	int port;
	int fd;
	chan_t *chan;
} server_t;

typedef struct ptr_s {
	char *str;
	int (*fnc)(char **);
} ptr_t;

int create_epoll(int);
void loop_server(server_t *);

int error_msg(char *, int, FILE *);

int add_to_server(int, server_t *, char *);
int remove_user(int, server_t *);

char **my_str_to_wordtab(char *, char);

int parse_cmd(char *);

int cmd_connect(char **);

int client_connection(server_t *, int);
int client_received(server_t *, int);

#endif /* _SERVER_H_ */
