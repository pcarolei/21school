/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_line_args_parser.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcarolei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 02:20:27 by pcarolei          #+#    #+#             */
/*   Updated: 2020/03/05 11:40:35 by pcarolei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static int	check_option(char *option)
{
	size_t	i;
	size_t	option_len;

	i = 1;
	option_len = ft_strlen(option);
	if ((option_len > 6) || (option_len == 1))
		return (0);
	while (i < option_len)
	{
		if ((option[i] == 'l') || (option[i] == 'R') || (option[i] == 'a')
				|| (option[i] == 'r') || (option[i] == 't'))
			i++;
		else
			return (0);
	}
	return (1);
}

static int	parse_options(char **options, int ac, char **av)
{
	int	i;

	i = 0;
	while ((i + 1 < ac) && (av[i + 1][0] == '-'))
	{
		if (check_option(av[i + 1]))
			options[i] = av[i + 1];
		else
			return (-1);
		i++;
	}
	return (i);
}

static int	flags_fill(t_flags *flags, char **options, int options_size)
{
	int	i;

	i = 0;
	while (i < options_size)
	{
		if (ft_strstr(options[i], "l"))
			flags->l = 1;
		if (ft_strstr(options[i], "a"))
			flags->a = 1;
		if (ft_strstr(options[i], "t"))
			flags->t = 1;
		if (ft_strstr(options[i], "r"))
			flags->rev = 1;
		if (ft_strstr(options[i], "R"))
			flags->rec = 1;
		i++;
	}
	return (1);
}

static char	**parse_filenames(int options_size, char **av, int ac)
{
	int		i;
	int		ii;
	char	**filenames;

	if (ac - 1 == options_size)
		return (ft_strsplit(".", ' '));
	filenames = (char **)malloc(sizeof(char *) * (ac - options_size));
	i = 1 + options_size;
	ii = 0;
	while (av[i])
	{
		if (check_if_dir(av[i]))
			filenames[ii] = add_postfix_slash(ft_strdup(av[i]));
		else
			filenames[ii] = ft_strdup(av[i]);
		i++;
		ii++;
	}
	filenames[ii] = NULL;
	return (filenames);
}

char		**command_line_args_parser(t_flags *flags, int ac, char **av)
{
	char	options[ac - 1][6];
	int		options_size;

	(void)flags;
	options_size = parse_options((char **)options, ac, av);
	if (options_size == -1)
	{
		perror("illegal option\n");
		exit(1);
	}
	flags_fill(flags, (char **)options, options_size);
	return (parse_filenames(options_size, av, ac));
}
