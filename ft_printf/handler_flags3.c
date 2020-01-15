/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_flags3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcarolei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 06:57:11 by pcarolei          #+#    #+#             */
/*   Updated: 2020/01/14 07:06:50 by pcarolei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*handler_flag_plus(char *str, t_fwplt *fwplt)
{
	if (check_str_is_neg(str))
		return (str);
	return (create_plussign_str(str, fwplt));
}

char	*handler_flag_space(char *str, t_fwplt *fwplt)
{
	char	*newstr;
	size_t	str_len;
	size_t	str_size;
	size_t	i;
	int		flag;

	if (ft_strstr(str, "-") || ft_strstr(str, "+") || (str[0] == ' '))
		return (str);
	str_len = ft_strlen(str);
	str_size = str_len + 1 + (str[ft_strlen(str) - 1] != ' ');
	if (!(newstr = (char *)malloc(str_size)))
		return (NULL);
	newstr[0] = ' ';
	i = 1;
	while (i < str_size - 1)
	{
		newstr[i] = str[i - 1];
		i++;
	}
	newstr[i] = '\0';
	free(str);
	return (newstr);
}

char	select_zero_or_space(t_fwplt *fwplt, char c)
{
	if ((fwplt->type == '%') && (ft_strstr(fwplt->flags, "-")))
		return (' ');
	if ((fwplt->type == 'f') && (ft_strstr(fwplt->flags, "-")))
		return (' ');
	if (fwplt->type == 'f')
		return ('0');
	if (fwplt->precision == -1)
		return ('0');
	return (c);
}

void	cps_helper(int *flag, int *i, char *newstr)
{
	if (*i > 0)
	{
		newstr[*i - 1] = '+';
		*flag = 1;
	}
	else
	{
		newstr[*i] = '+';
		*i = *i + 1;
		*flag = 0;
	}
}

char	*create_plussign_str(char *str, t_fwplt *fwplt)
{
	char	*newstr;
	int		i;
	size_t	first_digit_pos;
	size_t	str_len;
	int		flag;

	str_len = ft_strlen(str) + check_str_has_no_spaces(str);
	newstr = ft_strnew(str_len + 1);
	first_digit_pos = get_first_digit_pos(str);
	i = -1;
	while ((++i) < first_digit_pos)
		newstr[i] = str[i];
	cps_helper(&flag, &i, newstr);
	while (i < str_len)
	{
		newstr[i] = str[i - 1 + flag];
		i++;
	}
	free(str);
	newstr[i] = '\0';
	if (ft_strstr(fwplt->flags, "-"))
		return (handler_flag_minus(newstr));
	return (newstr);
}
