/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_foreach_if.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcarolei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 19:23:45 by pcarolei          #+#    #+#             */
/*   Updated: 2019/02/13 19:23:47 by pcarolei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_foreach_if(t_list *begin_list, void (*f)(void *),
	void *data_ref, int (*cmp)(void *, void *))
{
	t_list	*i_list;

	i_list = begin_list;
	while (i_list != 0)
	{
		if (cmp(i_list->data, data_ref) == 0)
			(*f)(i_list->data);
		i_list = i_list->next;
	}
}
