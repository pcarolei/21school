/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcarolei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 10:28:58 by pcarolei          #+#    #+#             */
/*   Updated: 2020/03/09 20:11:21 by pcarolei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error_handler(int *tab, char **instructions)
{
	int	i;

	i = 0;
	free(tab);
	if (instructions)
	{
		while (instructions[i] != NULL)
		{
			free(instructions[i]);
			i++;
		}
		free(instructions);
	}
	write(2, "Error\n", 6);
	exit(1);
}
