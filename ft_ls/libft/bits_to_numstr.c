/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bits_to_numstr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcarolei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 05:59:22 by pcarolei          #+#    #+#             */
/*   Updated: 2020/02/21 15:56:55 by pcarolei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		count_without_postfix_zeroes(char *str)
{
	int		len;
	int		zeroes_cnt;
	int		i;

	len = ft_strlen(str);
	i = len - 1;
	zeroes_cnt = 0;
	while (str[i] == '0')
	{
		zeroes_cnt++;
		i--;
	}
	return (len - zeroes_cnt);
}

char	*prepend_zeroes(char *str, int last)
{
	char	*finstr;
	int		true_len;
	int		diff;
	int		i;

	true_len = count_without_postfix_zeroes(str);
	diff = last - true_len;
	if (!(finstr = (char *)malloc(last + 1)))
		return (NULL);
	i = 0;
	while (i < diff)
	{
		finstr[i] = '0';
		i++;
	}
	while (i < last)
	{
		finstr[i] = str[i - diff];
		i++;
	}
	finstr[last] = '\0';
	free(str);
	return (finstr);
}

char	*epf_to_fract_part(t_ld_epf *epf)
{
	int		i;
	int		len;
	int		last;
	char	*fract_part;
	char	*add;

	i = 0;
	len = (int)ft_strlen(epf->fract_part_bin);
	if (epf->exp_dec < -1000)
		return (ft_strdup("0"));
	fract_part = str_from_char('0');
	while (epf->fract_part_bin[i])
	{
		if (epf->fract_part_bin[i] == '1')
		{
			add = power_of_5(ft_abs((epf->exp_dec)) + i);
			add = mult_by_10_n_times(add, len - 1 - i);
			fract_part = bignum_sum(add, fract_part);
			last = ft_abs((epf->exp_dec)) + i;
		}
		i++;
	}
	return (prepend_zeroes(fract_part, last));
}

char	*epf_to_integer_part(t_ld_epf *epf)
{
	int		i;
	char	*integer_part;

	i = 0;
	integer_part = str_from_char('0');
	while (epf->integer_part_bin[i])
	{
		if (epf->integer_part_bin[i] == '1')
			integer_part = bignum_sum(power_of_2(epf->exp_dec), integer_part);
		epf->exp_dec--;
		i++;
	}
	return (integer_part);
}

char	*prepend_minus(char *numstr)
{
	char	*minus_str;
	char	*res_str;

	minus_str = ft_strnew(2);
	minus_str[0] = '-';
	res_str = ft_strjoin(minus_str, numstr);
	free(minus_str);
	free(numstr);
	return (res_str);
}
