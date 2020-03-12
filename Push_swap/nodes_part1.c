/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nodes_part1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcarolei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 16:28:30 by pcarolei          #+#    #+#             */
/*   Updated: 2020/02/21 10:46:47 by pcarolei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nodes.h"

t_node	*node_create(int data)
{
	t_node	*node;

	if (!(node = (t_node *)malloc(sizeof(t_node))))
		return (NULL);
	node->data = data;
	node->next = NULL;
	return (node);
}

int		node_find_max_lesser_than_data(t_node *root, int data)
{
	t_node	*cur;
	int		max;

	cur = root;
	max = node_find_min(root);
	while (cur)
	{
		if ((cur->data > max) && (cur->data < data))
			max = cur->data;
		cur = cur->next;
	}
	return (max);
}

int		node_find_dist_to_data(t_node *root, int data)
{
	t_node	*cur;
	int		dist;

	cur = root;
	dist = 0;
	while ((cur->next) && (cur->data != data))
	{
		cur = cur->next;
		dist++;
	}
	return (dist);
}

int		node_count_nodes_lesser(t_node *root, int data)
{
	t_node	*cur;
	int		count;

	cur = root;
	count = 0;
	while (cur)
	{
		if (cur->data < data)
			count++;
		cur = cur->next;
	}
	return (count);
}

int		node_find_med(t_node *root, int elem_count)
{
	t_node	*cur;
	int		med;

	cur = root;
	med = cur->data;
	while (cur->next)
	{
		if (node_count_nodes_lesser(root, med) == (elem_count / 2))
			return (med);
		cur = cur->next;
		med = cur->data;
	}
	return (med);
}
