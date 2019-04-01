/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_funcs_part_one.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcarolei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/17 18:31:25 by pcarolei          #+#    #+#             */
/*   Updated: 2019/02/17 18:31:26 by pcarolei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "node_struct.h"
#include "other_funcs.h"
#include "node_funcs_part_one_def.h"
#include "node_funcs_part_two.h"
#include <stdlib.h>

t_node	*ft_node_create(int value, char operation)
{
	t_node	*node;

	node = malloc(sizeof(t_node));
	if (node)
	{
		node->value = value;
		node->operation = operation;
		node->next = 0;
	}
	return (node);
}

void	ft_node_push_back(t_node **begin_list, int value, char operation)
{
	t_node *current;
	t_node *new_node;

	current = *begin_list;
	new_node = ft_node_create(value, operation);
	if (current == 0)
		*begin_list = new_node;
	while (current->next != 0)
		current = current->next;
	current->next = new_node;
}

int		ft_node_get_chain_length(t_node *begin_list)
{
	t_node	*i_node;
	int		length;

	i_node = begin_list;
	length = 0;
	while (i_node != 0)
	{
		length++;
		i_node = i_node->next;
	}
	return (length);
}

void	ft_node_evaluate_chain_high_pr_op_helper(t_node *begin_node)
{
	t_node	*cu;
	t_node	*ne;
	t_node	*prev;
	char	last_low_priority_op;

	cu = begin_node;
	prev = cu;
	if (cu->operation == '+' || cu->operation == '-')
		last_low_priority_op = cu->operation;
	else
		last_low_priority_op = '+';
	while (cu->next != 0)
	{
		if (cu->operation != '+' && cu->operation != '-')
		{
			ne->value = ft_other_smplcalc(cu->value, ne->value, cu->operation);
			cu->value = 0;
			cu->operation = last_low_priority_op;
		}
		else
			last_low_priority_op = cu->operation;
		prev = cu;
		cu = cu->next;
		ne = cu->next;
	}
}

int		ft_node_evaluate_chain(t_node *begin_list)
{
	int		res;
	int		operand1;
	int		operand2;
	char	operation;
	t_node	*current;

	res = 0;
	operation = 't';
	current = begin_list;
	ft_node_evaluate_chain_high_pr_op_helper(begin_list);
	while (current != 0)
	{
		if (operation == 't')
			MODE1;
		if (operation != 't')
		{
			if (current->next != '\0')
				MODE2;
			if (current->next == '\0')
				return (res);
		}
	}
	res += ft_other_smplcalc(res, operand2, operation);
	return (res);
}
