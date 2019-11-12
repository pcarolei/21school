/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   misc_other.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcarolei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 14:25:37 by pcarolei          #+#    #+#             */
/*   Updated: 2019/10/28 14:28:39 by pcarolei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		center_image(t_vertex *root_v, t_viewport *vp)
{
	t_vertex	*ptr;

	ptr = root_v;
	get_centering_shift(root_v, vp);
	while (ptr)
	{
		ptr->x += vp->sh_x;
		ptr->y += vp->sh_y;
		ptr = ptr->next;
	}
}

void		change_projection_type(t_edge *root_e, t_viewport *vp)
{
	vp->mode = (vp->mode == 'i') ? 'p' : 'i';
	edges_recalc(root_e, vp);
}

void		redraw(t_mwr *mwr)
{
	image_clear(mwr->image);
	edges_recalc(mwr->root_e, mwr->vp);
	center_image(mwr->root_v, mwr->vp);
	edges_connect(mwr->image, mwr->root_e);
	mlx_put_image_to_window(mwr->mlx, mwr->win, mwr->image->img_ptr, 0, 0);
}

void		deal_key_helper(int key, t_mwr *mwr)
{
	if (key == 126)
		mwr->vp->d_z += 1;
	if (key == 4)
		mwr->vp->d_x -= 10;
	if (key == 37)
		mwr->vp->d_x += 10;
	if (key == 38)
		mwr->vp->d_y += 10;
	if (key == 40)
		mwr->vp->d_y -= 10;
}

int			deal_key(int key, void *param)
{
	t_mwr	*mwr;

	mwr = (t_mwr *)param;
	if (key == 53)
	{
		resources_release(mwr->root_p, mwr->root_v, mwr->root_e, mwr->vp);
		exit(4);
	}
	if (key == 24)
		mwr->vp->scale *= 2;
	if (key == 27)
		if (mwr->vp->scale != 1)
			mwr->vp->scale /= 2;
	if (key == 34 && mwr->vp->mode == 'p')
		mwr->vp->mode = 'i';
	if (key == 35 && mwr->vp->mode == 'i')
		mwr->vp->mode = 'p';
	if (key == 125)
		mwr->vp->d_z -= 1;
	deal_key_helper(key, mwr);
	redraw(mwr);
	return (0);
}
