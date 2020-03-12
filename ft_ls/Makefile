# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pcarolei <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/14 07:53:44 by pcarolei          #+#    #+#              #
#    Updated: 2020/03/05 12:16:14 by pcarolei         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_ls

HEADER = ft_ls.h

LIB = libft/libftprintf.a

SRC = ft_ls.c \
	  command_line_args_parser.c \
	  display.c \
	  display_file.c \
	  utils_part1.c \
	  utils_part2.c \
	  utils_part3.c \
	  utils_part4.c \
	  sorts.c \
	  error.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(LIB):
	@make -C libft/

$(NAME): $(LIB) $(HEADER) $(SRC)
	gcc -Wall -Werror -Wextra -c $(SRC)
	gcc -Wall -Werror -Wextra $(OBJ) $(LIB) -o $(NAME)

clean:
	@rm -f $(OBJ)
	@make -C libft/ clean

fclean: clean
	@rm -f $(NAME)
	@make -C libft/ fclean

re: fclean all
