NAME = libft.a

all: $(NAME)

$(NAME):
	gcc -Wall -Wextra -Werror -c *.c
	ar -rc $(NAME) *.o

clean:
	rm -rf *.o

fclean:
	rm -rf *.o
	rm -rf libft.a

re: fclean all
