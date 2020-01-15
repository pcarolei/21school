/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcarolei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 06:16:36 by pcarolei          #+#    #+#             */
/*   Updated: 2020/01/14 07:52:33 by pcarolei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	handler_b(int fd, t_fwplt *fwplt, int arg)
{
	char	*res;
	char	*bin;
	size_t	part_of_len;

	if (arg < 0)
	{
		bin = ft_itoa_base((unsigned)arg, 2);
		res = ft_strjoin("-", bin);
		free(bin);
	}
	else
		res = ft_itoa_base(arg, 2);
	res = handler_width(fwplt, res);
	res = handler_flags(fwplt, res);
	part_of_len = write(fd, res, ft_strlen(res));
	fwplt_free(fwplt);
	free(res);
	return (part_of_len);
}

size_t	handler_f(int fd, t_fwplt *fwplt, long double arg)
{
	char	*float_str;
	int		precision;
	char	*res;
	size_t	part_of_len;

	if (fwplt->precision == -1)
		precision = 6;
	else
		precision = fwplt->precision;
	float_str = float_to_str(arg, (arg >= 0));
	res = float_round_wrapper(float_str, precision);
	free(float_str);
	res = handler_width(fwplt, res);
	res = handler_flags(fwplt, res);
	part_of_len = write(fd, res, ft_strlen(res));
	fwplt_free(fwplt);
	free(res);
	return (part_of_len);
}

size_t	handler_percent(int fd, t_fwplt *fwplt)
{
	char	*res;
	size_t	part_of_len;

	if (!(res = (char *)malloc(2)))
		return (0);
	res[0] = '%';
	res[1] = '\0';
	res = handler_width(fwplt, res);
	res = handler_flags(fwplt, res);
	part_of_len = write(fd, res, ft_strlen(res));
	fwplt_free(fwplt);
	free(res);
	return (part_of_len);
}

size_t	handler_helper(t_fwplt *fwplt, char *str, va_list *args, int fd)
{
	if ((fwplt->type == 'f') && (fwplt->length)
									&& (fwplt->length[0] == 'L'))
		return (handler_f(fd, fwplt, va_arg(*args, long double)));
	else if (fwplt->type == 'f')
		return (handler_f(fd, fwplt, va_arg(*args, double)));
	else if (fwplt->type == 'b')
		return (handler_b(fd, fwplt, va_arg(*args, int)));
	else if (fwplt->type == 'r')
		return (handler_r(fd, fwplt, (char)va_arg(*args, int)));
	else if (fwplt->type == 'k')
		return (handler_k(fd, fwplt, va_arg(*args, char *)));
	else
		fwplt_free(fwplt);
	return (0);
}

size_t	handler(char *str, va_list *args, int fd)
{
	t_fwplt	*fwplt;

	fwplt = fwplt_create(str);
	if (fwplt->type == '%')
		return (handler_percent(fd, fwplt));
	if (fwplt->type == 'c')
		return (handler_c(fd, fwplt, (char)va_arg(*args, int)));
	else if (fwplt->type == 's')
		return (handler_s(fd, fwplt, va_arg(*args, char *)));
	else if (fwplt->type == 'p')
		return (handler_p(fd, fwplt, va_arg(*args, void *)));
	else if ((fwplt->type == 'd') || (fwplt->type == 'i'))
		return (handler_di(fd, fwplt, args));
	else if (fwplt->type == 'u')
		return (handler_u(fd, fwplt, args));
	else if (fwplt->type == 'o')
		return (handler_o(fd, fwplt, args));
	else if (fwplt->type == 'x' || fwplt->type == 'X')
		return (handler_x(fd, fwplt, args, fwplt->type == 'x'));
	return (handler_helper(fwplt, str, args, fd));
}
