NAME = bsq

SRC = ./bsq.c ./helpers1.c ./helpers2.c ./helpers3.c ./helpers4.c ./helpers5.c

all: $(NAME)

$(NAME):	
	@gcc -Wall -Wextra -Werror -o $(NAME) $(SRC)
	
clean:
	@rm -f *.o

fclean:
	@rm -f $(NAME)

re: fclean all