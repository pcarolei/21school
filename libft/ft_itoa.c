/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcarolei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 02:38:30 by pcarolei          #+#    #+#             */
/*   Updated: 2019/04/10 22:16:40 by pcarolei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_number_len(int n)
{
	int	cnt;

	cnt = 0;
	if (n == 0)
		return (1);
	else if (n == -2147483648)
		return (-11);
	else if (n < 0)
	{
		cnt++;
		n = n * (-1);
	}
	while (n > 0)
	{
		n = n / 10;
		cnt++;
	}
	return (cnt);
}

char		*ft_itoa(int n)
{
	size_t	i;
	size_t	n_size;
	char	*n_string;
	int		flag;

	i = 0;
	flag = 0;
	n_size = get_number_len(n);
	if (n == -2147483648)
		return ("-2147483648");
	n_string = (char *)malloc(sizeof(char) * (n_size + 1));
	if (n < 0)
		n_string[flag++] = '-';
	n = ((n < 0) ? (-n) : n);
	while (i < n_size)
	{
		if (n_size - i - 1 == 0 && flag == 1)
			break ;
		n_string[n_size - 1 - i] = n % 10 + '0';
		n = n / 10;
		i++;
	}
	n_string[n_size + flag] = '\0';
	return (n_string);
}
