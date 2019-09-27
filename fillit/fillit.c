/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcarolei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/25 20:08:52 by pcarolei          #+#    #+#             */
/*   Updated: 2019/09/25 20:19:08 by pcarolei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	fillit(t_tetrimino *root)
{
	int		size;
	t_map	*map;
	t_map	*res_map;

	size = map_get_initial_size(root);
	map = map_create(size);
	res_map = NULL;
	while (!(res_map != map_fill(map, root)))
	{
		map_release(map);
		map = map_create(++size);
	}
	map_display(map);
	map_release(map);
	tetrimino_delete_all(root, 0);
}

int		main(int ac, char **av)
{
	int			fd;
	t_tetrimino	*root;

	if (ac != 2 || !av)
		return (display_usage());
	fd = open(av[1], O_RDONLY);
	if (!fd)
		return (display_error());
	root = tetrimino_create_all(fd);
	if (!root)
		display_error();
	fillit(root);
	return (0);
}
