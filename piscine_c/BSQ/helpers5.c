/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers5.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcarolei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 23:11:06 by pcarolei          #+#    #+#             */
/*   Updated: 2019/02/20 23:11:07 by pcarolei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

void	from_st_input(void)
{
	int		fd;
	char	**param;
	char	**str;

	to_file();
	fd = open("file_for_standart_input", O_RDWR);
	param = parse(fd);
	str = str_creation(count_x(fd), ft_atoi(param[0]), "file_for_standart_input");
}

void 	from_files (int argc, char **argv)
{
	int		fd;
	char	**str;
	char	**param;
	int 	i;

	i = 1;
	while (i < argc)
	{
		fd = open(argv[i], O_RDONLY);
		param = parse(fd);
		if (ft_atoi(param[0]) > 0)
		{
			if (is_map_first_line_valid(argv[i], param[0]) == 1)
			{
				str = str_creation(count_x(fd), ft_atoi(param[0]), argv[i]);
				if (is_str_valid(str, ft_atoi(param[0]), param[1][0], param[2][0]) == 1)
				{
					str_transpiler(str, param[1][0], param[2][0], ft_atoi(param[0]));
					bsq(str, param, get_tab_cols_amount(str));
					close(fd);
					i++;
					free(str);
				}
				else
					i += write(2, "map error\n", 11);
			}
			else
				i++;
		}
		else
			i += write(2, "map error\n", 11);
	}
}
