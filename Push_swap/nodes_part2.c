/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nodes_part2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcarolei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 16:28:30 by pcarolei          #+#    #+#             */
/*   Updated: 2020/02/21 10:47:07 by pcarolei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nodes.h"

int		node_find_max(t_node *root)
{
	int		max;
	t_node	*cur;

	cur = root;
	max = cur->data;
	while (cur->next)
	{
		cur = cur->next;
		if (cur->data > max)
			max = cur->data;
	}
	return (max);
}

int		node_find_min(t_node *root)
{
	int		min;
	t_node	*cur;

	cur = root;
	min = cur->data;
	while (cur->next)
	{
		cur = cur->next;
		if (cur->data < min)
			min = cur->data;
	}
	return (min);
}

t_node	*node_find_by_count(t_node *root, int count)
{
	int		i;
	t_node	*cur;

	i = 1;
	cur = root;
	while ((i < count) && (cur->next))
	{
		cur = cur->next;
		i++;
	}
	return (cur);
}

void	node_free_list(t_node *root)
{
	t_node	*cur;
	t_node	*nxt;

	cur = root;
	while (cur)
	{
		nxt = cur->next;
		free(cur);
		cur = nxt;
	}
}
