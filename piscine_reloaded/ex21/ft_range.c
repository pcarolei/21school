/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcarolei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 14:49:13 by pcarolei          #+#    #+#             */
/*   Updated: 2019/02/07 14:49:15 by pcarolei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int *arr;
	int	i;

	if (min >= max)
		return (NULL);
	arr = (int*)malloc(sizeof(int) * (max - min));
	i = 0;
	while (max - min > i)
	{
		arr[i] = min + i;
		i++;
	}
	return (arr);
}
