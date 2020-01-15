/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bignum2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcarolei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 05:28:44 by pcarolei          #+#    #+#             */
/*   Updated: 2020/01/14 05:41:12 by pcarolei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*mult_by_10_n_times(char *num, int n)
{
	char	*res;

	res = num;
	while (n > 0)
	{
		res = bignum_multiply_by_n(res, 10);
		n--;
	}
	return (res);
}

char	*power_of_2(int n)
{
	int		i;
	char	*res;

	if (n == 0)
		return (str_from_char('1'));
	res = str_from_char('2');
	i = 1;
	while (i < n)
	{
		res = bignum_multiply_by_n(res, 2);
		i++;
	}
	return (res);
}

char	*power_of_5(int n)
{
	int		i;
	char	*res;

	if (n == 0)
		return (str_from_char('1'));
	res = str_from_char('5');
	i = 1;
	while (i < n)
	{
		res = bignum_multiply_by_n(res, 5);
		i++;
	}
	return (res);
}

void	free_nums(char *num1, char *num2)
{
	free(num1);
	free(num2);
}

char	*bignum_sum(char *num1, char *num2)
{
	char	*res;
	int		sum;
	int		i;
	int		carry;

	swap_str(&num1, &num2, ft_strlen(num1) > ft_strlen(num2));
	num1 = str_rev(num1);
	num2 = str_rev(num2);
	i = 0;
	carry = 0;
	res = NULL;
	while (i < (int)ft_strlen(num2))
	{
		if (i < ft_strlen(num1))
			sum = ((num1[i] - '0') + (num2[i] - '0') + carry);
		else
			sum = (num2[i] - '0') + carry;
		res = push_back(res, (sum % 10) + '0');
		carry = sum / 10;
		i++;
	}
	if (carry)
		res = push_back(res, carry + '0');
	free_nums(num1, num2);
	return (str_rev(res));
}
