/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_width.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcarolei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 07:21:41 by pcarolei          #+#    #+#             */
/*   Updated: 2020/01/14 07:22:12 by pcarolei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_add_spaces(char *str, int space_cnt, int width)
{
	char	*newstr;
	size_t	str_len;
	size_t	i;

	str_len = ft_strlen(str);
	if (!(newstr = (char *)malloc(1 + width)))
		return (NULL);
	i = 0;
	while (i < space_cnt)
	{
		newstr[i] = ' ';
		i++;
	}
	while (i < width)
	{
		newstr[i] = str[i - space_cnt];
		i++;
	}
	newstr[width] = '\0';
	free(str);
	return (newstr);
}

char	*handler_width(t_fwplt *fwplt, char *str)
{
	int	len;
	int	space_cnt;

	len = MAX(fwplt->precision, ft_strlen(str));
	if (ft_strlen(str) < len)
		len = ft_strlen(str);
	if (check_str_is_neg(str))
		len++;
	if (fwplt->width == -1)
		return (str);
	space_cnt = fwplt->width - len + check_str_is_neg(str);
	if (space_cnt < 0)
		return (str);
	return (ft_add_spaces(str, space_cnt, fwplt->width));
}
