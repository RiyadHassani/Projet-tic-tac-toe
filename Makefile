NAME = tic-tac-toe

SRCS = main.c \
	afficher.c \
	joueur.c \
	ordinateur.c \
	verif.c \

CFLAGS = -Wall -Wextra -O2

all: $(NAME)

$(NAME): $(SRCS)
	gcc $(CFLAGS) $(SRCS) -o $(NAME)

fclean:
	rm -f $(NAME)


