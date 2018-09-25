/*
** EPITECH PROJECT, 2018
** salt
** File description:
** description
*/

#include "server.h"
#include "rfc.h"

static ptr_t cmd_g[10] = {{"give", cmd_connect}, {NULL}};

int cmd_connect(char **tab)
{
	return (SUCCESS);
}

int parse_cmd(char *cmd)
{
	char **tab;

	tab = my_str_to_wordtab(cmd, ' ');
	if (tab != NULL && tab[0] != NULL) {
		for (int i = 0; cmd_g[i].str != NULL; i++) {
			if (strcmp(cmd_g[i].str, tab[0]) == 0)
				return (cmd_g[i].fnc(tab));
		}
	}
	return (SUCCESS);
}
