/*
** EPITECH PROJECT, 2018
** myirc
** File description:
** description
*/

#include "server.h"

#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/epoll.h>
#include <stdio.h>

int create_epoll(int fd)
{
	int efd;
	int s;
	struct epoll_event *event = calloc(sizeof(struct epoll_event), 1);

	efd = epoll_create1(0);
	if (efd < 0)
		return (-1);
	event->data.fd = fd;
	event->events = EPOLLIN | EPOLLET;
	s = epoll_ctl(efd, EPOLL_CTL_ADD, fd, event);
	if (s == -1)
		exit(ERROR);
	return (efd);
}

void loop_server(server_t *server)
{
	int efd = create_epoll(server->fd);
	struct epoll_event events[MAXEVENTS * sizeof(struct epoll_event)];
	int n;
	int ret = SUCCESS;

	while (ret == SUCCESS) {
		n = epoll_wait(efd, events, MAXEVENTS, -1);
		for (int i = 0; i < n; i++) {
			if ((events[i].events & EPOLLERR)
			    || (events[i].events & EPOLLHUP)
			    || (!(events[i].events & EPOLLIN))) {
				continue;
			} else if (server->fd == events[i].data.fd) {
				ret = client_connection(server, efd);
			} else {
				ret = client_received(server,
						      events[i].data.fd);
			}
		}
	}
}
