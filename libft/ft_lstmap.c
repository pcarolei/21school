/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcarolei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 05:45:54 by pcarolei          #+#    #+#             */
/*   Updated: 2019/04/17 07:56:13 by pcarolei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*ptr;
	t_list	*newlst;

	if (!lst || !f)
		return (NULL);
	ptr = lst;
	newlst = NULL;
	while (ptr)
	{
		ft_lstaddl(&newlst, f(ptr));
		ptr = ptr->next;
	}
	return (newlst);
}
