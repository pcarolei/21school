# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pcarolei <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/14 07:53:44 by pcarolei          #+#    #+#              #
#    Updated: 2020/03/09 20:12:59 by pcarolei         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
HEADER = libft.h
SRC = bignum.c \
bignum2.c \
bits_to_epf.c \
bits_to_epf2.c \
bits_to_numstr.c \
bits_to_numstr2.c \
char_to_str.c \
colorize.c \
colorize2.c \
controlchar_to_str.c \
dec_to_hex_str.c \
float_round.c \
floats.c \
free_2_args.c \
ft_atoi.c \
ft_bzero.c \
ft_isalnum.c \
ft_isalpha.c \
ft_isascii.c \
ft_isdigit.c \
ft_isprint.c \
ft_isspace.c \
ft_itoa.c \
ft_itoa_base.c \
ft_lst_get_length.c \
ft_lstadd.c \
ft_lstaddl.c \
ft_lstdel.c \
ft_lstdelone.c \
ft_lstiter.c \
ft_lstmap.c \
ft_lstnew.c \
ft_max.c \
ft_memalloc.c \
ft_memccpy.c \
ft_memchr.c \
ft_memcmp.c \
ft_memcpy.c \
ft_memdel.c \
ft_memmove.c \
ft_memrchr.c \
ft_memset.c \
ft_min.c \
ft_printf.c \
ft_putchar.c \
ft_putchar_fd.c \
ft_putendl.c \
ft_putendl_fd.c \
ft_putnbr.c \
ft_putnbr_fd.c \
ft_putstr.c \
ft_putstr_fd.c \
ft_strcat.c \
ft_strchr.c \
ft_strclr.c \
ft_strcmp.c \
ft_strcpy.c \
ft_strdel.c \
ft_strdup.c \
ft_strequ.c \
ft_striter.c \
ft_striteri.c \
ft_strjoin.c \
ft_strjoinfree.c \
ft_strlcat.c \
ft_strlen.c \
ft_strmap.c \
ft_strmapi.c \
ft_strncat.c \
ft_strncmp.c \
ft_strncpy.c \
ft_strnequ.c \
ft_strnew.c \
ft_strnstr.c \
ft_strrchr.c \
ft_strreplace.c \
ft_strsplit.c \
ft_strstr.c \
ft_strsub.c \
ft_strtrim.c \
ft_strtrimc.c \
ft_tolower.c \
ft_toupper.c \
get_next_line.c \
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
parser.c \

OBJ = $(SRC:.c=.o)

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJ) $(HEADER)
	ar rc  $(NAME) $(OBJ)

%.o: %.c
	gcc -c -Wall -Werror -Wextra $< -o $@

clean:
	rm -rf *.o

fclean: clean
	rm -rf $(NAME)

re: fclean all
