/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_clear.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcarolei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 18:05:00 by pcarolei          #+#    #+#             */
/*   Updated: 2019/02/12 18:05:02 by pcarolei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_clear(t_list **begin_list)
{
	t_list	*list;
	t_list	*buf;

	if ((*begin_list)->next == 0)
		return ;
	else
	{
		list = *begin_list;
		while (list->next->next != 0)
		{
			buf = list->next->next;
			list->next->next = 0;
			list->next = buf;
		}
		list->next = 0;
	}
}
