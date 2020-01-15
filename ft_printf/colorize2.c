/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colorize2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcarolei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 05:11:16 by pcarolei          #+#    #+#             */
/*   Updated: 2020/01/14 05:26:03 by pcarolei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*replace_eoc(char *str)
{
	char	*pos;
	char	*newstr;
	char	*first_part;
	char	*second_part;
	char	*tmp;

	if (!(pos = ft_strstr(str, "{eoc}")))
		return (str);
	first_part = ft_strsub(str, 0, (size_t)(pos - str));
	second_part = ft_strsub(str, pos - str + 5,
									ft_strlen(str) - (pos - str + 5));
	tmp = ft_strjoin(first_part, "\033[0m");
	free(first_part);
	newstr = ft_strjoin(tmp, second_part);
	free(tmp);
	free(second_part);
	return (replace_eoc(newstr));
}

char	*replace_red(char *str)
{
	char	*pos;
	char	*newstr;
	char	*first_part;
	char	*second_part;
	char	*tmp;

	if (!(pos = ft_strstr(str, "{red}")))
		return (str);
	first_part = ft_strsub(str, 0, (size_t)(pos - str));
	second_part = ft_strsub(str, pos - str + 5,
									ft_strlen(str) - (pos - str + 5));
	tmp = ft_strjoin(first_part, "\033[0;31m");
	free(first_part);
	newstr = ft_strjoin(tmp, second_part);
	free(tmp);
	free(second_part);
	return (replace_red(newstr));
}

char	*replace_green(char *str)
{
	char	*pos;
	char	*newstr;
	char	*first_part;
	char	*second_part;
	char	*tmp;

	if (!(pos = ft_strstr(str, "{green}")))
		return (str);
	first_part = ft_strsub(str, 0, (size_t)(pos - str));
	second_part = ft_strsub(str, pos - str + 7,
									ft_strlen(str) - (pos - str + 7));
	tmp = ft_strjoin(first_part, "\033[0;32m");
	free(first_part);
	newstr = ft_strjoin(tmp, second_part);
	free(tmp);
	free(second_part);
	return (replace_green(newstr));
}

char	*replace_yellow(char *str)
{
	char	*pos;
	char	*newstr;
	char	*first_part;
	char	*second_part;
	char	*tmp;

	if (!(pos = ft_strstr(str, "{yellow}")))
		return (str);
	first_part = ft_strsub(str, 0, (size_t)(pos - str));
	second_part = ft_strsub(str, pos - str + 8,
									ft_strlen(str) - (pos - str + 8));
	tmp = ft_strjoin(first_part, "\033[0;33m");
	free(first_part);
	newstr = ft_strjoin(tmp, second_part);
	free(tmp);
	free(second_part);
	return (replace_yellow(newstr));
}
