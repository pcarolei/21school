/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcarolei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 10:28:58 by pcarolei          #+#    #+#             */
/*   Updated: 2020/03/03 03:25:57 by pcarolei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "operations.h"
# include "libft/libft.h"
# define BORDER "--------------------------------------------------------"

typedef struct	s_checker_flags
{
	int	v_flag;
	int	c_flag;
}				t_checker_flags;

char			**read_instructions(void);
void			visualize_stacks(t_stack *stack_a, t_stack *stack_b,
								t_checker_flags *flags, char *instruction);
void			execute_instructions(int *tab, int tab_size,
								char **instructions, t_checker_flags *flags);
int				*read_integer_list(int ac, char **av, int shift);
void			error_handler(int *tab, char **instructions);

#endif
