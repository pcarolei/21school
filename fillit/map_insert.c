/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_insert.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcarolei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/25 20:16:46 by pcarolei          #+#    #+#             */
/*   Updated: 2019/09/25 20:45:33 by pcarolei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static char	map_get(t_map *map, int i, int j)
{
	return (map->data[(map->size * i) + j]);
}

static void	map_set(t_map *map, int i, int j, char c)
{
	map->data[map->size * i + j] = c;
}

int			map_insert(t_map *map, t_tetrimino *tetrimino, int i)
{
	int	t;

	t = 0;
	if (CRD_J < 0)
		return (0);
	while (t < 16)
	{
		if (tetrimino->data[t] == '#' || tetrimino->data[t] == '@')
		{
			if ((MAX(CRD_I + (t / 4), CRD_J + (t % 4)) < map->size) &&
				(map_get(map, CRD_I + (t / 4), CRD_J + (t % 4)) == '.'))
				map_set(map, CRD_I + (t / 4), CRD_J + (t % 4),
						tetrimino->pos + 'A');
			else
				return (0);
		}
		t++;
	}
	tetrimino->is_on_map = 1;
	return (1);
}
