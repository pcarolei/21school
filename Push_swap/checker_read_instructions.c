/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_read_instructions.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcarolei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 10:28:58 by pcarolei          #+#    #+#             */
/*   Updated: 2020/03/09 20:21:22 by pcarolei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static int	check_instruction(char *str)
{
	if (ft_strcmp(str, "sa") == 0)
		return (1);
	if (ft_strcmp(str, "sb") == 0)
		return (1);
	if (ft_strcmp(str, "ss") == 0)
		return (1);
	if (ft_strcmp(str, "pa") == 0)
		return (1);
	if (ft_strcmp(str, "pb") == 0)
		return (1);
	if (ft_strcmp(str, "ra") == 0)
		return (1);
	if (ft_strcmp(str, "rb") == 0)
		return (1);
	if (ft_strcmp(str, "rr") == 0)
		return (1);
	if (ft_strcmp(str, "rra") == 0)
		return (1);
	if (ft_strcmp(str, "rrb") == 0)
		return (1);
	if (ft_strcmp(str, "rrr") == 0)
		return (1);
	return (0);
}

char		**read_instructions(void)
{
	char	**instructions;
	char	*input_instructions_str;
	char	*tmp;
	char	*line;
	int		gnl_ret;

	input_instructions_str = ft_strnew(0);
	while ((gnl_ret = get_next_line(0, &line)) > 0)
	{
		if (check_instruction(line))
		{
			tmp = ft_strjoin(input_instructions_str, line);
			free(input_instructions_str);
			input_instructions_str = ft_strjoin(tmp, " ");
			free(tmp);
			free(line);
		}
		else
			return (free_2_args(input_instructions_str, line));
	}
	line = ft_strtrim(input_instructions_str);
	instructions = ft_strsplit(line, ' ');
	free_2_args(input_instructions_str, line);
	return (instructions);
}
