/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcarolei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 10:28:58 by pcarolei          #+#    #+#             */
/*   Updated: 2020/02/21 11:04:17 by pcarolei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static void	check_cl_flags(t_checker_flags *flags, char **av)
{
	flags->v_flag = 0;
	flags->c_flag = 0;
	if ((av[1]) && (ft_strcmp(av[1], "-v") == 0))
		flags->v_flag = 1;
	if ((av[2]) && (ft_strcmp(av[2], "-c") == 0))
		flags->c_flag = 1;
}

static int	check_eq_cnt_flags_with_args(int ac, t_checker_flags *flags)
{
	int	flags_cnt;

	flags_cnt = 0;
	flags_cnt += flags->v_flag;
	flags_cnt += flags->c_flag;
	if ((ac - 1) == flags_cnt)
	{
		ft_printf("{red}Error{eoc}\n");
		return (1);
	}
	return (0);
}

int			main(int ac, char **av)
{
	int				*tab;
	int				tab_size;
	char			**instructions;
	t_checker_flags	flags;

	if (ac == 1)
		return (0);
	check_cl_flags(&flags, av);
	if (check_eq_cnt_flags_with_args(ac, &flags))
		return (0);
	if (!(tab = read_integer_list(ac, av, flags.v_flag + flags.c_flag)))
		error_handler(tab, NULL);
	if (!(instructions = read_instructions()))
		error_handler(tab, instructions);
	tab_size = ac - 1 - (flags.v_flag + flags.c_flag);
	execute_instructions(tab, tab_size, instructions, &flags);
	return (0);
}
