/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcarolei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 03:55:33 by pcarolei          #+#    #+#             */
/*   Updated: 2019/04/11 23:57:16 by pcarolei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*ptr_d;
	char	*src_copy;

	src_copy = (char *)malloc(sizeof(char) * len);
	memcpy(src_copy, src, len);
	ptr_d = (char *)dst;
	while ((len--) > 0)
		ptr_d[len] = src_copy[len];
	free(src_copy);
	return (dst);
}
