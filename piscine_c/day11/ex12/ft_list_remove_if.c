/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_remove_if.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcarolei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 19:34:45 by pcarolei          #+#    #+#             */
/*   Updated: 2019/02/13 20:13:31 by pcarolei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include <stdlib.h>

void	ft_list_remove_if(t_list *begin_list, void *data_ref,
	int (*cmp)(void *, void *))
{
	t_list	*i_list;
	t_list	*to_del;

	i_list = begin_list;
	while (i_list->next != 0)
	{
		if (cmp(i_list->next->data, data_ref) == 0
			&& (i_list->next->next != 0))
		{
			to_del = i_list->next;
			i_list->next = i_list->next->next;
			free(to_del);
		}
		else if (cmp(i_list->next->data, data_ref) == 0
			&& i_list->next->next == 0)
		{
			to_del = i_list->next;
			i_list->next = 0;
			free(to_del);
		}
		i_list = i_list->next;
	}
}
