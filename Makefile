##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## make
##

CC	=	gcc -Iinclude

NAME	=	pixel

SRCS	=	src/main.c		\
		src/create_image.c	\
		src/init.c		\

OBJS	=	$(SRCS:.c=.o)

CFLAGS	=	-Wall -Wextra

all:	libs $(NAME)

libs:
	$(MAKE) -C lib/pixel/ OUTDIR=.

$(NAME):	$(OBJS)
		$(CC) -o $(NAME) $(OBJS) $(CFLAGS) -Llib/pixel/ -lpixel -lc_graph_prog
clean:
	$(RM) $(OBJS)
	$(MAKE) clean -C lib/pixel/

fclean: clean
	$(RM) $(NAME)
	$(MAKE) fclean -C lib/pixel/

re: fclean all

.PHONY: all clean fclean re
