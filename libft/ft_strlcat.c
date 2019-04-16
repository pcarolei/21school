/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcarolei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 03:00:22 by pcarolei          #+#    #+#             */
/*   Updated: 2019/04/16 10:57:13 by pcarolei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dst_len;
	size_t	src_len;
	size_t	remaining_size;

	if (size == 0)
		return (0);
	src_len = ft_strlen(src);
	remaining_size = size;
	while (*dst && remaining_size > 0)
	{
		dst++;
		remaining_size--;
	}
	dst_len = size - remaining_size;
	if (size - dst_len > 0)
	{
		ft_strncpy(dst, src, size - dst_len - 1);
		dst[size - dst_len - 1] = '\0';
	}
	return (dst_len + src_len);
}
