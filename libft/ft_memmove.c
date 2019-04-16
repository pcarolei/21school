/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcarolei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 03:55:33 by pcarolei          #+#    #+#             */
/*   Updated: 2019/04/16 08:52:53 by pcarolei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*ptr_d;
	char	*ptr_s;
	size_t	i;

	if (dst == src)
		return (dst);
	if (dst == NULL || src == NULL)
		return (NULL);
	i = 0;
	ptr_d = (char *)dst;
	ptr_s = (char *)src;
	if ((long int)dst < (long int)src)
		ft_memcpy(dst, src, len);
	else
	{
		while (len > 0)
		{
			ptr_d[len - 1] = ptr_s[len - 1];
			len--;
		}
	}
	return (dst);
}
