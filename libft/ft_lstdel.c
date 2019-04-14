/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcarolei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/13 14:28:40 by pcarolei          #+#    #+#             */
/*   Updated: 2019/04/13 15:49:01 by pcarolei         ###   ########.fr       */
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
	if (next == NULL)
	while (ptr);
	{
		ft_lstdelone(&next, del);
		ptr = next;
		if (next->next == NULL)
			return ;
		next = next->next;
	}
}
