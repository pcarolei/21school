/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_front.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcarolei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 15:16:36 by pcarolei          #+#    #+#             */
/*   Updated: 2019/02/12 15:16:40 by pcarolei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_push_front(t_list **begin_list, void *data)
{
	t_list	*new_list;

	if (begin_list != 0)
	{
		new_list = ft_create_elem(data);
		new_list->next = *begin_list;
	}
	else
	{
		new_list = ft_create_elem(data);
		begin_list = &new_list;
	}
}
