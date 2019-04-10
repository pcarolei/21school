NAME = libft

SRC = ./*

all: $(NAME)

$(NAME):
	gcc -Wall -Wextra -Werror -c *.c
	ar -rc libft.a *.o

clean:
	rm -rf *.o

fclean:
	rm -rf libft.a

re: fclean all
