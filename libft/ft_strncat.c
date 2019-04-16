/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcarolei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 04:07:10 by pcarolei          #+#    #+#             */
/*   Updated: 2019/04/16 10:06:03 by pcarolei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	size_t i;
	size_t k;

	if (!s1 || !s2)
		return (NULL);
	i = ft_strlen(s1);
	k = 0;
	while (s2[k] != '\0' && k < n)
	{
		s1[i] = s2[k];
		i++;
		k++;
	}
	s1[i] = '\0';
	return (s1);
}
