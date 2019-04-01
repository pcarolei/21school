/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcarolei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 15:32:21 by pcarolei          #+#    #+#             */
/*   Updated: 2019/02/07 15:32:22 by pcarolei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	i;

	if (min >= max)
		return (0);
	range[0] = (int*)malloc(sizeof(int) * (max - min));
	i = 0;
	while (max - min > i)
	{
		range[0][i] = min + i;
		i++;
	}
	return (sizeof(int) * (max - min));
}
