/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floats.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcarolei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 04:55:33 by pcarolei          #+#    #+#             */
/*   Updated: 2020/02/13 07:54:26 by pcarolei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*float_to_str(long double num, int sign)
{
	char		bits[80];

	num_to_bits(num, bits);
	return (bits_to_numstr(bits, sign));
}
