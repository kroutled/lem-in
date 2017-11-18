NAME = lem-in

CC = gcc -Wall -Werror -Wextra

INC = -L libft -lft

SRC = main.c	\
	  rooms.c	\
	  tunnels.c	\
	  frees.c	\
	  looping.c	\
	  moving.c	\

all: $(NAME)

$(NAME):
	make -C libft
	$(CC) $(SRC) $(INC) -o $(NAME)

clean:
	make -C libft clean

fclean:
	make -C libft fclean
	rm -rf $(NAME)

re: fclean all
