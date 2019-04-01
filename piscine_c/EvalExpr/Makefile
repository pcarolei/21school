# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pcarolei <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/02/17 22:22:11 by pcarolei          #+#    #+#              #
#    Updated: 2019/02/17 22:22:13 by pcarolei         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = eval_expr
FILES = main.c node_funcs_part_one.c node_funcs_part_two.c other_funcs.c string_funcs_part_one.c string_funcs_part_two.c

all:
	@gcc -Wall -Wextra -Werror $(FILES) -o $(NAME)

clean:
	@rm -f *.o

fclean: clean
	@rm -f $(NAME)

re: fclean all