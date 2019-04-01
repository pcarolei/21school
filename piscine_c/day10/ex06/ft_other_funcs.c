/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_other_func.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcarolei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 18:16:11 by pcarolei          #+#    #+#             */
/*   Updated: 2019/02/11 18:16:13 by pcarolei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
	return ;
}

int		ft_atoi(char *str)
{
	int		i;
	int		res;
	int		sign;

	sign = 1;
	i = 0;
	res = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n' || str[i] == '\v'
	|| str[i] == '\r' || str[i] == '\f')
		i++;
	if (str[i] == '-')
	{
		sign = (-1);
		i++;
	}
	if (str[i] == '+')
	{
		i++;
		if (sign == -1)
			return (0);
	}
	while (str[i] >= 48 && str[i] <= 57)
		res = res * 10 + (str[i++] - 48);
	return (sign * res);
}

void	ft_putnbr(int nb)
{
	int rm;
	int sign;
	int array_digits[10];
	int i;

	i = 0;
	sign = -2 + (nb > 0) + (nb > 0) + (nb > 0) + (nb < 0);
	rm = 0;
	if (nb == 0)
		ft_putchar('0');
	while (nb != 0)
	{
		array_digits[i] = sign * (nb % 10);
		rm = 10 * rm + sign * nb % 10;
		nb = nb / 10;
		i++;
	}
	if (sign == -1)
		ft_putchar('-');
	while (i > 0)
		ft_putchar(array_digits[--i] + '0');
}
