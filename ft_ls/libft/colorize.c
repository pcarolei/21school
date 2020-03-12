/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colorize.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcarolei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 05:08:49 by pcarolei          #+#    #+#             */
/*   Updated: 2020/02/26 03:30:05 by pcarolei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*replace_blue(char *str)
{
	char	*pos;
	char	*newstr;

	if (!(pos = ft_strstr(str, "{blue}")))
		return (str);
	newstr = ft_strreplace(str, "{blue}", "\033[0;34m");
	free(str);
	return (replace_blue(newstr));
}

char	*replace_magenta(char *str)
{
	char	*pos;
	char	*newstr;

	if (!(pos = ft_strstr(str, "{magenta}")))
		return (str);
	newstr = ft_strreplace(str, "{magenta}", "\033[0;35m");
	free(str);
	return (replace_magenta(newstr));
}

char	*replace_cyan(char *str)
{
	char	*pos;
	char	*newstr;

	if (!(pos = ft_strstr(str, "{cyan}")))
		return (str);
	newstr = ft_strreplace(str, "{cyan}", "\033[0;36m");
	free(str);
	return (replace_cyan(newstr));
}

char	*colorize(char *str)
{
	char	*newstr;

	newstr = replace_eoc(ft_strdup(str));
	newstr = replace_red(newstr);
	newstr = replace_green(newstr);
	newstr = replace_yellow(newstr);
	newstr = replace_blue(newstr);
	newstr = replace_magenta(newstr);
	newstr = replace_cyan(newstr);
	return (newstr);
}
