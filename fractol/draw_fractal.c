/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_fractal.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcarolei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 17:53:02 by pcarolei          #+#    #+#             */
/*   Updated: 2019/11/25 18:40:15 by pcarolei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		draw_fractal(t_mwv *mwv)
{
	int			x;
	int			y;
	int			i;
	t_complex	c;
	t_complex	z;

	factor_create(&mwv->factor, mwv->vp->scale, mwv);
	y = -1;
	while (++y < WIN_SIZE_Y)
	{
		x = -1;
		while (++x < WIN_SIZE_X)
		{
			c = c_create(&mwv->factor, x, y, mwv);
			z = complex_create(c.re, c.im);
			i = -1;
			while (z.re * z.re + z.im * z.im <= 4 && ++i < mwv->vp->iter_max)
				iter_create(&z, &c, mwv->type);
			image_set_pixel(mwv->image, x, y, calc_color(i, mwv->vp->iter_max));
		}
	}
}
