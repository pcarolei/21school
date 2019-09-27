/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetrimino_data_validate.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcarolei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/25 20:30:38 by pcarolei          #+#    #+#             */
/*   Updated: 2019/09/25 20:51:30 by pcarolei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int	count_links(int i, char data[16])
{
	int	link_cnt;

	link_cnt = 0;
	if (i > 3 && data[i - 4] == '#')
		link_cnt++;
	if (i < 12 && data[i + 4] == '#')
		link_cnt++;
	if ((i % 4 != 0) && data[i - 1] == '#')
		link_cnt++;
	if (((i + 1) % 4 != 0) && data[i + 1] == '#')
		link_cnt++;
	return (link_cnt);
}

int			tetrimino_data_validate(char data[16])
{
	int	i;
	int	hash_cnt;
	int	link_cnt;

	i = 0;
	hash_cnt = 0;
	link_cnt = 0;
	while (i < 16)
	{
		hash_cnt += ((data[i] == '#') ? 1 : 0);
		link_cnt += ((data[i] == '#') ? count_links(i, data) : 0);
		if ((data[i] != '#' && data[i] != '.') || hash_cnt > 4)
			return (0);
		i++;
	}
	return ((link_cnt == 6 || link_cnt == 8) ? 1 : 0);
}
