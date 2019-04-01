/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_find.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcarolei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 19:31:47 by pcarolei          #+#    #+#             */
/*   Updated: 2019/02/13 19:31:51 by pcarolei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_list	*ft_list_find(t_list *begin_list, void *data_ref, int (*cmp)())
{
	t_list	*i_list;

	i_list = begin_list;
	while (cmp(i_list->data, data_ref) != 0)
		i_list = i_list->next;
	if (cmp(i_list->data, data_ref) == 0)
		return (i_list);
	else
	{
		i_list = 0;
		return (i_list);
	}
}
