/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_part3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcarolei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 02:20:27 by pcarolei          #+#    #+#             */
/*   Updated: 2020/03/05 11:48:21 by pcarolei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static int	count_files_in_dir(t_flags *flags, char *dirname)
{
	DIR				*dir_ptr;
	struct dirent	*dp;
	int				files_cnt;

	files_cnt = 0;
	if (!(dir_ptr = opendir(dirname)))
		return (-1);
	while ((dp = readdir(dir_ptr)) != NULL)
	{
		if ((dp->d_name[0] == '.') && (flags->a != 1))
			continue;
		else
			files_cnt++;
	}
	(void)closedir(dir_ptr);
	return (files_cnt);
}

char		**get_all_filenames_in_dir(t_flags *flags, char *dirname)
{
	char			**arr_filenames;
	int				files_cnt;
	DIR				*dir_ptr;
	struct dirent	*dp;
	int				i;

	files_cnt = count_files_in_dir(flags, dirname);
	if (!(arr_filenames = (char **)malloc(sizeof(char *) * (files_cnt + 1))))
		return (NULL);
	if (!(dir_ptr = opendir(dirname)))
		return (NULL);
	i = 0;
	while ((dp = readdir(dir_ptr)) != NULL)
	{
		if ((flags->a != 1) && (dp->d_name[0] == '.'))
			continue;
		else
		{
			arr_filenames[i] = ft_strdup(dp->d_name);
			i++;
		}
	}
	(void)closedir(dir_ptr);
	arr_filenames[files_cnt] = NULL;
	return (sort(flags, arr_filenames, files_cnt));
}

char		*get_username_by_uid(uid_t uid)
{
	struct passwd	res;

	res = *getpwuid(uid);
	return (ft_strdup(res.pw_name));
}

char		*get_group_by_gid(int gid)
{
	struct group	res;

	res = *getgrgid(gid);
	return (ft_strdup(res.gr_name));
}

char		*crop_time(char *timestr)
{
	char	*res;
	int		size;
	int		i;

	size = ft_strlen(timestr) - 13;
	if (!(res = (char *)malloc(size)))
		return (NULL);
	i = 0;
	while (i < size)
	{
		res[i] = timestr[i + 4];
		i++;
	}
	res[size] = '\0';
	return (res);
}
