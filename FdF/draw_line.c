/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcarolei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 14:30:16 by pcarolei          #+#    #+#             */
/*   Updated: 2019/10/28 14:30:18 by pcarolei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	deltas_calc(t_deltas *d, t_edge *e)
{
	d->dx = abs(e->end->x - e->start->x);
	d->sx = (e->start->x < e->end->x) ? (1) : (-1);
	d->dy = abs(e->end->y - e->start->y);
	d->sy = (e->start->y < e->end->y) ? (1) : (-1);
	d->err = ((d->dx > d->dy) ? (d->dx) : (-d->dy)) / 2;
}

void		draw_line(t_img *image, t_edge *e, int color)
{
	int			x;
	int			y;
	int			e2;
	t_deltas	d;

	x = e->start->x;
	y = e->start->y;
	deltas_calc(&d, e);
	while (1)
	{
		image_set_pixel(image, x, y, color);
		if (x == e->end->x && y == e->end->y)
			break ;
		e2 = d.err;
		d.err -= (e2 > (-d.dx)) ? d.dy : 0;
		x += (e2 > (-d.dx)) ? d.sx : 0;
		d.err += (e2 < d.dy) ? d.dx : 0;
		y += (e2 < d.dy) ? d.sy : 0;
	}
}
