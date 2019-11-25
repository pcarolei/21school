/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcarolei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 18:18:18 by pcarolei          #+#    #+#             */
/*   Updated: 2019/11/25 19:03:06 by pcarolei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		celtic_perpendicular_z_iter_create(t_complex *z, t_complex *c)
{
	float	temp_re;

	temp_re = fabs(z->re * z->re - z->im * z->im) + c->re;
	z->im = -2.0 * fabs(z->re) * z->im + c->im;
	z->re = temp_re;
}

void		perpendicular_mandelbrot_z_iter_create(t_complex *z, t_complex *c)
{
	float	temp_re;

	temp_re = z->re * z->re - z->im * z->im + c->re;
	z->im = -2.0 * fabs(z->re) * z->im + c->im;
	z->re = temp_re;
}

void		perpendicular_bship_z_iter_create(t_complex *z, t_complex *c)
{
	float	temp_re;

	temp_re = z->re * z->re - z->im * z->im + c->re;
	z->im = -2.0 * z->re * fabs(z->im) + c->im;
	z->re = temp_re;
}

void		perpendicular_buffalo_z_iter_create(t_complex *z, t_complex *c)
{
	float	temp_re;

	temp_re = fabs(z->re * z->re - z->im * z->im) + c->re;
	z->im = -2.0 * z->re * fabs(z->im) + c->im;
	z->re = temp_re;
}

void		iter_create(t_complex *z, t_complex *c, char *type)
{
	if (!ft_strcmp(type, "mandelbrot") || !ft_strcmp(type, "julia"))
		z_iter_create(z, c);
	else if (!ft_strcmp(type, "burning_ship"))
		burning_ship_z_iter_create(z, c);
	else if (!ft_strcmp(type, "mandelbar"))
		mandelbar_z_iter_create(z, c);
	else if (!ft_strcmp(type, "celtic_mandelbrot"))
		celtic_z_iter_create(z, c);
	else if (!ft_strcmp(type, "celtic_mandelbar"))
		celtic_mandelbar_z_iter_create(z, c);
	else if (!ft_strcmp(type, "celtic_perpendicular"))
		celtic_perpendicular_z_iter_create(z, c);
	else if (!ft_strcmp(type, "perpendicular_mandelbrot"))
		perpendicular_mandelbrot_z_iter_create(z, c);
	else if (!ft_strcmp(type, "perpendicular_burning_ship"))
		perpendicular_bship_z_iter_create(z, c);
	else if (!ft_strcmp(type, "perpendicular_buffalo"))
		perpendicular_buffalo_z_iter_create(z, c);
}
