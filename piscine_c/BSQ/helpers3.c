/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcarolei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 23:09:01 by pcarolei          #+#    #+#             */
/*   Updated: 2019/02/20 23:09:06 by pcarolei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

void    bsq(char **tab, char **param, int cols)
{
	int     i;
	int     j;
	int     max_i_j[3];
	int    *new_tab[ft_atoi(param[0])];

	i = 0;
	j = 0;
	max_i_j[0] = 0;
	max_i_j[1] = 0;
	max_i_j[2] = 0;
	cols = get_tab_cols_amount(tab);
	while (i < ft_atoi(param[0]))
	{
		new_tab[i] = (int *)malloc(sizeof(int) * cols);
		i++;
	}

	i = 0;
	j = 0;

	if (ft_atoi(param[0]) == 1 && cols == 1)
	{
		if (tab[0][0] == '1')
			write(1, param[3], 1);
		else
			write(1, param[2], 1);
		write(1, "\n", 1);
		return;
	}

	while (i < ft_atoi(param[0]))
	{
		if (i == 0)
		{
			while (j < cols)
			{
				new_tab[0][j] = tab[0][j] - '0';
				j++;
			}
		}
		else
		{
			while (j < cols)
			{
				if (j == 0)
					new_tab[i][j] = tab[i][j] - '0';
				else
					new_tab[i][j] = 0;
				j++;
			}
		}
		j = 0;
		i++;
	}
	i = 1;
	j = 1;

	while (i < ft_atoi(param[0]))
	{
		while (j < cols)
		{
			if (tab[i][j] == '0')
				new_tab[i][j] = 0;
			else
			{
				new_tab[i][j] = min(new_tab[i - 1][j],
							  new_tab[i][j - 1],
							  new_tab[i - 1][j - 1]) + 1;
				if ((new_tab[i][j]) > max_i_j[0])
				{
					max_i_j[0] = new_tab[i][j];
					max_i_j[1] = i;
					max_i_j[2] = j;
				}
			}
			j++;
		}
		j = 1;
		i++;
	}
	final(
		tab,
		get_start(max_i_j[0], max_i_j[1], max_i_j[2]),
		max_i_j,
		param
		);
}

char 	**parse(int fd)
{
	char	**param;
	int		i;
	int		j;
	int 	counter;
	char	buf[14];

	j = 0;
	i = 3;
	read(fd, buf, 14);
	counter = first_line_symbol_counter(buf);
	param = (char **)malloc(sizeof(char *) * 4);
	while (i >= 0)
	{
		if (i == 0)
			param[i] = (char*)malloc(sizeof(char) * (counter - 3 + 1)); 
		else
			param[i] = (char *)malloc(sizeof(char) + 1);	
		while (parse_cond_helper(i, j, counter))
		{
			if (i == 0)
			{
				j = 0;
				while (j < counter - 3)
				{
					param[i][j] = buf[j];
					j++;
				}
			}
			else
				param[i][j] = buf[counter - (3 - i) - 1]; // иначе 
			j++;
		}
		param[i][j] = '\0';
		i--;
		j = 0;
	}
	return (param);
}

int count_x(int fd)
{
	char buf[1];
	int j;
	int k;

	j = 0;
	while(read(fd, buf, 1))
	{
		if(*buf != '\n')
		{
			j++;
			k = j;
		}
		else
			j = 0;
	}
	return (k);
} 

void	shift_str_array(char **str, int y)
{
	int 	i;
	char 	*swp;

	i = 0;
	swp = str[y];
	while (i + 1 < y)
	{
		str[i] = str[i + 1];
		i++;
	}
	str[i] = swp;
}

int 	count_number_symbols(char *nbr_str)
{
	int count;

	count = 0;
	while (nbr_str[count] >= '0' && nbr_str[count] <= '9')
		count++;
	return (count);
}
