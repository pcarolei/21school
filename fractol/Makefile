# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pcarolei <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/28 14:48:54 by pcarolei          #+#    #+#              #
#    Updated: 2019/11/25 18:30:32 by pcarolei         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol
CC = gcc
CFLAGS = -Wall -Wextra -Werror
HEAD = fractol.h
SRC = fractol.c \
	  fractol_other.c \
	  color.c \
	  complex.c \
	  complex_2.c \
	  complex_3.c \
	  draw_fractal.c \
	  julia.c \
	  image.c
OBJ = $(patsubst %.c,%.o, $(SRC))
all: $(NAME)
$(NAME): $(OBJ) $(HEAD)
	make -C libft/
	$(CC) $(CFLAGS) -c $(SRC)
	$(CC) -o $(NAME) $(OBJ) -lm -L libft/ -lft -lmlx \
		                    -framework OpenGL -framework AppKit \
							-O3
clean:
	make -C libft clean
	rm -f $(OBJ)
fclean: clean
	make -C libft fclean
	rm -f $(NAME)
re: fclean all
.PHONY: all clean fclean re
