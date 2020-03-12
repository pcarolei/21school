# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pcarolei <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/14 07:53:44 by pcarolei          #+#    #+#              #
#    Updated: 2020/02/21 16:24:21 by pcarolei         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
HEADER = libft.h

all: $(NAME)

$(NAME): $(HEADER)
	gcc -c -Wall -Werror -Wextra *.c
	ar rc $(NAME) *.o

clean:
	rm -rf *.o

fclean: clean
	rm -rf $(NAME)

re: fclean all
