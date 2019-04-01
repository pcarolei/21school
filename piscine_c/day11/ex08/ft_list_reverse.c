/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_reverse.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcarolei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 19:55:57 by pcarolei          #+#    #+#             */
/*   Updated: 2019/02/12 19:55:59 by pcarolei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_reverse(t_list **begin_list)
{
	t_list	*list;
	t_list	*prev;
	t_list	*next;
	t_list	**new_begin_list;

	list = *begin_list;
	prev = 0;
	new_begin_list = begin_list;
	while (list != 0)
	{
		next = list->next;
		list->next = prev;
		prev = list;
		list = next;
	}
	*new_begin_list = prev;
}
