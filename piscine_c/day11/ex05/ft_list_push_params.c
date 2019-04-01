/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_params.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcarolei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 15:36:30 by pcarolei          #+#    #+#             */
/*   Updated: 2019/02/12 15:36:32 by pcarolei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_list	ft_list_push_params(int ac, char **av)
{
	int		i;
	t_list	*f_list;
	t_list	*list;

	i = 2;
	list = malloc(sizeof(t_list));
	f_list = list;
	list->data = av[i];
	if (ac == 1)
	{
		list->next = 0;
		return (*list);
	}
	while (i < ac)
	{
		list->next = ft_create_elem((void *)av[i + 1]);
		list = list->next;
		i++;
	}
	list = ft_create_elem((void *)av[1]);
	return (*f_list);
}
