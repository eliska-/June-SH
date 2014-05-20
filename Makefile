##
## Makefile for Minishell2 in /home/benaro_k/rendu/PSU_2013_minishell2
## 
## Made by Kevin BENAROCHE
## Login   <benaro_k@epitech.net>
## 
## Started on  Mon Jan  6 18:06:17 2014 Kevin BENAROCHE
## Last update Tue May 20 14:19:18 2014 Kevin BENAROCHE
##

SRC=    main.c \
	mysh.c \
	get_next_line.c \
	builtins.c \
	functions.c \
	unsetenv.c \
	setenv.c \
	get_env.c \
	pure_str.c \
	aggreg.c \
	echo.c

NAME=	mysh

OBJ=	$(SRC:.c=.o)

CC=	cc -o $(NAME) -g

all:	$(NAME)

$(NAME):	$(OBJ)
	$(CC) $(OBJ)
clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean all

.PHONY:	all clean fclean re
