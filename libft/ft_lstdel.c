/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcarolei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/13 14:28:40 by pcarolei          #+#    #+#             */
/*   Updated: 2019/04/15 02:37:58 by pcarolei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*ptr;
	t_list	*next;

	if (alst == NULL || *alst == NULL)
		return ;
	ptr = *alst;
	next = ptr->next;
	while (ptr != NULL)
	{
		ft_lstdelone(&ptr, del);
		if (next == NULL)
			break ;
		ptr = next;
		if (ptr->next == NULL)
		{
			ft_lstdelone(&ptr, del);
			break ;
		}
		next = ptr->next;
	}
	alst = NULL;
}
