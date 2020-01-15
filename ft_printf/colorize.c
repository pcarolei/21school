/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colorize.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcarolei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 05:08:49 by pcarolei          #+#    #+#             */
/*   Updated: 2020/01/14 07:51:51 by pcarolei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*replace_blue(char *str)
{
	char	*pos;
	char	*newstr;
	char	*first_part;
	char	*second_part;
	char	*tmp;

	if (!(pos = ft_strstr(str, "{blue}")))
		return (str);
	first_part = ft_strsub(str, 0, (size_t)(pos - str));
	second_part = ft_strsub(str, pos - str + 6,
									ft_strlen(str) - (pos - str + 6));
	tmp = ft_strjoin(first_part, "\033[0;34m");
	free(first_part);
	newstr = ft_strjoin(tmp, second_part);
	free(tmp);
	free(second_part);
	return (replace_blue(newstr));
}

char	*replace_magenta(char *str)
{
	char	*pos;
	char	*newstr;
	char	*first_part;
	char	*second_part;
	char	*tmp;

	if (!(pos = ft_strstr(str, "{magenta}")))
		return (str);
	first_part = ft_strsub(str, 0, (size_t)(pos - str));
	second_part = ft_strsub(str, pos - str + 9,
									ft_strlen(str) - (pos - str + 9));
	tmp = ft_strjoin(first_part, "\033[0;35m");
	free(first_part);
	newstr = ft_strjoin(tmp, second_part);
	free(tmp);
	free(second_part);
	return (replace_magenta(newstr));
}

char	*replace_cyan(char *str)
{
	char	*pos;
	char	*newstr;
	char	*first_part;
	char	*second_part;
	char	*tmp;

	if (!(pos = ft_strstr(str, "{cyan}")))
		return (str);
	first_part = ft_strsub(str, 0, (size_t)(pos - str));
	second_part = ft_strsub(str, pos - str + 6,
									ft_strlen(str) - (pos - str + 6));
	tmp = ft_strjoin(first_part, "\033[0;36m");
	free(first_part);
	newstr = ft_strjoin(tmp, second_part);
	free(tmp);
	free(second_part);
	return (replace_cyan(newstr));
}

char	*colorize(char *str)
{
	char	*newstr;

	newstr = replace_eoc(str);
	newstr = replace_red(newstr);
	newstr = replace_green(newstr);
	newstr = replace_yellow(newstr);
	newstr = replace_blue(newstr);
	newstr = replace_magenta(newstr);
	newstr = replace_cyan(newstr);
	return (newstr);
}
