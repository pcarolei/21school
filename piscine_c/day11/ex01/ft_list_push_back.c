/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_back.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcarolei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 14:21:16 by pcarolei          #+#    #+#             */
/*   Updated: 2019/02/12 15:11:19 by pcarolei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_push_back(t_list **begin_list, void *data)
{
	t_list	*new_list;

	if (begin_list != 0)
	{
		new_list = ft_create_elem(data);
		(*begin_list)->next = new_list;
	}
	else
	{
		new_list = ft_create_elem(data);
		*begin_list = new_list;
	}
}
