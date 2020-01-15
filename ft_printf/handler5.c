/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler5.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcarolei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 06:39:01 by pcarolei          #+#    #+#             */
/*   Updated: 2020/01/14 07:19:24 by pcarolei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	handler_p(int fd, t_fwplt *fwplt, void *arg)
{
	char	*res;
	size_t	part_of_len;

	res = dec_to_hex_str((uintptr_t)arg, 1);
	res = ft_strtolower(res);
	res = handler_width(fwplt, res);
	res = handler_flags(fwplt, res);
	part_of_len = (write(fd, res, ft_strlen(res)));
	fwplt_free(fwplt);
	free(res);
	return (part_of_len);
}

size_t	handler_di(int fd, t_fwplt *fwplt, va_list *args)
{
	char	*res;
	size_t	part_of_len;

	part_of_len = 0;
	if ((fwplt->length) && (fwplt->length[0] == 'l'))
		res = ft_itoa_base(va_arg(*args, long long int), 10);
	else
		res = ft_itoa_base(va_arg(*args, int), 10);
	res = handler_precision_num_wrapper(fwplt, res);
	res = handler_width(fwplt, res);
	res = handler_flags(fwplt, res);
	part_of_len = write(fd, res, ft_strlen(res));
	free(res);
	fwplt_free(fwplt);
	return (part_of_len);
}

size_t	handler_u(int fd, t_fwplt *fwplt, va_list *args)
{
	char	*res;
	size_t	part_of_len;

	part_of_len = 0;
	if ((fwplt->length) && (fwplt->length[0] == 'l'))
		res = ft_itoa_base(va_arg(*args, long long int), 10);
	else
		res = ft_itoa_base(va_arg(*args, unsigned int), 10);
	res = handler_precision_num_wrapper(fwplt, res);
	res = handler_width(fwplt, res);
	res = handler_flags(fwplt, res);
	part_of_len = write(fd, res, ft_strlen(res));
	fwplt_free(fwplt);
	free(res);
	return (part_of_len);
}

size_t	handler_o(int fd, t_fwplt *fwplt, va_list *args)
{
	char	*res;
	size_t	part_of_len;

	if ((fwplt->length) && (fwplt->length[0] == 'l'))
		res = ft_itoa_base(va_arg(*args, long long int), 8);
	else
		res = ft_itoa_base(va_arg(*args, unsigned int), 8);
	res = handler_precision_num_wrapper(fwplt, res);
	res = handler_width(fwplt, res);
	res = handler_flags(fwplt, res);
	part_of_len = write(fd, res, ft_strlen(res));
	fwplt_free(fwplt);
	free(res);
	return (part_of_len);
}

size_t	handler_x(int fd, t_fwplt *fwplt, va_list *args, int mode)
{
	char	*res;
	size_t	part_of_len;

	if ((fwplt->length) && (fwplt->length[0] == 'l'))
		res = dec_to_hex_str(va_arg(*args, unsigned long long int), 0);
	else
		res = dec_to_hex_str(va_arg(*args, unsigned int), 0);
	if (mode)
		res = ft_strtolower(res);
	res = handler_precision_num_wrapper(fwplt, res);
	res = handler_width(fwplt, res);
	res = handler_flags(fwplt, res);
	part_of_len = write(fd, res, ft_strlen(res));
	fwplt_free(fwplt);
	free(res);
	return (part_of_len);
}
