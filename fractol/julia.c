/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcarolei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/23 16:06:32 by pcarolei          #+#    #+#             */
/*   Updated: 2019/11/25 18:42:19 by pcarolei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void		k_create(t_mwv *mwv, t_complex *k)
{
	float	x;
	float	y;

	x = (float)mwv->vp->mouse_x;
	y = (float)mwv->vp->mouse_y;
	k->re = 4 * (x / WIN_SIZE_X - 0.5);
	k->im = 4 * ((WIN_SIZE_Y - y) / WIN_SIZE_Y - 0.5);
}

static void		julia(t_mwv *mwv, t_complex k)
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
			{
				z_iter_create(&z, &k);
			}
			image_set_pixel(mwv->image, x, y, calc_color(i, mwv->vp->iter_max));
		}
	}
}

void			julia_wrapper(t_mwv *mwv)
{
	t_complex	k;

	k_create(mwv, &k);
	julia(mwv, k);
}
