/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetrimino_other.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcarolei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/25 20:38:42 by pcarolei          #+#    #+#             */
/*   Updated: 2019/09/25 20:51:31 by pcarolei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_tetrimino	*tetrimino_get_next_unused(t_tetrimino *cur)
{
	while (cur && cur->is_on_map)
		cur = cur->next;
	return (cur);
}

int			tetrimino_get_amount(t_tetrimino *root)
{
	t_tetrimino	*ptr;

	ptr = root;
	while (ptr->next)
		ptr = ptr->next;
	return (ptr->pos + 1);
}

int			tetrimino_put(t_map *map, t_tetrimino *tetrimino)
{
	int			i;
	t_tetrimino	*ptr;

	i = 0;
	ptr = tetrimino->next;
	while (i < (map->size * map->size))
	{
		if (map_insert(map, tetrimino, i))
			return (i);
		else
			map_clean_from_letter(map, tetrimino->pos + 'A');
		i++;
	}
	return (-1);
}

int			tetrimino_get_amount_unused(t_tetrimino *root)
{
	t_tetrimino	*ptr;
	int			unused;

	ptr = root;
	unused = 0;
	while (ptr)
	{
		if (ptr->is_on_map == 0)
			unused++;
		ptr = ptr->next;
	}
	return (unused);
}
