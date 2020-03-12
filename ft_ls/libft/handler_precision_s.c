/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_precision_s.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcarolei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 07:20:39 by pcarolei          #+#    #+#             */
/*   Updated: 2020/02/13 07:56:49 by pcarolei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*handler_precision_s(t_fwplt *fwplt, char *str)
{
	size_t	i;
	size_t	len;
	char	*newstr;

	if (fwplt->precision == -1)
		return (str);
	len = fwplt->precision;
	len = (fwplt->width > 0) ? (len + fwplt->width) : len;
	i = 0;
	if (!(newstr = (char *)malloc(len + 1)))
		return (NULL);
	while ((int)i < fwplt->precision)
	{
		newstr[i] = str[i];
		i++;
	}
	newstr[i] = '\0';
	free(str);
	return (newstr);
}
