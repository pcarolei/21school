# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pcarolei <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/14 07:53:44 by pcarolei          #+#    #+#              #
#    Updated: 2020/01/14 08:02:25 by pcarolei         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
SRC = bignum.c \
	  bignum2.c \
	  bits_to_epf.c \
	  bits_to_epf2.c \
	  bits_to_numstr.c \
	  bits_to_numstr2.c \
	  colorize.c \
	  colorize2.c \
	  controlchar_to_str.c \
	  dec_to_hex_str.c \
	  float_round.c \
	  floats.c \
	  ft_itoa_base.c \
	  ft_printf.c \
	  handler.c \
	  handler2.c \
	  handler3.c \
	  handler4.c \
	  handler5.c \
	  handler_flags.c \
	  handler_flags2.c \
	  handler_flags3.c \
	  handler_flags4.c \
	  handler_precision_num.c \
	  handler_precision_s.c \
	  handler_width.c \
	  num_to_bits.c \
	  parse_date.c \
	  parse_date2.c \
	  parser.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME):
	gcc -c -Wall -Werror -Wextra libft/*.c
	gcc -c $(SRC)
	ar rc $(NAME) *.o

clean:
	rm -rf *.o libft/*.o

fclean: clean
	rm -rf $(NAME)

re: fclean all
