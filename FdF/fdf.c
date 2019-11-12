/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcarolei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 16:09:46 by pcarolei          #+#    #+#             */
/*   Updated: 2019/10/28 14:29:49 by pcarolei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		fdf(t_point *root_p, t_vertex *root_v, t_edge *root_e,
														t_viewport *vp)
{
	t_mwr	mwr;

	mwr.mlx = mlx_init();
	mwr.win = mlx_new_window(mwr.mlx, WIN_SIZE_X, WIN_SIZE_Y, WIN_TITLE);
	mwr.root_p = root_p;
	mwr.root_v = root_v;
	mwr.root_e = root_e;
	mwr.vp = vp;
	mwr.image = image_create(mwr.mlx);
	mlx_key_hook(mwr.win, deal_key, (void *)(&mwr));
	redraw(&mwr);
	mlx_loop(mwr.mlx);
}

int			main(int ac, char **av)
{
	int			fd;
	t_point		*root_p;
	t_vertex	*root_v;
	t_viewport	*vp;
	t_edge		*root_e;

	if (ac != 2)
		error_wrong_arg_cnt();
	fd = open(av[1], O_RDONLY);
	vp = viewport_create();
	if (fd < 0 || !vp)
		exit(2);
	root_p = points_create(fd, &vp->map_width, &vp->map_height);
	close(fd);
	root_v = (root_p == NULL) ? NULL : vertexes_create(root_p, vp);
	root_e = (root_v == NULL) ? NULL : edges_create(root_v, vp->map_width);
	if (!root_p || !root_v || !root_e)
		exit(3);
	fdf(root_p, root_v, root_e, vp);
	return (0);
}
