/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_part3.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcarolei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 10:28:58 by pcarolei          #+#    #+#             */
/*   Updated: 2020/03/12 19:12:53 by pcarolei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"

void	rrr(t_stack *a, t_stack *b, int verbose)
{
	rra(a, 0);
	rrb(b, 0);
	if (verbose)
		ft_printf("rrr\n");
}

void	stack_shift_sort(t_stack *a, int max)
{
	int	dist;
	int	flag;

	if (stack_check_if_sorted(a))
		return ;
	dist = node_find_dist_to_data(a->top, max);
	flag = (dist < (a->count / 2));
	while (a->root->data != max)
	{
		if (flag)
			ra(a, 1);
		else
			rra(a, 1);
	}
}

void	execute(t_stack *stack_a, t_stack *stack_b, char *instruction)
{
	if (ft_strcmp(instruction, "sa") == 0)
		sa(stack_a, 0);
	else if (ft_strcmp(instruction, "sb") == 0)
		sb(stack_b, 0);
	else if (ft_strcmp(instruction, "ss") == 0)
		ss(stack_a, stack_b, 0);
	else if ((ft_strcmp(instruction, "pa") == 0) && (stack_b->count > 0))
		pa(stack_a, stack_b, 0);
	else if ((ft_strcmp(instruction, "pb") == 0) && (stack_a->count > 0))
		pb(stack_a, stack_b, 0);
	else if (ft_strcmp(instruction, "ra") == 0)
		ra(stack_a, 0);
	else if (ft_strcmp(instruction, "rb") == 0)
		rb(stack_b, 0);
	else if (ft_strcmp(instruction, "rr") == 0)
		rr(stack_a, stack_b, 0);
	else if (ft_strcmp(instruction, "rra") == 0)
		rra(stack_a, 0);
	else if (ft_strcmp(instruction, "rrb") == 0)
		rrb(stack_b, 0);
	else if (ft_strcmp(instruction, "rrr") == 0)
		rrr(stack_a, stack_b, 0);
}
