NAME = libft.a

all: $(NAME)

$(NAME):
	gcc -Wall -Wextra -Werror -c *.c
	ar -rc $(NAME) *.o

clean:
	rm -rf *.o

fclean: clean
	rm -rf libft.a

re: fclean all
