/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcarolei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 02:20:27 by pcarolei          #+#    #+#             */
/*   Updated: 2020/03/09 20:40:36 by pcarolei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		display_and_free_file_lf(t_long_format *lf)
{
	ft_printf("%s  %d %s  %s  %d %s %s\n", lf->filemode, lf->number_of_links,
		lf->owner_name, lf->group_name, lf->num_of_bytes, lf->last_modif_date,
		lf->filename);
	free(lf->filemode);
	free(lf->owner_name);
	free(lf->group_name);
	free(lf->last_modif_date);
	free(lf->filename);
}

static char	**display_dir(t_flags *flags, char *dirname, int show_total)
{
	char	**arr_filenames;
	char	*full_filename;
	int		i;

	if (!(arr_filenames = get_all_filenames_in_dir(flags, dirname)))
		return (NULL);
	i = 0;
	if (show_total && (flags->l == 1))
		ft_printf("total %d\n", get_total(arr_filenames, dirname));
	while (arr_filenames[i])
	{
		full_filename = add_dirname_prefix(arr_filenames[i], dirname);
		display_file(flags, full_filename, arr_filenames[i]);
		free(full_filename);
		i++;
	}
	return (arr_filenames);
}

static void	display_filename(t_flags *flags, char *filename,
								int display_dirname, int first_size)
{
	struct stat	buf;
	int			lstat_ret;
	char		**arr_filenames;

	if (-1 == (lstat_ret = lstat(filename, &buf)))
		ft_error("cant open that file\n");
	if (S_ISDIR(buf.st_mode))
	{
		if (display_dirname)
			ft_printf("%s:\n", filename);
		arr_filenames = display_dir(flags, filename, first_size >= 1);
	}
	else if (S_ISREG(buf.st_mode))
	{
		display_file(flags, filename, filename);
		arr_filenames = NULL;
	}
	ft_printf("\n");
	if ((flags->rec == 1) && (arr_filenames))
	{
		add_dirname_prefix_to_filenames(arr_filenames, filename);
		display_rec(flags, dir_filter(arr_filenames));
	}
	else
		free_filenames(arr_filenames);
}

void		display_rec(t_flags *flags, char **filenames)
{
	int	i;
	int	filenames_size;

	if (!filenames)
		return ;
	ft_printf("\n");
	filenames_size = get_filenames_size(filenames);
	sort(flags, filenames, filenames_size);
	i = (flags->a == 1) ? 2 : 0;
	while (filenames[i])
	{
		display_filename(flags, filenames[i], 1, filenames_size > 0);
		i++;
	}
	free_filenames(filenames);
}

void		display(t_flags *flags, char **filenames)
{
	int	i;
	int	filenames_size;

	if (!filenames)
		return ;
	filenames_size = get_filenames_size(filenames);
	sort(flags, filenames, filenames_size);
	i = 0;
	while (filenames[i])
	{
		display_filename(flags, filenames[i], filenames_size > 1,
				filenames_size > 0);
		i++;
	}
}
