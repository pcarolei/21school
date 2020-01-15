/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bignum.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcarolei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 05:28:16 by pcarolei          #+#    #+#             */
/*   Updated: 2020/01/14 07:51:20 by pcarolei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*str_from_char(char c)
{
	char	*str;

	if (!(str = (char *)malloc(2)))
		return (NULL);
	str[0] = c;
	str[1] = '\0';
	return (str);
}

char	*push_back(char *res, char c)
{
	char	*new_res;
	size_t	len;
	int		i;

	len = (res == NULL) ? 0 : ft_strlen(res);
	if (!(new_res = (char *)malloc(len + 2)))
		return (NULL);
	i = 0;
	while (i < len)
	{
		new_res[i] = res[i];
		i++;
	}
	new_res[i] = c;
	new_res[i + 1] = '\0';
	if (res)
		free(res);
	return (new_res);
}

char	*str_rev(char *str)
{
	char	*str_rev;
	size_t	str_len;
	size_t	i;

	str_len = ft_strlen(str);
	if (str_len == 1)
		return (str);
	if (!(str_rev = (char *)malloc(str_len + 1)))
		return (NULL);
	i = 0;
	while (i < str_len)
	{
		str_rev[i] = str[str_len - 1 - i];
		i++;
	}
	str_rev[i] = '\0';
	free(str);
	return (str_rev);
}

void	swap_str(char **str1, char **str2, int mode)
{
	char	*swp;

	if (mode == 0)
		return ;
	swp = *str1;
	*str1 = *str2;
	*str2 = swp;
}

char	*bignum_multiply_by_n(char *num, int n)
{
	int		i;
	int		carry;
	int		prod;
	int		len;
	char	*res;

	i = 0;
	carry = 0;
	len = (int)ft_strlen(num);
	num = str_rev(num);
	res = NULL;
	while (i < len)
	{
		prod = (num[i] - '0') * n + carry;
		res = push_back(res, (prod % 10) + '0');
		carry = prod / 10;
		i++;
	}
	while (carry)
	{
		res = push_back(res, (carry % 10) + '0');
		carry /= 10;
	}
	free(num);
	return (str_rev(res));
}
