# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pcarolei <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/25 20:10:19 by pcarolei          #+#    #+#              #
#    Updated: 2019/09/25 22:32:28 by pcarolei         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit
SRCS = fillit.c \
	   error_handling.c \
	   map_fill.c \
	   map_insert.c \
	   map_other.c \
	   tetrimino_create.c \
	   tetrimino_create_all.c \
	   tetrimino_data_validate.c \
	   tetrimino_delete_all.c \
	   tetrimino_other.c
OBJ = $(subst .c,.o,$(SRCS))
LIB = -L libft -lft
HEADER = -I libft
CFLAGS = -Wall -Wextra -Werror
all: $(NAME)
$(NAME): lib $(OBJ)
	gcc $(CFLAGS) $(OBJ) $(LIB) -o $(NAME)
%.o: %.c
	gcc $(CFLAGS) $(HEADER) -c $< -o $@
lib:
	make -C libft
clean:
	make -C libft clean
	rm -f $(OBJ)
fclean: clean
	make -C libft fclean
	rm -f $(NAME)
re: fclean all
.PHONY: all clean fclean re
