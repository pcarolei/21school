/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_visualize.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcarolei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 10:28:58 by pcarolei          #+#    #+#             */
/*   Updated: 2020/02/21 10:31:03 by pcarolei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static void	visualize_stacks_color(t_stack *stack_a, t_stack *stack_b,
															char *instruction)
{
	char	*stack_a_str;
	char	*stack_b_str;

	ft_printf("{cyan}%s{eoc}\n", BORDER);
	ft_printf("{green}Executing{eoc} {magenta}%s{eoc}\n", instruction);
	ft_printf("{blue}%s{eoc}\n", stack_a_str = stack_to_str(stack_a, 1));
	ft_printf("{red}%s{eoc}\n", stack_b_str = stack_to_str(stack_b, 2));
	free(stack_a_str);
	free(stack_b_str);
}

void		visualize_stacks(t_stack *stack_a, t_stack *stack_b,
									t_checker_flags *flags, char *instruction)
{
	char	*stack_a_str;
	char	*stack_b_str;

	if (flags->v_flag == 0)
		return ;
	if (flags->c_flag == 1)
	{
		visualize_stacks_color(stack_a, stack_b, instruction);
		return ;
	}
	ft_printf("%s\n", BORDER);
	ft_printf("Executing %s\n", instruction);
	ft_printf("%s\n", stack_a_str = stack_to_str(stack_a, 1));
	ft_printf("%s\n", stack_b_str = stack_to_str(stack_b, 2));
	free(stack_a_str);
	free(stack_b_str);
}
