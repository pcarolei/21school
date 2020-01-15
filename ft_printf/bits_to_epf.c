/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bits_to_epf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcarolei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 05:53:01 by pcarolei          #+#    #+#             */
/*   Updated: 2020/01/14 07:51:31 by pcarolei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_pow(int n, int pow)
{
	int	res;

	res = 1;
	while (pow > 0)
	{
		res *= n;
		pow--;
	}
	return (res);
}

void	get_exponent_from_bits(char *bits, char *exp)
{
	int	i;

	i = 1;
	while (i < 16)
	{
		exp[i - 1] = bits[i];
		i++;
	}
}

void	get_mantissa_from_bits(char *bits, char *mnt)
{
	int	i;

	i = 16;
	while (i < 80)
	{
		mnt[i - 16] = bits[i];
		i++;
	}
}

void	get_decimal_exponent(t_ld_epf *epf)
{
	int	i;
	int	exp_dec;

	i = 0;
	exp_dec = 0;
	while (i < 15)
	{
		exp_dec += (epf->exp[14 - i] - '0') * ft_pow(2, i);
		i++;
	}
	epf->exp_dec = (exp_dec - 16383);
}
