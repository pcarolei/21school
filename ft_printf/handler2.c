/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcarolei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 06:18:55 by pcarolei          #+#    #+#             */
/*   Updated: 2020/01/14 06:21:45 by pcarolei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	fwplt_free(t_fwplt *fwplt)
{
	if (fwplt->flags)
		free(fwplt->flags);
	if (fwplt->length)
		free(fwplt->length);
	free(fwplt);
}

int		check_flag_char(char c)
{
	if ((c == '-') || (c == '+') || (c == ' ') || (c == '0') || (c == '#'))
		return (1);
	return (0);
}

char	*extract_flag_str(char *str, int n)
{
	char	*flag_str;
	size_t	i;

	if (!(flag_str = (char *)malloc(n + 1)))
		return (NULL);
	i = 0;
	while ((int)i < n)
	{
		flag_str[i] = str[i];
		i++;
	}
	flag_str[i] = '\0';
	return (flag_str);
}

void	check_flags(char *str, char *cur_mod, t_fwplt *fwplt, int *pos)
{
	size_t	i;

	if (!check_flag_char(str[0]))
	{
		fwplt->flags = NULL;
		return ;
	}
	i = 0;
	while (check_flag_char(str[i]))
		i++;
	fwplt->flags = extract_flag_str(str, i);
	*pos += i;
	*cur_mod = 'F';
}

void	check_width(char *str, char *cur_mod, t_fwplt *fwplt, int *pos)
{
	char	width_str[4];

	if (ft_isdigit(str[*pos]))
	{
		width_str[0] = str[*pos];
		width_str[1] = (ft_isdigit(str[*pos + 1])) ? str[*pos + 1] : '\0';
		width_str[2] = (ft_isdigit(str[*pos + 2])) ? str[*pos + 2] : '\0';
		width_str[3] = '\0';
		fwplt->width = ft_atoi(width_str);
		*pos += ft_strlen(width_str);
		*cur_mod = 'W';
		return ;
	}
	fwplt->width = -1;
}
