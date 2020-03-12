/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcarolei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 06:19:31 by pcarolei          #+#    #+#             */
/*   Updated: 2020/02/13 07:55:27 by pcarolei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	check_precision(char *str, char *cur_mod, t_fwplt *fwplt, int *pos)
{
	char	prec_str[4];

	if (str[*pos] == '.')
	{
		prec_str[0] = (ft_isdigit(str[*pos + 1])) ? str[*pos + 1] : '\0';
		prec_str[1] = (ft_isdigit(str[*pos + 2])) ? str[*pos + 2] : '\0';
		prec_str[2] = (ft_isdigit(str[*pos + 3])) ? str[*pos + 3] : '\0';
		prec_str[3] = '\0';
		fwplt->precision = ft_atoi(prec_str);
		if (prec_str[0] != '\0')
			*pos += 1 + ft_strlen(prec_str);
		else
			*pos += 1;
		*cur_mod = 'P';
		return ;
	}
	fwplt->precision = -1;
}

void	check_length(char *str, char *cur_mod, t_fwplt *fwplt, int *pos)
{
	fwplt->length = NULL;
	if ((size_t)(*pos + 1) >= ft_strlen(str))
		return ;
	if (str[*pos] == 'L')
	{
		fwplt->length = ft_strdup("L");
		*pos += 1;
		*cur_mod = 'L';
	}
	else if (str[*pos] == 'l' || (str[*pos] == 'h'))
	{
		if ((str[*pos] == 'l') && (str[*pos + 1] == 'l'))
			fwplt->length = ft_strdup("ll");
		else if ((str[*pos] == 'h') && (str[*pos + 1] == 'h'))
			fwplt->length = ft_strdup("hh");
		else if (str[*pos] == 'l')
			fwplt->length = ft_strdup("l");
		else
			fwplt->length = ft_strdup("h");
		*pos += ft_strlen(fwplt->length);
		*cur_mod = 'L';
	}
}

void	check_type(char c, char *cur_mod, t_fwplt *fwplt)
{
	char	*type_str;
	char	*type;
	char	c_str[2];

	c_str[0] = c;
	c_str[1] = '\0';
	type_str = "%cspdiouxXfbrk";
	if ((type = ft_strstr(type_str, c_str)) != NULL)
	{
		*cur_mod = 'T';
		fwplt->type = *type;
		return ;
	}
	fwplt->type = 'N';
}

t_fwplt	*fwplt_create(char *str)
{
	t_fwplt	*fwplt;
	int		pos;
	char	cur_mod;

	if (!(fwplt = (t_fwplt *)malloc(sizeof(t_fwplt))))
		return (NULL);
	pos = 1;
	cur_mod = 'A';
	if ((ft_strlen(str) < 2) || (ft_strlen(str) > 12))
		return (NULL);
	check_flags(&str[1], &cur_mod, fwplt, &pos);
	check_width(str, &cur_mod, fwplt, &pos);
	check_precision(str, &cur_mod, fwplt, &pos);
	check_length(str, &cur_mod, fwplt, &pos);
	check_type(str[pos], &cur_mod, fwplt);
	return (fwplt);
}

char	*ft_strtolower(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		if ((str[i] >= 'A') && (str[i] <= 'Z'))
			str[i] += 32;
		i++;
	}
	return (str);
}
