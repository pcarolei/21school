/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   misc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcarolei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 14:23:47 by pcarolei          #+#    #+#             */
/*   Updated: 2019/10/28 14:28:34 by pcarolei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		get_centering_shift(t_vertex *root_v, t_viewport *vp)
{
	t_vertex	*ptr;
	int			min_x;
	int			max_x;
	int			min_y;
	int			max_y;

	ptr = root_v;
	min_x = root_v->x;
	max_x = root_v->x;
	min_y = root_v->y;
	max_y = root_v->y;
	while (ptr->next)
	{
		min_x = (ptr->x < min_x) ? ptr->x : min_x;
		max_x = (ptr->x > max_x) ? ptr->x : max_x;
		min_y = (ptr->y < min_y) ? ptr->y : min_y;
		max_y = (ptr->y > max_y) ? ptr->y : max_y;
		ptr = ptr->next;
	}
	vp->sh_x = (WIN_SIZE_X - (max_x - min_x) / 2) / 2;
	vp->sh_y = (WIN_SIZE_Y - (max_y - min_y) / 2) / 2;
}

t_point		*read_line(int y, char **z_strings)
{
	int		x;
	t_point	*ptr;
	t_point	*root_p;

	x = 0;
	while (z_strings[x])
	{
		if (x == 0)
		{
			ptr = point_create(x, y, z_strings[x]);
			root_p = ptr;
		}
		else
		{
			ptr->next = point_create(x, y, z_strings[x]);
			ptr = ptr->next;
		}
		x++;
	}
	return (root_p);
}

void		z_strings_free(char **z_strings)
{
	int	i;

	i = 0;
	while (z_strings[i])
	{
		free(z_strings[i]);
		i++;
	}
	free(z_strings);
}

void		error_wrong_arg_cnt(void)
{
	ft_putstr("fdf: wrong number of arguments, should be 1");
	exit(1);
}

t_viewport	*viewport_create(void)
{
	t_viewport	*vp;

	vp = (t_viewport *)malloc(sizeof(t_viewport));
	if (!vp)
		return (NULL);
	vp->scale = 7;
	vp->mode = 'i';
	vp->sh_x = 0;
	vp->sh_y = 0;
	vp->d_x = 0;
	vp->d_y = 0;
	vp->d_z = 1;
	vp->a_x = 0;
	vp->a_y = 0;
	vp->a_z = 0;
	return (vp);
}
