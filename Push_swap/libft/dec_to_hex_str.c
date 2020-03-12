/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dec_to_hex_str.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcarolei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 05:42:11 by pcarolei          #+#    #+#             */
/*   Updated: 2020/02/13 07:54:11 by pcarolei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		get_hex_len(unsigned long long int n)
{
	int	len;

	if (n == 0)
		return (1);
	len = 0;
	while (n > 0)
	{
		n = n / 16;
		len++;
	}
	return (len);
}

char	*dec_to_hex_str(unsigned long long int n, int mode)
{
	char	*hex_str;
	char	*res_str;
	int		len;
	int		temp;

	len = get_hex_len(n);
	hex_str = ft_strnew(len + 1);
	hex_str[len--] = '\0';
	if (n == 0)
		hex_str[0] = '0';
	while (n > 0)
	{
		temp = n % 16;
		hex_str[len] = temp + ((temp < 10) ? 48 : 55);
		len--;
		n = n / 16;
	}
	if (mode == 1)
	{
		res_str = ft_strjoin("0x", hex_str);
		free(hex_str);
		return (res_str);
	}
	return (hex_str);
}
