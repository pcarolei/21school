/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcarolei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 18:46:32 by pcarolei          #+#    #+#             */
/*   Updated: 2019/04/17 19:27:42 by pcarolei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstmap(t_list *lst, t_list *(f)(t_list *elem))
{
	t_list	*ptr;
	t_list	*newlst;
	t_list	*proxy;

	if (!lst || !f)
		return (NULL);
	ptr = lst;
	newlst = NULL;
	while (ptr)
	{
		proxy = ft_lstnew(ptr->content, ptr->content_size);
		if (!proxy)
			return (newlst);
		ft_lstaddl(&newlst, f(proxy));
		ptr = ptr->next;
	}
	return (newlst);
}
