/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcarolei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 03:13:10 by pcarolei          #+#    #+#             */
/*   Updated: 2019/04/16 08:33:49 by pcarolei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char	*ptr_d;
	char	*ptr_s;

	if (dst == src)
		return (dst);
	if (dst == NULL || src == NULL)
		return (NULL);
	ptr_d = (char *)dst;
	ptr_s = (char *)src;
	while ((n--) >= 1)
		*ptr_d++ = *ptr_s++;
	return (dst);
}
