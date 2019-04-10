/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcarolei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 00:44:39 by pcarolei          #+#    #+#             */
/*   Updated: 2019/04/11 01:59:16 by pcarolei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t i;

	i = 0;
	if (n == 0)
		return (0);
	while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0' && (i < n))
		i++;
	if (s1[i] != '\0' && s2[i] == '\0')
		return (1);
	if (s1[i] == '\0' && s2[i] != '\0')
		return (-1);
	if (i == n)
		return (0);
	if ((int)s1[i] != (int)s2[i])
		return ((int)s1[i] - (int)s2[i]);
	return (0);
}
