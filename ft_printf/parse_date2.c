/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_date2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcarolei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 07:23:42 by pcarolei          #+#    #+#             */
/*   Updated: 2020/01/14 07:24:08 by pcarolei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	parse_year(char *str, char *year)
{
	if (!ft_isdigit(str[0]) || !ft_isdigit(str[1]) || !ft_isdigit(str[2])
			|| !ft_isdigit(str[3]))
		return (0);
	year[0] = str[0];
	year[1] = str[1];
	year[2] = str[2];
	year[3] = str[3];
	year[4] = '\0';
	return (1);
}
