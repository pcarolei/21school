/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstaddl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcarolei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 04:43:59 by pcarolei          #+#    #+#             */
/*   Updated: 2019/04/17 19:23:01 by pcarolei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstaddl(t_list **alst, t_list *new)
{
	t_list	*ptr;

	if (!alst)
		return ;
	if (!*alst)
	{
		*alst = new;
		return ;
	}
	ptr = *alst;
	while (ptr->next)
		ptr = ptr->next;
	ptr->next = new;
}
