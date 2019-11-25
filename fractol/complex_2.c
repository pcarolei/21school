/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_other.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcarolei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 18:17:32 by pcarolei          #+#    #+#             */
/*   Updated: 2019/11/25 18:21:21 by pcarolei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		z_iter_create(t_complex *z, t_complex *c)
{
	float	temp_re;

	temp_re = z->re * z->re - z->im * z->im + c->re;
	z->im = 2.0 * z->re * z->im + c->im;
	z->re = temp_re;
}

void		burning_ship_z_iter_create(t_complex *z, t_complex *c)
{
	float	temp_re;

	temp_re = z->re * z->re - z->im * z->im + c->re;
	z->im = 2.0 * fabs(z->re * z->im) + c->im;
	z->re = temp_re;
}

void		mandelbar_z_iter_create(t_complex *z, t_complex *c)
{
	float	temp_re;

	temp_re = z->re * z->re - z->im * z->im + c->re;
	z->im = -2.0 * z->re * z->im + c->im;
	z->re = temp_re;
}

void		celtic_z_iter_create(t_complex *z, t_complex *c)
{
	float	temp_re;

	temp_re = fabs(z->re * z->re - z->im * z->im) + c->re;
	z->im = 2.0 * z->re * z->im + c->im;
	z->re = temp_re;
}

void		celtic_mandelbar_z_iter_create(t_complex *z, t_complex *c)
{
	float	temp_re;

	temp_re = fabs(z->re * z->re - z->im * z->im) + c->re;
	z->im = -2.0 * z->re * z->im + c->im;
	z->re = temp_re;
}
