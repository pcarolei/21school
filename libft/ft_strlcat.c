/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcarolei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 03:00:22 by pcarolei          #+#    #+#             */
/*   Updated: 2019/04/12 03:28:46 by pcarolei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dst_len;
	size_t	src_len;
	size_t	r_size;

	src_len = ft_strlen(src);
	r_size = size;
	while (*dst && r_size > 0)
	{
		dst++;
		r_size--;
	}
	dst_len = size - r_size;
	if (dst_len < r_size)
	{
		ft_strncpy(dst, src, MIN(src_len, r_size - 1));
		dst[MIN(src_len, r_size - 1)] = '\0';
	}
	return (dst_len + src_len);
}
