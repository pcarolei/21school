/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_date.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcarolei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 07:23:05 by pcarolei          #+#    #+#             */
/*   Updated: 2020/01/14 07:53:03 by pcarolei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		parse_month(char *str, char *month)
{
	if (!ft_isdigit(str[5]) || !ft_isdigit(str[6]))
		return (0);
	if ((str[5] == '0') && (str[6] == '0'))
		return (0);
	if (!(((str[5] == '0') && (str[6] > '0') && (str[6] <= '9'))
		|| ((str[5] == '1') && ((str[6] == '0') || (str[6] == '1') ||
			(str[6] == '2')))))
		return (0);
	month[0] = str[5];
	month[1] = str[6];
	return (1);
}

int		parse_day(char *str, char *day)
{
	if (!ft_isdigit(str[8]) || !ft_isdigit(str[9]))
		return (0);
	if ((str[8] == '3') && (str[9] > '1'))
		return (0);
	if (str[8] >= '4')
		return (0);
	day[0] = str[8];
	day[1] = str[9];
	day[2] = ' ';
	day[3] = '\0';
	return (1);
}

int		check_delimiter(char *str)
{
	if ((str[4] != '-') && (str[6] != '-'))
		return (0);
	return (1);
}

char	*get_month_str(char *month)
{
	if ((month[0] == '0') && (month[1] == '1'))
		return (ft_strdup("January "));
	if ((month[0] == '0') && (month[1] == '2'))
		return (ft_strdup("February "));
	if ((month[0] == '0') && (month[1] == '3'))
		return (ft_strdup("March "));
	if ((month[0] == '0') && (month[1] == '4'))
		return (ft_strdup("April "));
	if ((month[0] == '0') && (month[1] == '5'))
		return (ft_strdup("May "));
	if ((month[0] == '0') && (month[1] == '6'))
		return (ft_strdup("June "));
	if ((month[0] == '0') && (month[1] == '7'))
		return (ft_strdup("July "));
	if ((month[0] == '0') && (month[1] == '8'))
		return (ft_strdup("August "));
	if ((month[0] == '0') && (month[1] == '9'))
		return (ft_strdup("September "));
	if ((month[0] == '1') && (month[1] == '0'))
		return (ft_strdup("October "));
	if ((month[0] == '1') && (month[1] == '1'))
		return (ft_strdup("November "));
	return (ft_strdup("December "));
}

char	*parse_date(char *str)
{
	char	year[5];
	char	month[2];
	char	day[4];
	char	*res;
	char	*tmp;

	if (!check_delimiter(str) || !parse_year(str, year)
			|| !parse_month(str, month) || !parse_day(str, day))
		return (ft_strdup("error"));
	res = get_month_str(month);
	tmp = ft_strjoin(day, res);
	free(res);
	res = ft_strjoin(tmp, year);
	free(tmp);
	return (res);
}
