/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcarolei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 02:22:31 by pcarolei          #+#    #+#             */
/*   Updated: 2019/04/12 02:42:54 by pcarolei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	char			*sub;
	unsigned int	start;

	if (ft_strlen(needle) == 0)
		return (ft_strdup(haystack));
	start = 0;
	while (start + (unsigned int)ft_strlen(needle) < (unsigned int)len)
	{
		sub = ft_strsub(haystack, start, ft_strlen(needle));
		if (ft_strequ(needle, sub) == 1)
		{
			ft_strdel(&sub);
			return (ft_strdup(&haystack[start]));
		}
		ft_strdel(&sub);
		start++;
	}
	return (NULL);
}