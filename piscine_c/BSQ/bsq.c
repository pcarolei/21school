/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcarolei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 23:14:36 by pcarolei          #+#    #+#             */
/*   Updated: 2019/02/20 23:14:39 by pcarolei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int	main(int argc, char **argv)
{
	char	*s;
	char	*str[2];

	s = (char *)malloc(sizeof(char) * 25);
	s = "file_for_standart_input";
	str[0] = NULL;
	str[1] = s;
	if (argc == 1)
	{
		from_st_input();
		from_files(argc + 1, str);
	}
	else
		from_files(argc, argv);
	return (0);
}
