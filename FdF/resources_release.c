/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resources_release.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcarolei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 01:14:25 by pcarolei          #+#    #+#             */
/*   Updated: 2019/10/28 14:35:28 by pcarolei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	points_delete(t_point *root_p)
{
	t_point	*cur;
	t_point	*nxt;

	cur = root_p;
	while (cur)
	{
		nxt = cur->next;
		free(cur);
		cur = nxt;
	}
}

static void	vertexes_delete(t_vertex *root_v)
{
	t_vertex	*cur;
	t_vertex	*nxt;

	cur = root_v;
	while (cur)
	{
		nxt = cur->next;
		free(cur);
		cur = nxt;
	}
}

static void	edges_delete(t_edge *root_e)
{
	t_edge	*cur;
	t_edge	*nxt;

	cur = root_e;
	while (cur)
	{
		nxt = cur->next;
		free(cur);
		cur = nxt;
	}
}

void		resources_release(t_point *root_p, t_vertex *root_v,
												t_edge *root_e, t_viewport *vp)
{
	if (root_p)
		points_delete(root_p);
	if (root_v)
		vertexes_delete(root_v);
	if (root_e)
		edges_delete(root_e);
	if (vp)
		free(vp);
}
