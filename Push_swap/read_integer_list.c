/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_integer_list.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcarolei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 10:28:58 by pcarolei          #+#    #+#             */
/*   Updated: 2020/02/21 15:18:01 by pcarolei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "checker.h"

static int	*tab_duplicate_check(int *tab, int size)
{
	int	i;
	int	j;

	j = 0;
	while (j < size)
	{
		i = j + 1;
		while (i < size)
		{
			if (tab[j] == tab[i])
			{
				free(tab);
				return (NULL);
			}
			i++;
		}
		j++;
	}
	return (tab);
}

static int	int_bounds_check(char *str)
{
	int		atoi;
	char	*itoa;
	int		res;

	atoi = ft_atoi(str);
	itoa = ft_itoa(atoi);
	if (ft_strcmp(str, itoa) != 0)
		res = 0;
	else
		res = 1;
	free(itoa);
	return (res);
}

static int	numstr_check(char *str)
{
	size_t	i;
	int		flag;

	i = 0;
	flag = 1;
	while (str[i])
	{
		if ((i == 0) && (str[i] == '0') && (ft_isdigit(str[i + 1])))
			return (0);
		flag = ft_isdigit(str[i]);
		i++;
	}
	return (flag);
}

int			*read_integer_list(int ac, char **av, int shift)
{
	int	i;
	int	*tab;

	i = 0;
	if ((ac <= 1) || (!(tab = (int *)malloc(sizeof(int) * (ac - 1 - shift)))))
		return (NULL);
	while (i < ac - 1 - shift)
	{
		if (!numstr_check(av[i + 1 + shift]) ||
									!int_bounds_check(av[i + 1 + shift]))
			error_handler(tab, NULL);
		tab[i] = ft_atoi(av[i + 1 + shift]);
		i++;
	}
	return (tab_duplicate_check(tab, ac - 1 - shift));
}
