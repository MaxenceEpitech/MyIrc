/*
** EPITECH PROJECT, 2018
** killian
** File description:
** description
*/

#include "server.h"

int chan_exist(server_t *server, char *name)
{
	chan_t *tmp = server->chan;

	while (tmp != NULL) {
		if (strcmp(name, tmp->name) == 0)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

void new_chan(server_t *server, chan_t *chan)
{
	chan_t *tmp = server->chan;

	while (tmp->next != NULL) {
		tmp = tmp->next;
	}
	tmp->next = chan;
	chan->next = NULL;
}

void add_chan_exist(server_t *server, char *name, int fd)
{
}

int add_to_server(int fd, server_t *server, char *chan_name)
{
	users_t *user;
	chan_t *chan;

	if (chan_exist(server, chan_name))
		add_chan_exist(server, chan_name, fd);
	else {
		chan = malloc(sizeof(chan_t));
		user = malloc(sizeof(users_t));
		if (user == NULL || chan == NULL)
			return (ERROR);
		chan->name = strdup(chan_name);
		new_chan(server, chan);
		user->fd = fd;
		user->dead = 0;
		chan->users = user;
	}
	return (SUCCESS);
}
