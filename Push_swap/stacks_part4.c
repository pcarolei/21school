/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks_part4.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcarolei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 16:28:10 by pcarolei          #+#    #+#             */
/*   Updated: 2020/03/12 19:12:49 by pcarolei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stacks.h"

void	stack_rotate_two(t_stack *stack)
{
	t_node	*top_copy;
	t_node	*root_copy;

	top_copy = node_create(stack->top->data);
	root_copy = node_create(stack->root->data);
	free(stack->top);
	free(stack->root);
	root_copy->next = top_copy;
	top_copy->next = NULL;
	stack->top = root_copy;
	stack->root = top_copy;
}
