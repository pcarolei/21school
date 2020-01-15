/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_precision_num.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcarolei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 07:15:33 by pcarolei          #+#    #+#             */
/*   Updated: 2020/01/14 07:20:11 by pcarolei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*handler_precision_num_wrapper(t_fwplt *fwplt, char *str)
{
	if (fwplt->precision == 0)
	{
		free(str);
		return (ft_strdup(""));
	}
	if ((fwplt->precision == -1) || ((int)ft_strlen(str) >= fwplt->precision))
		return (str);
	return (handler_precision_num(fwplt, str));
}

char	*handler_precision_num(t_fwplt *fwplt, char *str)
{
	size_t	i;
	int		is_neg;
	int		diff;
	char	*newstr;

	i = 0;
	is_neg = (str[0] == '-');
	if (!(newstr = (char *)malloc(fwplt->precision + is_neg + 1)))
		return (NULL);
	if (is_neg)
		newstr[i++] = '-';
	diff = fwplt->precision - ft_strlen(str) + is_neg;
	while ((int)i < diff + is_neg)
	{
		newstr[i] = '0';
		i++;
	}
	while ((int)i < fwplt->precision + diff)
	{
		newstr[i] = str[i - diff];
		i++;
	}
	newstr[i] = '\0';
	free(str);
	return (newstr);
}
