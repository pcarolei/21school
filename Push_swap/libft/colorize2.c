/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colorize2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcarolei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 05:11:16 by pcarolei          #+#    #+#             */
/*   Updated: 2020/02/26 03:30:06 by pcarolei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*replace_eoc(char *str)
{
	char	*pos;
	char	*newstr;

	if (!(pos = ft_strstr(str, "{eoc}")))
		return (str);
	newstr = ft_strreplace(str, "{eoc}", "\033[0m");
	free(str);
	return (replace_eoc(newstr));
}

char	*replace_red(char *str)
{
	char	*pos;
	char	*newstr;

	if ((pos = ft_strstr(str, "{red}")) == NULL)
		return (str);
	newstr = ft_strreplace(str, "{red}", "\033[0;31m");
	free(str);
	return (replace_red(newstr));
}

char	*replace_green(char *str)
{
	char	*pos;
	char	*newstr;

	if (!(pos = ft_strstr(str, "{green}")))
		return (str);
	newstr = ft_strreplace(str, "{green}", "\033[0;32m");
	free(str);
	return (replace_green(newstr));
}

char	*replace_yellow(char *str)
{
	char	*pos;
	char	*newstr;

	if (!(pos = ft_strstr(str, "{yellow}")))
		return (str);
	newstr = ft_strreplace(str, "{yellow}", "\033[0;33m");
	free(str);
	return (replace_yellow(newstr));
}
