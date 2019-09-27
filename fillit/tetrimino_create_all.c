/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetrimino_create_all.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcarolei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/25 20:26:22 by pcarolei          #+#    #+#             */
/*   Updated: 2019/09/25 20:51:29 by pcarolei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int	new_line_check(int fd)
{
	char	buf[1];
	int		ret;

	ret = read(fd, buf, 1);
	if (ret <= 0)
		return (0);
	if (buf[0] == '\n')
		return (1);
	return (-1);
}

t_tetrimino	*tetrimino_create_all(int fd)
{
	t_tetrimino	*root;
	t_tetrimino	*ptr;
	int			pos;
	int			nlc_res;

	pos = 0;
	root = tetrimino_create(fd, pos);
	if (!root)
		return (NULL);
	ptr = root;
	while (ptr)
	{
		nlc_res = new_line_check(fd);
		if (nlc_res == (-1))
			tetrimino_delete_all(root, 1);
		if (nlc_res == 0)
			break ;
		if (nlc_res == 1)
			ptr->next = tetrimino_create(fd, ++pos);
		if (pos == 26 || !ptr->next)
			tetrimino_delete_all(root, 1);
		ptr = ptr->next;
	}
	return (root);
}
