/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floats.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcarolei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 04:55:33 by pcarolei          #+#    #+#             */
/*   Updated: 2020/01/14 07:52:06 by pcarolei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*float_to_str(long double num, int sign)
{
	char		bits[80];

	num_to_bits(num, bits);
	return (bits_to_numstr(bits, sign));
}
