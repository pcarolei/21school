/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   points.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcarolei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 14:13:59 by pcarolei          #+#    #+#             */
/*   Updated: 2019/10/28 14:26:54 by pcarolei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_point		*point_create(int x, int y, char *z_str)
{
	t_point	*p;

	p = (t_point *)malloc(sizeof(t_point));
	if (!p)
		return (NULL);
	p->x = x;
	p->y = y;
	p->z = ft_atoi(z_str);
	p->next = NULL;
	return (p);
}

t_point		*points_get_last(t_point *root_p)
{
	t_point	*lst;

	lst = root_p;
	while (lst->next)
		lst = lst->next;
	return (lst);
}

int			map_get_width(char **z_strings)
{
	int	width;

	width = 0;
	while (z_strings[width])
		width++;
	return (width);
}

t_point		*points_delete_width_error(t_point *root_p)
{
	t_point	*cur;
	t_point	*nxt;

	cur = root_p;
	while (cur)
	{
		nxt = cur->next;
		free(cur);
		cur = nxt;
	}
	write(2, "Found wrong line length. Exiting\n", 32);
	return (NULL);
}

t_point		*points_create(int fd, int *width, int *height)
{
	int		y;
	char	*line;
	t_point	*root_p;
	char	**z_strings;

	y = 0;
	line = NULL;
	while (get_next_line(fd, &line) > 0)
	{
		z_strings = ft_strsplit(line, ' ');
		*width = (*width == 0) ? map_get_width(z_strings) : *width;
		if (*width != map_get_width(z_strings))
			return (points_delete_width_error(root_p));
		if (y == 0)
			root_p = read_line(y, z_strings);
		else
			(points_get_last(root_p))->next = read_line(y, z_strings);
		free(line);
		z_strings_free(z_strings);
		y++;
	}
	*height = y - 1;
	return (root_p);
}
