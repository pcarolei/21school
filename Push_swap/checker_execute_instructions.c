/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_execute_instructions.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcarolei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 10:28:58 by pcarolei          #+#    #+#             */
/*   Updated: 2020/03/12 19:12:54 by pcarolei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static void	resources_release(int *tab, char **instructions, t_node *top)
{
	int		i;
	t_node	*cur;
	t_node	*nxt;

	free(tab);
	i = 0;
	while (instructions[i])
	{
		free(instructions[i]);
		i++;
	}
	cur = top;
	while (cur)
	{
		nxt = cur->next;
		free(cur);
		cur = nxt;
	}
	free(instructions);
}

static void	stack_b_release(t_node *top)
{
	t_node	*cur;
	t_node	*nxt;

	cur = top;
	while (cur)
	{
		nxt = cur->next;
		free(cur);
		cur = nxt;
	}
}

void		execute_instructions(int *tab, int tab_size, char **instructions,
								t_checker_flags *flags)
{
	t_stack	stack_a;
	t_stack	stack_b;
	int		i;

	stack_init(&stack_a);
	stack_init(&stack_b);
	stack_init_with_inttab(&stack_a, tab, tab_size);
	visualize_stacks(&stack_a, &stack_b, flags, "Initializing stack a");
	i = 0;
	while (instructions[i])
	{
		execute(&stack_a, &stack_b, instructions[i]);
		visualize_stacks(&stack_a, &stack_b, flags, instructions[i]);
		i++;
	}
	if (stack_check_if_sorted(&stack_a) && (stack_b.count == 0))
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	resources_release(tab, instructions, stack_a.top);
	if (stack_b.count > 0)
		stack_b_release(stack_b.top);
}
