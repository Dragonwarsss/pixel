##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## Make the files
##

SRCFILES  = 	pixel.c		\
		my.c		\

SRCDIR   := .

OBJDIR   := .

OUTDIR   := .

NAME     := libpixel.a

CFLAGS   += -Wextra -Wall -pedantic

CPPFLAGS += -I include

LDFLAGS  +=

OBJ       = $(addprefix $(OBJDIR)/, $(SRCFILES:.c=.o))
SRC       = $(addprefix $(SRCDIR)/, $(SRCFILES))
OUT       = $(OUTDIR)/$(NAME)

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	$(CC) $(CPPFLAGS) $(CFLAGS) -c -o $@ $<

all: $(NAME)

$(NAME): $(OBJ)
#	$(CC) -o $(OUT) $(OBJ) $(LDFLAGS)
	$(AR) rc $(OUT) $(OBJ)
	cp pixel.h ../../include/

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(OUT)

re: fclean all

rc: re
	$(MAKE) clean

.PHONY: all clean fclean re rc run_tests
