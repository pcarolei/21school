/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcarolei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 01:31:22 by pcarolei          #+#    #+#             */
/*   Updated: 2019/04/12 01:36:35 by pcarolei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*ptr;

	ptr = ft_strnew(len);
	if (ptr == NULL)
		return (NULL);
	ft_memcpy((void *)ptr, (void *)(&s[start]), len);
	return (ptr);
}
