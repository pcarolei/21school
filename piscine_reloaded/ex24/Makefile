# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pcarolei <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/02/11 12:29:04 by pcarolei          #+#    #+#              #
#    Updated: 2019/02/11 12:57:52 by pcarolei         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SOURCES = ./srcs/ft_putchar.c ./srcs/ft_putstr.c ./srcs/ft_strcmp.c ./srcs/ft_strlen.c ./srcs/ft_swap.c
HEADERS = ./includes/

all:
	gcc -c -I$(HEADERS) $(SOURCES)
	ar rc libft.a *.o

clean:
	rm -f *.o

fclean: clean
	rm -f libft.a

re: fclean all
