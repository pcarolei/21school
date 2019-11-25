/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_other.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcarolei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 18:24:55 by pcarolei          #+#    #+#             */
/*   Updated: 2019/11/25 18:59:16 by pcarolei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		fractol_name_check(char *cmd_arg)
{
	if (!ft_strcmp(cmd_arg, "mandelbrot") ||
		!ft_strcmp(cmd_arg, "julia") ||
		!ft_strcmp(cmd_arg, "burning_ship") ||
		!ft_strcmp(cmd_arg, "mandelbar") ||
		!ft_strcmp(cmd_arg, "celtic_mandelbrot") ||
		!ft_strcmp(cmd_arg, "celtic_mandelbar") ||
		!ft_strcmp(cmd_arg, "celtic_perpendicular") ||
		!ft_strcmp(cmd_arg, "perpendicular_mandelbrot") ||
		!ft_strcmp(cmd_arg, "perpendicular_burning_ship") ||
		!ft_strcmp(cmd_arg, "perpendicular_buffalo"))
		return (1);
	return (0);
}

int		display_usage(void)
{
	write(1, "wrong arg. possible options:\n", 29);
	write(1, "mandelbrot\n", 11);
	write(1, "julia\n", 6);
	write(1, "burning_ship\n", 13);
	write(1, "mandelbar\n", 10);
	write(1, "celtic_mandelbar\n", 17);
	write(1, "celtic_mandelbrot\n", 18);
	write(1, "celtic_perpendicular\n", 21);
	write(1, "perpendicular_mandelbrot\n", 25);
	write(1, "perpendicular_burning_ship\n", 27);
	write(1, "perpendicular_buffalo\n", 22);
	exit(0);
}

void	redraw(t_mwv *mwv)
{
	int		i;

	i = 0;
	image_clear(mwv->image);
	if (!ft_strcmp(mwv->type, "julia"))
		julia_wrapper(mwv);
	else
		draw_fractal(mwv);
	mlx_put_image_to_window(mwv->mlx, mwv->win, mwv->image->img_ptr, 0, 0);
	mlx_string_put(mwv->mlx, mwv->win, 0, WIN_SIZE_Y - 40,
					0xFFFFFF, "W/A/S/D - move image");
	mlx_string_put(mwv->mlx, mwv->win, 0, WIN_SIZE_Y - 20,
					0xFFFFFF, "[/] - change iterations count");
}

int		deal_key(int key, void *param)
{
	t_mwv	*mwv;

	mwv = (t_mwv *)param;
	if (key == 53)
		exit(0);
	if (key == 24)
		mwv->vp->scale *= 0.9;
	if (key == 27)
		mwv->vp->scale /= 0.9;
	if (key == 13)
		mwv->vp->offset_y += 50 * mwv->vp->scale;
	if (key == 1)
		mwv->vp->offset_y -= 50 * mwv->vp->scale;
	if (key == 0)
		mwv->vp->offset_x -= 50 * mwv->vp->scale;
	if (key == 2)
		mwv->vp->offset_x += 50 * mwv->vp->scale;
	if (key == 33)
		mwv->vp->iter_max -= 10;
	if (key == 30)
		mwv->vp->iter_max += 10;
	redraw(mwv);
	return (0);
}
