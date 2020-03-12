/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_flags4.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcarolei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 07:07:05 by pcarolei          #+#    #+#             */
/*   Updated: 2020/02/21 15:56:17 by pcarolei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*handler_flag_zero(char *str, t_fwplt *fwplt)
{
	size_t	i;

	i = 0;
	if (((fwplt->precision > 0) && (fwplt->width > fwplt->precision))
								&& (fwplt->type != 'f'))
		return (str);
	if (check_str_is_neg(str))
		str[i++] = '-';
	else if (check_str_is_pos(str))
		str[i++] = '+';
	else if (ft_strstr(fwplt->flags, " "))
		str[i++] = ' ';
	while (str[i])
	{
		if ((str[i] == ' ') || (str[i] == '-') || (str[i] == '+'))
			str[i] = select_zero_or_space(fwplt, str[i]);
		i++;
	}
	return (str);
}

int		get_first_symbol_pos(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (ft_isalnum(str[i]))
			return (i);
		i++;
	}
	return (i);
}

int		check_for_zero_str(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		if ((str[i] != '0') && (str[i] != ' '))
			return (0);
		i++;
	}
	return (1);
}

char	*add_prefix(char *str, char type, t_fwplt *fwplt)
{
	int	first_symbol_pos;

	if (check_for_zero_str(str) == 1)
		return (ft_strdup(str));
	first_symbol_pos = get_first_symbol_pos(str);
	if (((ft_isalpha(str[0])) || (first_symbol_pos == 0))
				&& ((str[0] != '0') || (fwplt->precision > 0)))
		return (ft_strjoin(((type == 'x') ? "0x" : "0X"), str));
	if ((first_symbol_pos == 1) && (!((str[0] == '-') && (str[1] == '0'))))
	{
		str[0] = (type == 'x') ? 'x' : 'X';
		return (ft_strjoin("0", str));
	}
	if ((str[0] == '0') && (str[1] == '0'))
		first_symbol_pos = 2;
	str[first_symbol_pos - 2] = '0';
	str[first_symbol_pos - 1] = (type == 'x') ? 'x' : 'X';
	return (ft_strdup(str));
}

char	*cut_extra(char *str, t_fwplt *fwplt)
{
	char	*newstr;
	size_t	i;
	size_t	j;

	if ((fwplt->width < 0) || ((int)ft_strlen(str) == fwplt->width))
		return (str);
	i = 0;
	while ((str[i]) && (str[i] != ' '))
		i++;
	if (!(newstr = (char *)malloc(ft_max(fwplt->width + 1, (int)i + 1))))
		return (NULL);
	j = 0;
	while ((int)j < ft_max(fwplt->width, (int)i))
	{
		newstr[j] = str[j];
		j++;
	}
	newstr[ft_max(fwplt->width, (int)i)] = '\0';
	free(str);
	return (newstr);
}
