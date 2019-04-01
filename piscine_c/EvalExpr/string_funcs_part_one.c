/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_funcs_part_one.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcarolei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/17 18:21:52 by pcarolei          #+#    #+#             */
/*   Updated: 2019/02/17 18:21:54 by pcarolei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_string_get_number_of_next_operation(char *str, int n)
{
	int i;

	i = 0;
	while (str[n + i] >= '0' && str[n + i] <= '9')
		i++;
	return (n + i);
}

int		ft_string_get_length(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int		ft_string_count_spaces(char *str)
{
	int i;
	int count;

	i = 0;
	count = 0;
	while (str[i] != '\0')
	{
		if (str[i] == ' ' | str[i] == '\t')
			count++;
		i++;
	}
	return (count);
}

int		ft_string_get_length_of_number(char *str)
{
	int		i;

	i = 0;
	while (str[i] >= '0' && str[i] <= '0')
		i++;
	return (i);
}

void	ft_string_change_signes_mm_to_mp(char *str)
{
	int i;

	i = 0;
	while (str[i + 1] != 0)
	{
		if (str[i] == '-' && str[i + 1] == '-')
		{
			str[i] = '+';
			str[i + 1] = ' ';
		}
		i++;
	}
}
