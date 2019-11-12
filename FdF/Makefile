# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pcarolei <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/28 14:48:54 by pcarolei          #+#    #+#              #
#    Updated: 2019/10/28 14:51:43 by pcarolei         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf
CC = gcc
CFLAGS = -Wall -Wextra -Werror
HEAD = fdf.h
SRC = fdf.c \
	  image.c \
	  resources_release.c \
	  draw_line.c \
	  points.c \
	  vertexes.c \
	  edges.c \
	  edges_other.c \
	  misc.c \
	  misc_other.c
OBJ = $(patsubst %.c,%.o, $(SRC))
all: $(NAME)
$(NAME): $(OBJ) $(HEAD)
	make -C libft/
	$(CC) $(CFLAGS) -c $(SRC)
	$(CC) -o $(NAME) $(OBJ) -lm -L libft/ -lft -lmlx \
		                             -framework OpenGL -framework AppKit
clean:
	make -C libft clean
	rm -f $(OBJ)
fclean: clean
	make -C libft fclean
	rm -f $(NAME)
re: fclean all
.PHONY: all clean fclean re
