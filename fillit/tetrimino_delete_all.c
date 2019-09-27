/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetrimino_delete_all.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcarolei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/25 20:34:35 by pcarolei          #+#    #+#             */
/*   Updated: 2019/09/25 20:51:30 by pcarolei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	tetrimino_delete_all(t_tetrimino *root, int err_opt)
{
	t_tetrimino	*next;

	while (root)
	{
		next = root->next;
		free(root);
		root = next;
	}
	if (err_opt == 1)
		display_error();
}
