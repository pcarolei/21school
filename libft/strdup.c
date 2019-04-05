/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcarolei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 13:59:32 by pcarolei          #+#    #+#             */
/*   Updated: 2019/02/07 13:59:34 by pcarolei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strdup(char *src)
{
	int		i;
	int		src_size;
	char	*str_copy;

	i = 0;
	src_size = ft_strlen(src) + 1;
	str_copy = (char*)malloc(sizeof(char) * src_size);
	while (src[i] != '\0')
	{
		str_copy[i] = src[i];
		i++;
	}
	str_copy[i] = '\0';
	return (str_copy);
}
