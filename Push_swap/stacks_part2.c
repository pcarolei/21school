/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks_part2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcarolei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 16:28:10 by pcarolei          #+#    #+#             */
/*   Updated: 2020/03/12 19:20:04 by pcarolei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stacks.h"

void	stack_rotate(t_stack *stack)
{
	t_node	*top_copy;
	t_node	*top_next;
	t_node	*tmp;

	if ((!stack->root) || (stack->count == 1))
		return ;
	if (stack->count == 2)
	{
		stack_rotate_two(stack);
		return ;
	}
	top_copy = node_create(stack->top->data);
	top_next = stack->top->next;
	tmp = stack->top;
	stack->top = top_next;
	stack->root->next = top_copy;
	stack->root = top_copy;
	free(tmp);
}

void	stack_reverse_rotate(t_stack *stack)
{
	t_node	*root_copy;
	t_node	*root_prev;

	if (!stack->root || (stack->count == 1))
		return ;
	root_copy = node_create(stack->root->data);
	root_prev = node_find_by_count(stack->top, stack->count - 1);
	free(stack->root);
	root_prev->next = NULL;
	root_copy->next = stack->top;
	stack->top = root_copy;
	stack->root = root_prev;
}

char	*stack_to_str(t_stack *stack, int num)
{
	char	*str;
	t_node	*cur;

	if (num == 1)
		str = ft_strdup("A: ");
	else
		str = ft_strdup("B: ");
	cur = stack->top;
	while (cur)
	{
		str = ft_strjoinfree(str, ft_itoa(cur->data));
		if (cur->next)
			str = ft_strjoinfree(str, char_to_str(' '));
		cur = cur->next;
	}
	return (str);
}

int		stack_check_if_sorted(t_stack *stack)
{
	t_node	*cur;
	int		data;
	int		min;
	int		max;

	if (stack->top == stack->root)
		return (1);
	min = node_find_min(stack->top);
	max = node_find_max(stack->top);
	if ((stack->top->data != min) && (stack->root->data != max))
		return (0);
	cur = stack->top;
	data = cur->data;
	while (cur->next)
	{
		cur = cur->next;
		if (cur->data < data)
			return (0);
		else
			data = cur->data;
	}
	return (1);
}

int		count_ops_to_push_elem(t_stack *a, t_stack *b, int elem)
{
	int	lesser;
	int	count;

	lesser = node_find_max_lesser_than_data(a->top, elem);
	count = stack_get_shortest_path_to_elem(b, elem);
	count += stack_get_shortest_path_to_elem(a, lesser);
	return (count);
}
