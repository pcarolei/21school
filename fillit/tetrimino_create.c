/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetrimino_create.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcarolei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/25 20:27:42 by pcarolei          #+#    #+#             */
/*   Updated: 2019/09/25 20:51:28 by pcarolei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int	tetrimino_data_read(int fd, char data[16])
{
	int		i;
	int		n;
	int		ret;
	char	buf[20];

	i = 0;
	n = 0;
	ret = read(fd, buf, 20);
	if (ret < 19 || (ret == 20 && buf[19] != '\n'))
		return (0);
	while (i < 19)
	{
		if (buf[i] != '\n')
		{
			data[n] = buf[i];
			n++;
		}
		i++;
	}
	return (1);
}

static void	tetrimino_move(char data[16])
{
	int i;
	int top;
	int left;
	int	offset;

	i = -1;
	top = 4;
	left = 4;
	while (++i < 16)
	{
		if (data[i] == '#' && (i / 4 < top))
			top = i / 4;
		if (data[i] == '#' && (i % 4 < left))
			left = i % 4;
	}
	offset = top * 4 + left;
	i = -1;
	while ((++i) < 16 - offset)
		data[i] = data[i + offset];
	i--;
	while ((i < 16) && (++i))
		data[i] = '.';
}

static int	tetrimino_get_offset_left(t_tetrimino *tetrimino)
{
	int	offset;

	offset = 0;
	while (tetrimino->data[offset] != '#' && offset < 4)
		offset++;
	return (offset);
}

t_tetrimino	*tetrimino_create(int fd, int pos)
{
	t_tetrimino	*tetrimino;

	tetrimino = (t_tetrimino *)malloc(sizeof(t_tetrimino));
	if (!tetrimino)
		return (NULL);
	if (!tetrimino_data_read(fd, tetrimino->data) ||
			!tetrimino_data_validate(tetrimino->data))
	{
		free(tetrimino);
		return (NULL);
	}
	tetrimino_move(tetrimino->data);
	tetrimino->pos = pos;
	tetrimino->is_on_map = 0;
	tetrimino->next = NULL;
	tetrimino->offset = tetrimino_get_offset_left(tetrimino);
	return (tetrimino);
}
