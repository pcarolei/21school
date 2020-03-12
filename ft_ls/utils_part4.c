/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_part4.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcarolei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 02:20:27 by pcarolei          #+#    #+#             */
/*   Updated: 2020/03/05 11:53:05 by pcarolei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static int		filetypeletter(int mode)
{
	char	c;

	if (S_ISREG(mode))
		c = '-';
	else if (S_ISDIR(mode))
		c = 'd';
	else if (S_ISBLK(mode))
		c = 'b';
	else if (S_ISCHR(mode))
		c = 'c';
	else if (S_ISFIFO(mode))
		c = 'p';
	else if (S_ISLNK(mode))
		c = 'l';
	else if (S_ISSOCK(mode))
		c = 's';
	else
		c = '?';
	return (c);
}

char			*mode_to_str(int mode)
{
	char	bits[11];
	char	*rwx[8];

	rwx[0] = "---";
	rwx[1] = "--x";
	rwx[2] = "-w-";
	rwx[3] = "-wx";
	rwx[4] = "r--";
	rwx[5] = "r-x";
	rwx[6] = "rw-";
	rwx[7] = "rwx";
	bits[0] = filetypeletter(mode);
	ft_strcpy(&bits[1], rwx[(mode >> 6) & 7]);
	ft_strcpy(&bits[4], rwx[(mode >> 3) & 7]);
	ft_strcpy(&bits[7], rwx[(mode & 7)]);
	if (mode & S_ISUID)
		bits[3] = (mode & S_IXUSR) ? 's' : 'S';
	if (mode & S_ISGID)
		bits[6] = (mode & S_IXGRP) ? 's' : 'l';
	if (mode & S_ISVTX)
		bits[9] = (mode & S_IXOTH) ? 't' : 'T';
	bits[10] = '\0';
	return (ft_strdup(bits));
}

char			*get_symlink_filename(char *filename)
{
	ssize_t	readlink_ret;
	char	buf[PATH_MAX + 1];
	char	*tmp;
	char	*res;

	if (-1 == (readlink_ret = readlink(filename, buf, PATH_MAX)))
		return (NULL);
	buf[PATH_MAX] = '\0';
	tmp = ft_strjoin(filename, " -> ");
	res = ft_strjoin(tmp, buf);
	free(tmp);
	return (res);
}

long long int	get_file_last_modif_time(char *filename)
{
	struct stat		buf;
	int				lstat_ret;
	struct timespec	lmt;

	if (-1 == (lstat_ret = lstat(filename, &buf)))
		return (-1);
	lmt = buf.st_mtimespec;
	return (buf.st_mtimespec.tv_sec);
}

int				compare_two_modif_times(char *f1, char *f2)
{
	long long int	t1;
	long long int	t2;

	t1 = get_file_last_modif_time(f1);
	t2 = get_file_last_modif_time(f2);
	if (t1 < t2)
		return (1);
	return (0);
}
