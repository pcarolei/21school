/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks_part3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcarolei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 10:28:58 by pcarolei          #+#    #+#             */
/*   Updated: 2020/03/03 03:33:27 by pcarolei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stacks.h"
#include "operations.h"

int		stack_get_shortest_path_to_elem(t_stack *s, int elem)
{
	int		left_path;
	int		right_path;
	t_node	*cur;

	left_path = 0;
	right_path = 0;
	cur = s->top;
	while ((cur) && (cur->data != elem))
	{
		left_path++;
		cur = cur->next;
	}
	while ((cur) && (cur != s->root))
	{
		right_path++;
		cur = cur->next;
	}
	right_path++;
	if (left_path < right_path)
		return (left_path);
	return (right_path);
}

int		stack_b_pick_elem_to_push(t_stack *a, t_stack *b)
{
	int		min_ops;
	int		cur_elem_ops;
	int		elem;
	t_node	*cur;

	if (b->count == 1)
		return (b->top->data);
	min_ops = a->count + b->count;
	cur = b->top;
	while (cur)
	{
		cur_elem_ops = count_ops_to_push_elem(a, b, cur->data);
		if (cur_elem_ops < min_ops)
		{
			min_ops = cur_elem_ops;
			elem = cur->data;
		}
		cur = cur->next;
	}
	return (elem);
}

void	stack_a_shift_lesser(t_stack *a, int lesser)
{
	int	dist;
	int	flag;

	dist = node_find_dist_to_data(a->top, lesser);
	if (dist < a->count / 2)
		flag = 1;
	else
		flag = 0;
	while (a->root->data != lesser)
	{
		if (flag)
			ra(a, 1);
		else
			rra(a, 1);
	}
}

void	stack_b_shift_elem(t_stack *b, int elem)
{
	int	dist;
	int	flag;

	dist = node_find_dist_to_data(b->top, elem);
	if (dist < b->count / 2)
		flag = 1;
	else
		flag = 0;
	while (b->top->data != elem)
	{
		if (flag)
			rb(b, 1);
		else
			rrb(b, 1);
	}
}

void	stack_b_push(t_stack *a, t_stack *b)
{
	int	elem;
	int	lesser;

	elem = stack_b_pick_elem_to_push(a, b);
	lesser = node_find_max_lesser_than_data(a->top, elem);
	stack_a_shift_lesser(a, lesser);
	stack_b_shift_elem(b, elem);
	pa(a, b, 1);
}
