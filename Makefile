##
## EPITECH PROJECT, 2018
## cpp
## File description:
## cpp
##

NAME		=	server

CC		=	gcc

CFLAGS		+=	-I ./include -g3 #-Wall -Wextra -Werror

RM		=	rm -f

SRCS		=	src/main.c 			\
			src/utils.c			\
			src/parser.c			\
			src/serv.c			\
			src/connection.c		\
			src/my_str_to_wordtab.c		\
			src/command.c

OBJS		=	$(SRCS:.c=.o)

all:		$(NAME)

$(NAME):	$(OBJS)
		$(CC) -o $(NAME) $(OBJS)

clean:
		$(RM) $(OBJS)

fclean:		clean
		$(RM) $(NAME)

re:		fclean all

.PHONY:		all clean fclean re
