/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcarolei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 02:20:27 by pcarolei          #+#    #+#             */
/*   Updated: 2020/03/05 11:39:47 by pcarolei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void		filenames_free(char **filenames)
{
	int	i;

	i = 0;
	while (filenames[i])
	{
		free(filenames[i]);
		i++;
	}
	free(filenames);
}

static t_flags	*flags_initializer(t_flags *flags)
{
	flags->l = 0;
	flags->a = 0;
	flags->t = 0;
	flags->rev = 0;
	flags->rec = 0;
	return (flags);
}

int				main(int ac, char **av)
{
	t_flags		flags;
	char		**filenames;

	filenames = command_line_args_parser(flags_initializer(&flags), ac, av);
	if (filenames)
		display(&flags, filenames);
	filenames_free(filenames);
	return (0);
}
