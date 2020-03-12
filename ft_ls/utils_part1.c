/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_part1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcarolei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 02:20:27 by pcarolei          #+#    #+#             */
/*   Updated: 2020/03/05 11:46:42 by pcarolei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		free_filenames(char **filenames)
{
	int	i;

	if (!filenames)
		return ;
	i = 0;
	while (filenames[i])
	{
		free(filenames[i]);
		i++;
	}
	free(filenames);
}

static int	get_used_block_count(char *filename)
{
	struct stat		buf;

	stat(filename, &buf);
	if (buf.st_blocks == 0)
		return (0);
	return (buf.st_blocks);
}

int			get_total(char **filenames, char *dirname)
{
	int		i;
	int		total;
	char	*full_filename;

	total = 0;
	i = 0;
	while (filenames[i])
	{
		full_filename = add_dirname_prefix(filenames[i], dirname);
		total += get_used_block_count(full_filename);
		free(full_filename);
		i++;
	}
	return (total);
}

void		add_dirname_prefix_to_filenames(char **filenames, char *dirname)
{
	int		i;
	char	*tmp1;
	char	*tmp2;

	i = 0;
	if ((ft_strcmp(dirname, ".") == 0) || (ft_strcmp(dirname, "..") == 0))
		return ;
	while (filenames[i])
	{
		tmp1 = ft_strjoinfree(ft_strdup(dirname), ft_strdup("/"));
		tmp2 = ft_strjoinfree(tmp1, filenames[i]);
		filenames[i] = tmp2;
		i++;
	}
}

char		*add_dirname_prefix(char *filename, char *dirname)
{
	char	*tmp1;
	char	*tmp2;

	tmp1 = ft_strjoin(dirname, "/");
	tmp2 = ft_strjoin(tmp1, filename);
	free(tmp1);
	return (tmp2);
}
