/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_fill.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcarolei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/25 20:07:21 by pcarolei          #+#    #+#             */
/*   Updated: 2019/09/25 20:24:39 by pcarolei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static t_map	*map_copy(t_map *map)
{
	t_map	*copy;
	int		i;

	copy = map_create(map->size);
	if (!copy)
		return (NULL);
	i = -1;
	copy->size = map->size;
	while (++i < map->size * map->size)
		copy->data[i] = map->data[i];
	return (copy);
}

static void		map_restore_from_copy(t_map *map, t_map *copy)
{
	int	i;

	i = -1;
	while (++i < map->size * map->size)
		map->data[i] = copy->data[i];
	map_release(copy);
}

void			map_clean_from_letter(t_map *map, char c)
{
	int	i;

	i = 0;
	while (i < map->size * map->size)
	{
		if (map->data[i] == c)
			map->data[i] = '.';
		i++;
	}
}

static t_map	*map_fill_helper(t_map *map, t_map *copy)
{
	map_release(copy);
	return (map);
}

t_map			*map_fill(t_map *map, t_tetrimino *root)
{
	int			i;
	t_tetrimino	*tetrimino;
	t_map		*copy;

	i = -1;
	tetrimino = tetrimino_get_next_unused(root);
	if (!tetrimino)
		return (map);
	if (map_count_dots(map) < tetrimino_get_amount_unused(root) * 4)
		return (NULL);
	while (tetrimino)
	{
		copy = map_copy(map);
		while (++i < map->size * map->size)
		{
			if (map_insert(map, tetrimino, i) && map_fill(map, root))
				return (map_fill_helper(map, copy));
			map_clean_from_letter(map, tetrimino->pos + 'A');
		}
		map_restore_from_copy(map, copy);
		tetrimino->is_on_map = 0;
		tetrimino = tetrimino_get_next_unused(tetrimino->next);
	}
	return (NULL);
}
