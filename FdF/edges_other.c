/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   edges_other.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcarolei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 14:22:25 by pcarolei          #+#    #+#             */
/*   Updated: 2019/10/28 14:23:33 by pcarolei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		edges_recalc(t_edge *root_e, t_viewport *vp)
{
	t_edge	*ptr;

	ptr = root_e;
	while (ptr)
	{
		vertex_calc(ptr->start, vp);
		vertex_calc(ptr->end, vp);
		ptr = ptr->next;
	}
}

void		edges_connect(t_img *image, t_edge *root_e)
{
	t_edge	*ptr;
	int		color;

	ptr = root_e;
	while (ptr)
	{
		color = ((ptr->start->point->z || ptr->end->point->z) ? C1 : C2);
		draw_line(image, ptr, color);
		ptr = ptr->next;
	}
}
