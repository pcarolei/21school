/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   edges.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcarolei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 14:20:13 by pcarolei          #+#    #+#             */
/*   Updated: 2019/10/28 14:30:47 by pcarolei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_edge			*edge_create(t_vertex *v1, t_vertex *v2)
{
	t_edge	*edge;

	if (!v1 || !v2)
		return (NULL);
	edge = (t_edge *)malloc(sizeof(t_edge));
	if (!edge)
		return (NULL);
	edge->start = v1;
	edge->end = v2;
	edge->next = NULL;
	return (edge);
}

t_edge			*edges_get_last(t_edge *root_e)
{
	t_edge	*lst;

	lst = root_e;
	while (lst->next)
		lst = lst->next;
	return (lst);
}

static t_edge	*edges_create_ver(t_vertex *root_v, int width)
{
	t_edge		*root_e;
	t_edge		*ptr_e;
	t_vertex	*ptr_v;

	root_e = edge_create(root_v, vertex_get_with_offset(root_v, width));
	ptr_v = root_v->next;
	ptr_e = root_e;
	while (ptr_v && vertex_get_with_offset(ptr_v, width) && root_e)
	{
		ptr_e->next = edge_create(ptr_v, vertex_get_with_offset(ptr_v, width));
		ptr_e = ptr_e->next;
		ptr_v = ptr_v->next;
	}
	return (root_e);
}

static t_edge	*edges_create_hor(t_vertex *root_v, int width)
{
	t_edge		*root_e;
	t_edge		*ptr_e;
	t_vertex	*ptr_v;

	root_e = edge_create(root_v, root_v->next);
	ptr_v = root_v->next;
	ptr_e = root_e;
	while (ptr_v && root_e)
	{
		if (ptr_v->next && ptr_v->next->point->x % width != 0)
		{
			ptr_e->next = edge_create(ptr_v, ptr_v->next);
			ptr_e = ptr_e->next;
		}
		ptr_v = ptr_v->next;
	}
	return (root_e);
}

t_edge			*edges_create(t_vertex *root_v, int width)
{
	t_edge	*root_e_ver;
	t_edge	*root_e_hor;

	root_e_ver = edges_create_ver(root_v, width);
	root_e_hor = edges_create_hor(root_v, width);
	if (!root_e_ver || !root_e_hor)
		return (NULL);
	(edges_get_last(root_e_ver))->next = root_e_hor;
	return (root_e_ver);
}
