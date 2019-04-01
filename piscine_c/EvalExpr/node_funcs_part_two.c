/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_funcs_part_two.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcarolei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/17 18:44:20 by pcarolei          #+#    #+#             */
/*   Updated: 2019/02/17 18:44:21 by pcarolei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "node_struct.h"
#include "other_funcs.h"
#include "string_funcs_part_one.h"
#include "string_funcs_part_two.h"
#include "node_funcs_part_one.h"
#include "node_funcs_part_two_def.h"

t_node	*ft_node_ccfs_helper_func1(char *e_str, int i, t_node *root_node)
{
	ft_node_push_back(&root_node, ft_other_atoi(&e_str[i]), 'e');
	return (root_node);
}

t_node	*ft_node_create_chain_from_str(char *e_str, int e_str_len)
{
	DECL5;
	INIT1;
	root_node = ft_node_create(0, '+');
	while (i < e_str_len - 1)
	{
		pos_of_next_operation = PONO;
		if (C1 || C2)
			return (ft_node_ccfs_helper_func1(e_str, i, root_node));
		if (e_str[i] == '-' && e_str[i + 1] >= '0' && e_str[i + 1] <= '9')
			U;
		if (e_str[i] >= '0' && e_str[i] <= '9')
			E4;
		if (e_str[i] == '-' && e_str[i++ + 1] == '(')
			ft_node_push_back(&root_node, 0, '-');
		if (e_str[i] == '(')
		{
			SOMEELSE;
			while (flag > 0)
				FLG;
			FCK;
		}
	}
	if (LASTCOND1 && LASTCOND2)
		ft_node_push_back(&root_node, e_str[e_str_len - 1] - '0', 'e');
	return (root_node);
}
