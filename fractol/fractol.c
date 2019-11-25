/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcarolei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 18:24:26 by pcarolei          #+#    #+#             */
/*   Updated: 2019/11/25 18:55:21 by pcarolei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_vp	*viewport_create(void)
{
	t_vp	*vp;

	if (!(vp = (t_vp *)malloc(sizeof(t_vp))))
		return (NULL);
	vp->offset_x = 0;
	vp->offset_y = 0;
	vp->scale = 1.0;
	vp->iter_max = ITER_MAX;
	vp->mouse_x = 1;
	vp->mouse_y = 1;
	return (vp);
}

int		mouse_move(int x, int y, void *param)
{
	t_mwv	*mwv;

	mwv = (t_mwv *)param;
	mwv->vp->mouse_x = x;
	mwv->vp->mouse_y = y;
	if (!ft_strcmp(mwv->type, "julia"))
		redraw(mwv);
	return (0);
}

int		mouse_press(int button, int x, int y, void *param)
{
	t_mwv	*mwv;

	UNUSED(x);
	UNUSED(y);
	mwv = (t_mwv *)param;
	if (button == 5)
		mwv->vp->scale *= 0.9;
	else if (button == 4)
		mwv->vp->scale /= 0.9;
	redraw(mwv);
	return (0);
}

void	fractol(char *type)
{
	t_mwv	mwv;

	mwv.mlx = mlx_init();
	mwv.win = mlx_new_window(mwv.mlx, WIN_SIZE_X, WIN_SIZE_Y, WIN_TITLE);
	mwv.vp = viewport_create();
	mwv.image = image_create(mwv.mlx);
	mwv.type = type;
	redraw(&mwv);
	mlx_key_hook(mwv.win, deal_key, (void *)(&mwv));
	mlx_hook(mwv.win, 6, 0, mouse_move, (void *)(&mwv));
	mlx_hook(mwv.win, 4, 0, mouse_press, (void *)(&mwv));
	mlx_loop(mwv.mlx);
}

int		main(int ac, char **av)
{
	UNUSED(av);
	if (ac != 2 || !fractol_name_check(av[1]))
		display_usage();
	fractol(av[1]);
	return (0);
}
