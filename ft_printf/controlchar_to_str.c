/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controlchar_to_str.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcarolei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 05:26:42 by pcarolei          #+#    #+#             */
/*   Updated: 2020/01/14 05:27:45 by pcarolei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*block_one(char c)
{
	if (c == 0)
		return (ft_strdup("nul"));
	if (c == 1)
		return (ft_strdup("soh"));
	if (c == 2)
		return (ft_strdup("stx"));
	if (c == 3)
		return (ft_strdup("etx"));
	if (c == 4)
		return (ft_strdup("eot"));
	if (c == 5)
		return (ft_strdup("eng"));
	if (c == 6)
		return (ft_strdup("ack"));
	if (c == 7)
		return (ft_strdup("bel"));
	if (c == 8)
		return (ft_strdup("bs"));
	if (c == 9)
		return (ft_strdup("ht"));
	if (c == 10)
		return (ft_strdup("nl"));
	if (c == 11)
		return (ft_strdup("vt"));
	return (block_two(c));
}

char	*block_two(char c)
{
	if (c == 12)
		return (ft_strdup("np"));
	if (c == 13)
		return (ft_strdup("cr"));
	if (c == 14)
		return (ft_strdup("so"));
	if (c == 15)
		return (ft_strdup("si"));
	if (c == 16)
		return (ft_strdup("dle"));
	if (c == 17)
		return (ft_strdup("dc1"));
	if (c == 18)
		return (ft_strdup("dc2"));
	if (c == 19)
		return (ft_strdup("dc3"));
	if (c == 20)
		return (ft_strdup("dc4"));
	if (c == 21)
		return (ft_strdup("nak"));
	if (c == 22)
		return (ft_strdup("syn"));
	if (c == 23)
		return (ft_strdup("etb"));
	return (block_three(c));
}

char	*block_three(char c)
{
	if (c == 24)
		return (ft_strdup("can"));
	if (c == 25)
		return (ft_strdup("em"));
	if (c == 26)
		return (ft_strdup("sub"));
	if (c == 27)
		return (ft_strdup("esc"));
	if (c == 28)
		return (ft_strdup("fs"));
	if (c == 29)
		return (ft_strdup("gs"));
	if (c == 30)
		return (ft_strdup("rs"));
	if (c == 31)
		return (ft_strdup("us"));
	if (c == 32)
		return (ft_strdup("sp"));
	return (NULL);
}

char	*controlchar_to_str(char c)
{
	if (c == 127)
		return (ft_strdup("del"));
	return (block_one(c));
}
