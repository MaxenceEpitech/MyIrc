/*
** EPITECH PROJECT, 2018
** aze
** File description:
** description
*/

#include "server.h"

int error_msg(char *str, int ret, FILE *file)
{
	if (str != NULL)
		fprintf(file, "%s\n", str);
	return (ret);
}
