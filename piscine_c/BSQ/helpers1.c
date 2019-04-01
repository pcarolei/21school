/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcarolei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 23:03:37 by pcarolei          #+#    #+#             */
/*   Updated: 2019/02/20 23:03:39 by pcarolei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

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
	if (str[i] < '0' || str[i] > '9')
		return(0);
	while (str[i] >= 48 && str[i] <= 57)
		res = res * 10 + (str[i++] - 48);
	return (sign * res);
}

int     get_tab_cols_amount(char **tab)
{
    int i;

    i = 0;
    while (tab[0][i] != '\0')
        i++;
    return (i);
}

void    display_char_tab(char **tab, int rows)
{
    int i;
    int j;

    i = 0;
    j = 0;
    while (i < rows)
    {
        while (tab[i][j] != '\0')
        {
            write(1, tab[i], 1 + get_tab_cols_amount(tab));
            j++;
        }
        j = 0;
        i++;
    }
}

int     min(int a, int b, int c)
{
    int min;

    min = a;
    if (a > b)
        min = b;
    if (c < min)
        min = c;
    return (min);
}