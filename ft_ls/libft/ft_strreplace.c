/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strreplace.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcarolei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 05:11:16 by pcarolei          #+#    #+#             */
/*   Updated: 2020/02/26 03:30:07 by pcarolei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strreplace(char *str, char *from, char *to)
{
	char	*res;
	char	*ptr;
	size_t	len1;
	size_t	len2;

	res = NULL;
	if ((ptr = ft_strstr(str, from)))
	{
		len1 = ptr - str;
		len2 = ft_strlen(ptr + ft_strlen(from));
		res = ft_memalloc(sizeof(char) * (len1 + ft_strlen(to) + len2 + 1));
		if (res)
		{
			res = ft_strncpy(res, str, len1);
			res = ft_strcat(res, to);
			res = ft_strcat(res, ptr + ft_strlen(from));
		}
	}
	return (res);
}
