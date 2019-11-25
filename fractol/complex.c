/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcarolei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 13:02:30 by pcarolei          #+#    #+#             */
/*   Updated: 2019/11/25 18:40:25 by pcarolei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

float		complex_abs(t_complex c)
{
	float	abs;

	abs = c.re * c.re + c.im * c.im;
	return (abs);
}

t_complex	complex_create(float re, float im)
{
	t_complex	c;

	c.re = re;
	c.im = im;
	return (c);
}

void		min_max_create(t_complex *min, t_complex *max, float scale,
							t_mwv *m)
{
	min->re = (-2.0) * scale + m->vp->offset_x / WIN_SIZE_X;
	min->im = (-2.0) * scale + m->vp->offset_y / WIN_SIZE_Y;
	max->re = (2.0) * scale + m->vp->offset_x / WIN_SIZE_X;
	max->im = min->im + (max->re - min->re) * WIN_RATIO;
}

t_complex	c_create(t_complex *factor, int x, int y, t_mwv *m)
{
	t_complex	c;
	t_complex	min;
	t_complex	max;

	min_max_create(&min, &max, m->vp->scale, m);
	c.im = max.im - y * factor->im;
	c.re = min.re + x * factor->re;
	return (c);
}

void		factor_create(t_complex *factor, float scale, t_mwv *m)
{
	t_complex	min;
	t_complex	max;

	min_max_create(&min, &max, scale, m);
	factor->re = (max.re - min.re) / (WIN_SIZE_X - 1);
	factor->im = (max.im - min.im) / (WIN_SIZE_Y - 1);
}
