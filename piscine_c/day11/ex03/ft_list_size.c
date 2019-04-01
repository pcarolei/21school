/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_size.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcarolei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 15:24:02 by pcarolei          #+#    #+#             */
/*   Updated: 2019/02/12 15:24:05 by pcarolei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

int	ft_list_size(t_list *begin_list)
{
	int	count;

	if (begin_list != 0)
		count = 1;
	else
		return (0);
	while (begin_list->next != 0)
	{
		begin_list = begin_list->next;
		count++;
	}
	return (count);
}
