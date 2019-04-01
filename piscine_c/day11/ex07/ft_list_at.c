/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_at.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcarolei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 19:42:11 by pcarolei          #+#    #+#             */
/*   Updated: 2019/02/12 19:42:14 by pcarolei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_list	*ft_list_at(t_list *begin_list, unsigned int nbr)
{
	unsigned int	i;
	t_list			*list;

	i = 1;
	list = begin_list;
	if (nbr == 0)
	{
		list = 0;
		return (list);
	}
	while (i < nbr)
	{
		if (list->next == 0 && (nbr - i > 1))
		{
			list = 0;
			return (list);
		}
		list = list->next;
		i++;
	}
	return (list);
}
