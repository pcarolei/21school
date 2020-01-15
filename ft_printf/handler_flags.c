/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_flags.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcarolei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 06:52:55 by pcarolei          #+#    #+#             */
/*   Updated: 2020/01/14 07:52:46 by pcarolei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*hash_o_helper(char *str, t_fwplt *fwplt)
{
	char	*newstr;
	size_t	i;

	if ((check_for_zero_str(str) == 1) && (fwplt->precision != 0))
		return (ft_strdup(str));
	i = (size_t)get_first_digit_pos(str);
	if (str[i] == '0')
		return (ft_strdup(str));
	if ((fwplt->width < 0) && (str[i] != '0'))
		return (ft_strjoin("0", str));
	if ((i == 0) && (str[0] == '0'))
		return (ft_strdup(str));
	if (i == 0)
		return (ft_strjoin("0", str));
	if (!ft_strstr(fwplt->flags, "-"))
		str[i - 1] = '0';
	else
		str[0] = '0';
	return (ft_strdup(str));
}

int		get_last_digit_pos(char *str)
{
	int	i;

	i = get_first_digit_pos(str);
	while (ft_isdigit(str[i]))
		i++;
	return (i);
}

char	*handler_flag_hash_f(t_fwplt *fwplt, char *str)
{
	char	*newstr;
	int		i;
	int		flag;

	i = ft_strlen(str);
	i = (i <= 2) ? (i + 1) : (i);
	if (!(newstr = (char *)malloc(i + 1)))
		return (NULL);
	newstr[--i] = '\0';
	newstr[i] = (ft_isdigit(str[i - 1]) ? '.' : ' ');
	i--;
	flag = (newstr[i + 1] == '.') ? 1 : 0;
	while (i >= 0)
	{
		if ((i > 0) && ft_isdigit(str[i - 1]) && (flag == 0))
		{
			newstr[i] = '.';
			flag = 1;
		}
		else
			newstr[i] = str[i];
		i--;
	}
	free(str);
	return (newstr);
}

char	*handler_flag_hash(char *str, char type, t_fwplt *fwplt)
{
	char	*newstr;

	if ((type == 'o') || (type == 'x') || (type == 'X'))
	{
		if (type == 'o')
			newstr = hash_o_helper(str, fwplt);
		else if (((type == 'x') || (type == 'X')) &&
			((ft_isalnum(str[0]) || ft_isalnum(str[1])) || (ft_atoi(str) != 0)))
			newstr = add_prefix(str, type, fwplt);
		else if (ft_atoi(&(str[get_first_digit_pos(str)])) != 0)
			newstr = add_prefix(str, type, fwplt);
		else
			newstr = ft_strdup(str);
		free(str);
		return (cut_extra(newstr, fwplt));
	}
	if ((type == 'f') && (ft_strstr(str, ".") == NULL))
		return (handler_flag_hash_f(fwplt, str));
	return (str);
}

char	*handler_flags(t_fwplt *fwplt, char *str)
{
	char	*res;

	res = str;
	if (!fwplt->flags)
		return (res);
	if (ft_strstr(fwplt->flags, "-"))
		res = (handler_flag_minus(res));
	if (ft_strstr(fwplt->flags, "+"))
		res = (handler_flag_plus(res, fwplt));
	if (ft_strstr(fwplt->flags, " "))
		res = (handler_flag_space(res, fwplt));
	if (ft_strstr(fwplt->flags, "0") && (fwplt->width != -1))
		res = (handler_flag_zero(res, fwplt));
	if (ft_strstr(fwplt->flags, "#"))
		res = (handler_flag_hash(res, fwplt->type, fwplt));
	return (res);
}
