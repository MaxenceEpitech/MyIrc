/*
** EPITECH PROJECT, 2018
** salut
** File description:
** description
*/

#include "server.h"

server_t *init_list(server_t *server)
{
	server->chan = malloc(sizeof(chan_t));
	if (server->chan == NULL)
		return (NULL);
	server->chan->name = strdup("default");
	printf("Listening on port 4242...\n");
	return (server);
}

server_t *init_server(char **av, server_t *server)
{
	struct sockaddr_in s_in;
	int fd = socket(AF_INET, SOCK_STREAM, getprotobyname("TCP")->p_proto);
	int value = 1;

	setsockopt(fd, SOL_SOCKET, SO_REUSEADDR, &value, sizeof(int));
	s_in.sin_family = AF_INET;
	s_in.sin_port = htons(atoi(av[1]));
	s_in.sin_addr.s_addr = INADDR_ANY;
	if ((fd == -1)
	    || ((bind(fd, (const struct sockaddr *)&s_in, sizeof(s_in))) == -1)
	    || (((listen(fd, 3)) == -1))) {
		return (NULL);
	}
	server->fd = fd;
	return (init_list(server));
}

int main(int ac, char **av)
{
	server_t *server;

	if (ac != 2 || (ac == 2 && strcmp(CMD_HELP, av[1]) == 0))
		return (error_msg(USAGE, SUCCESS, stdout));
	server = malloc(sizeof(server_t));
	if (server == NULL)
		return (error_msg(E_MALLOC, ERROR, stderr));
	server->port = atoi(av[1]);
	if (atoi(av[1]) <= 0)
		return (error_msg(E_PORT_NEG, 0, stdout));
	server = init_server(av, server);
	if (server == NULL)
		return (ERROR);
	loop_server(server);
	return (SUCCESS);
}
