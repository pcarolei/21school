# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pcarolei <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/03 19:46:39 by pcarolei          #+#    #+#              #
#    Updated: 2020/03/12 19:12:45 by pcarolei         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CHECKER = checker
PUSH_SWAP = push_swap
LIB = libft/libftprintf.a

SRC_CHECKER = nodes_part1.c \
			  nodes_part2.c \
			  stacks_part1.c \
			  stacks_part2.c \
			  stacks_part3.c \
			  stacks_part4.c \
			  operations_part1.c \
			  operations_part2.c \
			  operations_part3.c \
			  read_integer_list.c \
			  checker_read_instructions.c \
			  checker_execute_instructions.c \
			  checker_visualize.c \
			  error_handler.c \
			  checker.c

SRC_PUSH_SWAP = nodes_part1.c \
				nodes_part2.c \
				stacks_part1.c \
				stacks_part2.c \
				stacks_part3.c \
			  	stacks_part4.c \
				operations_part1.c \
				operations_part2.c \
				operations_part3.c \
				read_integer_list.c \
				error_handler.c \
				push_swap.c

HEADERS = checker.h \
		  nodes.h \
		  operations.h \
		  push_swap.h \
		  stacks.h

OBJ_CHECKER = $(SRC_CHECKER:.c=.o)
OBJ_PUSH_SWAP = $(SRC_PUSH_SWAP:.c=.o)

.PHONY: all clean fclean re force

all: $(CHECKER) $(PUSH_SWAP)

$(LIB):
	@make -C libft/

$(CHECKER): $(LIB) $(HEADERS) $(OBJ_CHECKER)
	gcc -Wall -Werror -Wextra $(OBJ_CHECKER) $(LIB) -o $(CHECKER)

$(PUSH_SWAP): $(LIB) $(HEADERS) $(OBJ_PUSH_SWAP)
	gcc -Wall -Werror -Wextra $(OBJ_PUSH_SWAP) $(LIB) -o $(PUSH_SWAP)

# $(OBJ_CHECKER): %.o: %.c
	# gcc -c -Wall -Werror -Wextra $< -o $@

# $(OBJ_PUSH_SWAP): %.o: %.c
	# gcc -c -Wall -Werror -Wextra $< -o $@

%.o: %.c
	gcc -c -Wall -Werror -Wextra $< -o $@

clean:
	@rm -f $(OBJ_CHECKER)
	@rm -f $(OBJ_PUSH_SWAP)
	@make -C libft/ clean

fclean: clean
	@rm -f $(CHECKER)
	@rm -f $(PUSH_SWAP)
	@make -C libft/ fclean

re: fclean all
