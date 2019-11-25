/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcarolei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/23 16:08:13 by pcarolei          #+#    #+#             */
/*   Updated: 2019/11/25 18:31:06 by pcarolei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	calc_color(int i, int iter_max)
{
	float	t;
	int		color;
	int		red;
	int		green;
	int		blue;

	t = (float)i / iter_max;
	red = (int)(9 * (1 - t) * pow(t, 3) * 255);
	green = (int)(15 * (1 - t) * pow(t, 2) * 255);
	blue = (int)(8.5 * (1 - t) * pow(t, 3) * 255);
	color = (red << 16 | green << 8 | blue);
	return (color);
}
