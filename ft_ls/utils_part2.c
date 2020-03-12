/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_part2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcarolei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 02:20:27 by pcarolei          #+#    #+#             */
/*   Updated: 2020/03/05 11:47:02 by pcarolei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static int	count_dirs(char **filenames)
{
	int	i;
	int	cnt;

	i = 0;
	cnt = 0;
	while (filenames[i])
	{
		if (check_if_dir(filenames[i]))
			cnt++;
		i++;
	}
	return (cnt);
}

char		**dir_filter(char **filenames)
{
	int		i;
	int		j;
	int		dir_cnt;
	char	**dirs;

	dir_cnt = count_dirs(filenames);
	if (!(dirs = ((char **)malloc(sizeof(char *) * (dir_cnt + 1)))))
		return (NULL);
	i = 0;
	j = 0;
	while (i < dir_cnt)
	{
		if (check_if_dir(filenames[j]))
		{
			dirs[i] = ft_strdup(filenames[j]);
			i++;
		}
		j++;
	}
	dirs[i] = NULL;
	free_filenames(filenames);
	return (dirs);
}

int			get_filenames_size(char **filenames)
{
	int	i;

	i = 0;
	while (filenames[i])
		i++;
	return (i);
}

char		*add_postfix_slash(char *filename)
{
	char	*newname;
	int		len;

	len = ft_strlen(filename);
	if (filename[len - 1] != '/')
	{
		newname = ft_strjoin(filename, "/");
		free(filename);
		return (newname);
	}
	return (filename);
}

int			check_if_dir(char *filename)
{
	struct stat	buf;
	int			lstat_ret;

	lstat_ret = lstat(filename, &buf);
	if (S_ISDIR(buf.st_mode))
		return (1);
	return (0);
}
