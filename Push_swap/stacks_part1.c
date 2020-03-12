/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks_part1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcarolei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 16:28:10 by pcarolei          #+#    #+#             */
/*   Updated: 2020/03/12 19:12:44 by pcarolei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stacks.h"

void	stack_init(t_stack *stack)
{
	stack->root = NULL;
	stack->top = NULL;
	stack->count = 0;
}

void	stack_init_with_inttab(t_stack *stack_a, int *tab, int size)
{
	int	i;

	i = size - 1;
	while (i >= 0)
	{
		stack_push(stack_a, tab[i]);
		i--;
	}
}

void	stack_push(t_stack *stack, int data)
{
	t_node	*node;

	if (!stack->root)
	{
		stack->root = node_create(data);
		stack->top = stack->root;
		stack->count++;
		return ;
	}
	node = node_create(data);
	node->next = stack->top;
	stack->top = node;
	stack->count++;
}

int		stack_pop(t_stack *stack)
{
	int		top_data;
	t_node	*top_prev;

	if (stack->count == 1)
	{
		top_data = stack->top->data;
		if (stack->top)
			free(stack->top);
		stack->top = NULL;
		stack->root = NULL;
		stack->count--;
		return (top_data);
	}
	top_prev = stack->top->next;
	stack->count--;
	top_data = stack->top->data;
	free(stack->top);
	stack->top = top_prev;
	return (top_data);
}

void	stack_swap(t_stack *stack)
{
	int		data_fst;
	int		data_snd;

	if (!stack->root || (stack->root == stack->top))
		return ;
	data_fst = stack->top->data;
	data_snd = stack->top->next->data;
	stack->top->data = data_snd;
	stack->top->next->data = data_fst;
}
