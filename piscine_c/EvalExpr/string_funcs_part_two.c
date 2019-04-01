/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_funcs_part_two.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcarolei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/17 18:27:38 by pcarolei          #+#    #+#             */
/*   Updated: 2019/02/17 18:27:40 by pcarolei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "string_funcs_part_one.h"
#include <stdlib.h>

#define T1 new_str[k] = '-';
#define T2 new_str[k + 1] = '1';
#define T3 new_str[k + 2] = '*';
#define T4 new_str[k + 3] = '(';
#define T5 {T1 T2 T3 T4 k += 2;}

char	*ft_string_remove_spaces(char *str)
{
	int		i;
	int		k;
	int		str_len;
	int		amount_of_spaces;
	char	*new_str;

	i = 0;
	k = 0;
	str_len = ft_string_get_length(str);
	amount_of_spaces = ft_string_count_spaces(str);
	new_str = (char *)malloc(sizeof(char) * (str_len - amount_of_spaces + 1));
	while (i < str_len)
	{
		if (str[i] != ' ' && str[i] != '\t')
		{
			new_str[k] = str[i];
			k++;
		}
		i++;
	}
	new_str[str_len - amount_of_spaces + 1] = '\0';
	return (new_str);
}

char	*ft_string_create_string_from_part(char *str, int p_op_br, int p_cl_br)
{
	int		i;
	char	*new_str;

	i = 0;
	new_str = (char *)malloc(sizeof(char) * (p_cl_br - p_op_br + 1));
	while (i != (p_cl_br - p_op_br + 1))
	{
		new_str[i] = str[p_op_br + i];
		i++;
	}
	new_str[p_cl_br - p_op_br + 1] = '\0';
	return (new_str);
}
