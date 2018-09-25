/*
** EPITECH PROJECT, 2018
** killian
** File description:
** description
*/

#include "rfc.h"
#include "server.h"

int client_connection(server_t *server, int efd)
{
	struct sockaddr_in in_client;
	socklen_t in_size = sizeof(in_client);

	int c_fd = accept(server->fd, (struct sockaddr *)&in_client, &in_size);
	if (c_fd == -1)
		return (error_msg("Failed to accept", ERROR, stderr));
	char *ip = inet_ntoa(in_client.sin_addr);
	printf("New client from %s\n", ip);
	send(c_fd, CONNECT_1, strlen(CONNECT_1), 0);
	send(c_fd, CONNECT_2, strlen(CONNECT_2), 0);
	send(c_fd, CONNECT_3, strlen(CONNECT_3), 0);
	return (SUCCESS);
}

int client_received(server_t *server, int fd)
{
	char buffer[500];

	if (recv(fd, buffer, sizeof(buffer), 0) > 0) {
		printf("%s\n", buffer);
		send(fd, "421\r\n", strlen("421\r\n"), 0);
	}
	return (SUCCESS);
}
