/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_other.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcarolei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/25 20:18:05 by pcarolei          #+#    #+#             */
/*   Updated: 2019/09/25 20:24:38 by pcarolei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		map_get_initial_size(t_tetrimino *root)
{
	int	size;
	int	tetrimino_amount;

	size = 2;
	tetrimino_amount = tetrimino_get_amount(root);
	while (size * size < tetrimino_amount * 4)
		size++;
	return (size);
}

t_map	*map_create(int size)
{
	t_map	*map;
	int		i;

	map = (t_map *)malloc(sizeof(t_map) + size * size);
	map->size = size;
	i = 0;
	while (i < size * size)
		map->data[i++] = '.';
	return (map);
}

void	map_release(t_map *map)
{
	free(map);
}

void	map_display(t_map *map)
{
	int	i;

	i = 0;
	if (map->size == 1)
	{
		ft_putchar(map->data[i]);
		ft_putchar('\n');
		return ;
	}
	while (i < map->size * map->size)
	{
		ft_putchar(map->data[i]);
		if (i != 0 && (i + 1) % map->size == 0)
			ft_putchar('\n');
		i++;
	}
}

int		map_count_dots(t_map *map)
{
	int	dots_cnt;
	int	i;

	dots_cnt = 0;
	i = 0;
	while (i < map->size * map->size)
	{
		if (map->data[i] == '.')
			dots_cnt++;
		i++;
	}
	return (dots_cnt);
}
