/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_flags2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcarolei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 06:54:52 by pcarolei          #+#    #+#             */
/*   Updated: 2020/02/13 07:56:03 by pcarolei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*handler_flag_minus(char *str)
{
	size_t	i;
	size_t	j;
	size_t	diff;
	char	swp;

	i = 0;
	while (str[i] == ' ')
		i++;
	if (i == ft_strlen(str))
		return (str);
	diff = ft_strlen(str) - i;
	j = 0;
	while (j < diff)
	{
		swp = str[j];
		str[j] = str[i + j];
		str[i + j] = swp;
		j++;
	}
	return (str);
}

int		check_str_is_neg(char *str)
{
	size_t	i;

	i = 0;
	while (((str[i] < '0') || (str[i] > '9')) && (str[i] != '\0'))
		i++;
	if (i > 0 && str[i - 1] == '-')
		return (1);
	return (0);
}

int		check_str_is_pos(char *str)
{
	size_t	i;

	i = 0;
	while (((str[i] < '0') || (str[i] > '9')) && (str[i]))
		i++;
	if (str[i - 1] == '+')
		return (1);
	return (0);
}

int		check_str_has_no_spaces(char *str)
{
	if (ft_strstr(str, " "))
		return (0);
	return (1);
}

int		get_first_digit_pos(char *str)
{
	size_t	i;

	i = 0;
	while (((str[i] < '0') || (str[i] > '9')) && (str[i]))
		i++;
	return (i);
}
