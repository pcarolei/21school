/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers4.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcarolei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 23:10:26 by pcarolei          #+#    #+#             */
/*   Updated: 2019/02/20 23:10:28 by pcarolei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int 	is_map_first_line_valid(char *file_name, char *nbr_str)
{
	// int 	i;
	int 	amount_of_symbols_fs;
	int 	amount_of_symbols_nbr;
	char 	buf[14];
	int 	fd;

	fd = open(file_name, O_RDONLY);
	read(fd, buf, 14);
	amount_of_symbols_fs = first_line_symbol_counter(buf);
	amount_of_symbols_nbr = count_number_symbols(nbr_str);
	if (amount_of_symbols_fs - amount_of_symbols_nbr == 3)
		return (1);
	write(2, "map error\n", 11);
	return (0);
}

char	**str_creation (int x, int y, char *file_name)
{
	char	**str;
	char	buf[1];
	int 	i;
	int 	j;
	int 	fd;

	i = 0;
	j = 0;
	str = 0;
	str = (char **)malloc(sizeof(char *) * (y));
	fd = open(file_name, O_RDONLY); 
	str[0] = (char *)malloc(sizeof(char) * (x + 1));
	while(read(fd, buf, 1))
	{
		if (*buf != '\n')
			{
				str[i][j] = *buf;		
				j++;
			}
		else
		{
			str[i][j] = '\0';
			i++;
			str[i] = (char *)malloc(sizeof(char) * (x + 1));
			j = 0;
		}
	}	
	shift_str_array(str, y);
	str[y] = 0;

	return (str);
}

void	str_transpiler(char **str, char smb1, char smb2, int rows)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < rows)
	{
		while (str[i][j] != '\0')
		{
			if (str[i][j] == smb1)
				str[i][j] = '1';
			else if (str[i][j] == smb2)
				str[i][j] = '0';
			j++;
		}
		j = 0;
		i++;
	}
}

int 	is_right_symbol(char test, char smb1, char smb2)
{
	if (test != smb1 && test != smb2)
		return (0);
	return (1);
}

int 	is_str_valid(char **str, int rows, char smb1, char smb2)
{
	int i;
	int j;
	int line_count;

	i = 0;
	j = 0;
	line_count = 0;
	while (i < rows)
	{
		while (str[i][j] != '\0')
		{
			if (is_right_symbol(str[i][j], smb1, smb2) == 0)
				return (0);
			j++;
		}
		if (i == 0)
			line_count = j;
		if ((i != 0 && j != line_count) || (str[i][j] != '\0'))
			return (0);
		j = 0;
		i++;
	}
	return (1);
}
