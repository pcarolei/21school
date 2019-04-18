/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcarolei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/13 13:25:24 by pcarolei          #+#    #+#             */
/*   Updated: 2019/04/17 17:32:52 by pcarolei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*new_lst;

	if (!content)
	{
		new_lst->content = NULL;
		new_lst->content_size = 0;
		return (new_lst);
	}
	new_lst->content = malloc(content_size);
	if (!new_lst->content)
	{
		free(new_lst);
		return (NULL);
	}
	ft_memcpy(new_lst->content, content, content_size);
	new_lst->content_size = content_size;
	return (new_lst);
}