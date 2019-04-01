/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcarolei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 23:06:39 by pcarolei          #+#    #+#             */
/*   Updated: 2019/02/20 23:06:40 by pcarolei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int   *get_start(int max, int max_i, int max_j)
{
	int 	*start;

	start = (int *)malloc(sizeof(int) * 2);
	if (max_i == 0)
		start[0] = 0;
	else
		start[0] = max_i - max + 1;
	if (max_j == 0)
		start[1] = 0;
	else
		start[1] = max_j - max + 1;
	return (start);
}

void 	final(char **str, int *start, int *end, char **param)
{
	int i;
	int j;
	char symbol;

	symbol = param[3][0];
	i = start[0];
	j = start[1];
	while (i < end[1] + 1)
	{
		while (j < end[2] + 1)
		{
			str[i][j] = symbol;
			j++;
		}
		j = 0;
		i++;
	}
	i = 0;
	j = 0;
	while (i < ft_atoi(param[0]))
	{
		write(1, str[i], 1 + get_tab_cols_amount(str));
		i++;
	}
}

void	to_file()
{
	int fd;
	int b;
	char buf2[2];

	fd = open("file_for_standart_input", O_RDWR);
	while ((b = read(0, buf2, 1)))
	{
		buf2[b] = 0;
		write(fd, buf2, 1);
	}
	close(fd);
}

int 	first_line_symbol_counter(char *buf)
{
	int counter;

	counter = 0;
	while (buf[counter] != '\n')
		counter++;
	return (counter--);
}

int 	parse_cond_helper(int i, int j, int counter)
{
	if (i == 0)
		return (j < counter - 3);
	return (j < 1);
}
