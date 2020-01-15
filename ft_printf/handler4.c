/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler4.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcarolei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 06:36:54 by pcarolei          #+#    #+#             */
/*   Updated: 2020/01/14 07:26:32 by pcarolei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*repl_del_char(char *str)
{
	int	i;
	int	len;

	i = 0;
	len = ft_strlen(str);
	while (i < len)
	{
		if (str[i] == 127)
			str[i] = '\0';
		i++;
	}
	return (str);
}

size_t	handler_c(int fd, t_fwplt *fwplt, char arg)
{
	char	*res;
	int		len;
	size_t	part_of_len;

	res = (char *)malloc(2);
	if (arg == '\0')
		res[0] = 127;
	else
		res[0] = arg;
	res[1] = '\0';
	res = handler_width(fwplt, res);
	res = handler_flags(fwplt, res);
	len = ft_strlen(res);
	if (arg == '\0')
		res = repl_del_char(res);
	part_of_len = (write(fd, res, len));
	fwplt_free(fwplt);
	free(res);
	return (part_of_len);
}

size_t	handler_r(int fd, t_fwplt *fwplt, char arg)
{
	char	*res;
	size_t	part_of_len;

	if ((arg >= 33) && (arg != 127))
		return (handler_c(fd, fwplt, arg));
	res = controlchar_to_str(arg);
	res = handler_precision_s(fwplt, res);
	res = handler_width(fwplt, res);
	res = handler_flags(fwplt, res);
	part_of_len = write(fd, res, ft_strlen(res));
	fwplt_free(fwplt);
	free(res);
	return (part_of_len);
}

size_t	handler_s(int fd, t_fwplt *fwplt, char *arg)
{
	char	*res;
	size_t	part_of_len;

	if (!arg)
		res = ft_strdup("(null)");
	else
		res = ft_strdup(arg);
	res = handler_precision_s(fwplt, res);
	res = handler_width(fwplt, res);
	res = handler_flags(fwplt, res);
	part_of_len = write(fd, res, ft_strlen(res));
	fwplt_free(fwplt);
	free(res);
	return (part_of_len);
}

size_t	handler_k(int fd, t_fwplt *fwplt, char *arg)
{
	char	*res;
	size_t	part_of_len;

	res = parse_date(arg);
	return (handler_s(fd, fwplt, res));
}
