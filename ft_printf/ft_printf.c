/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcarolei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 06:15:30 by pcarolei          #+#    #+#             */
/*   Updated: 2020/01/14 08:06:25 by pcarolei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	free_parts(t_list *parts)
{
	t_list	*cur;

	while (parts)
	{
		cur = parts;
		if ((cur) && (cur->content))
			free(cur->content);
		free(cur);
		parts = parts->next;
	}
}

size_t	list_to_str(t_list *parts, va_list *args, int fd)
{
	char	*res;
	t_list	*ptr;
	char	*s;
	char	*handled_part;
	int		len;

	ptr = parts->next;
	len = 0;
	while (ptr)
	{
		s = (char *)ptr->content;
		if ((s[0] == '%') && check_closing_token(s[parts->content_size]))
			len += handler(s, args, fd);
		else
			len += write(fd, s, ft_strlen(s));
		ptr = ptr->next;
	}
	free_parts(parts);
	return (len);
}

int		ft_printf(char *fmt_str, ...)
{
	va_list	args;
	t_list	*parts;
	int		len;
	int		fd;

	fd = 1;
	parts = (parser(colorize(fmt_str)));
	va_start(args, fmt_str);
	len = list_to_str(parts, &args, fd);
	va_end(args);
	return (len);
}

int		ft_printf_fd(int fd, char *fmt_str, ...)
{
	va_list	args;
	t_list	*parts;
	int		len;

	parts = (parser(colorize(fmt_str)));
	va_start(args, fmt_str);
	len = list_to_str(parts, &args, fd);
	va_end(args);
	return (len);
}
