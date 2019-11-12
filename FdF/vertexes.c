/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vertexes.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcarolei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 14:17:49 by pcarolei          #+#    #+#             */
/*   Updated: 2019/10/28 14:26:53 by pcarolei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		vertex_calc(t_vertex *v, t_viewport *vp)
{
	t_point	*p;
	int		x;
	int		y;
	int		z;

	p = v->point;
	x = p->x * vp->scale;
	y = p->y * vp->scale;
	z = p->z * vp->d_z;
	v->x = (vp->mode == 'i') ? (cos(0.523599) * (x - y)) : x;
	v->y = (vp->mode == 'i') ? (-z + sin(0.523599) * (x + y)) : y;
	v->x += vp->d_x;
	v->y += vp->d_y;
}

t_vertex	*vertex_create(t_point *p, t_viewport *vp)
{
	t_vertex	*v;

	v = (t_vertex *)malloc(sizeof(t_vertex));
	if (!v)
		return (NULL);
	v->point = p;
	v->next = NULL;
	vertex_calc(v, vp);
	return (v);
}

t_vertex	*vertexes_create(t_point *root_p, t_viewport *vp)
{
	t_vertex	*root_v;
	t_vertex	*ptr_v;
	t_point		*ptr_p;

	root_v = vertex_create(root_p, vp);
	ptr_p = root_p;
	ptr_v = root_v;
	while (ptr_p && root_v)
	{
		ptr_v->next = vertex_create(ptr_p, vp);
		ptr_v = ptr_v->next;
		ptr_p = ptr_p->next;
	}
	return (root_v);
}

t_vertex	*vertex_get_with_offset(t_vertex *v, int offset)
{
	t_vertex	*ptr;

	ptr = v;
	while (ptr && offset > 0)
	{
		ptr = ptr->next;
		offset--;
	}
	return (ptr);
}
