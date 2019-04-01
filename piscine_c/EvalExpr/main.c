/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcarolei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/17 18:11:51 by pcarolei          #+#    #+#             */
/*   Updated: 2019/02/17 18:11:52 by pcarolei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "node_struct.h"
#include "other_funcs.h"
#include "string_funcs_part_one.h"
#include "string_funcs_part_two.h"
#include "node_funcs_part_one.h"
#include "node_funcs_part_two.h"

int		eval_expr(char *str)
{
	t_node	*node_chain;
	char	*new_str;

	new_str = ft_string_remove_spaces(str);
	ft_string_change_signes_mm_to_mp(new_str);
	new_str = ft_string_remove_spaces(str);
	node_chain = ft_node_create_chain_from_str(new_str,
		ft_string_get_length(new_str));
	return (ft_node_evaluate_chain(node_chain));
}

int		main(int ac, char **av)
{
	if (ac > 1)
	{
		ft_putnbr(eval_expr(av[1]));
		ft_putchar('\n');
	}
	return (0);
}
