/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorts.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcarolei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 02:20:27 by pcarolei          #+#    #+#             */
/*   Updated: 2020/03/05 11:39:03 by pcarolei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void	arr_filenames_reverse(char **arr_filenames, int size)
{
	int		i;
	char	*tmp;

	i = 0;
	while (i < (size / 2) - 1)
	{
		tmp = arr_filenames[i];
		arr_filenames[i] = arr_filenames[size - 1 - i];
		arr_filenames[size - 1 - i] = tmp;
		i++;
	}
	arr_filenames[size] = NULL;
}

void		lexicographical_sort(char **arr_filenames, int size)
{
	int		i;
	int		j;
	char	*key;

	i = 1;
	while (i < size)
	{
		key = arr_filenames[i];
		j = i - 1;
		while (j >= 0 && (ft_strcmp(arr_filenames[j], key) > 0))
		{
			arr_filenames[j + 1] = arr_filenames[j];
			j = j - 1;
		}
		arr_filenames[j + 1] = key;
		i++;
	}
}

static void	last_modif_time_sort(char **arr_filenames, int size)
{
	int		i;
	int		j;
	char	*key;

	i = 1;
	while (i < size)
	{
		key = arr_filenames[i];
		j = i - 1;
		while (j >= 0 && (compare_two_modif_times(arr_filenames[j], key) > 0))
		{
			arr_filenames[j + 1] = arr_filenames[j];
			j = j - 1;
		}
		arr_filenames[j + 1] = key;
		i++;
	}
}

static void	last_modif_time_sort_rev(char **arr_filenames, int size)
{
	int		i;
	int		j;
	char	*key;

	i = 1;
	while (i < size)
	{
		key = arr_filenames[i];
		j = i - 1;
		while (j >= 0 && (compare_two_modif_times(arr_filenames[j], key) > 0))
		{
			arr_filenames[j + 1] = arr_filenames[j];
			j = j - 1;
		}
		arr_filenames[j + 1] = key;
		i++;
	}
}

char		**sort(t_flags *flags, char **arr_filenames, int size)
{
	if ((flags->t == 1) && (flags->rev == 1))
		last_modif_time_sort_rev(arr_filenames, size);
	else if (flags->t == 1)
		last_modif_time_sort(arr_filenames, size);
	else if (flags->rev == 1)
	{
		lexicographical_sort(arr_filenames, size);
		arr_filenames_reverse(arr_filenames, size);
	}
	else
		lexicographical_sort(arr_filenames, size);
	return (arr_filenames);
}
