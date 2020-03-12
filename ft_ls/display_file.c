/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcarolei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 02:20:27 by pcarolei          #+#    #+#             */
/*   Updated: 2020/03/09 20:39:13 by pcarolei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	display_file(t_flags *flags, char *full_filename, char *filename)
{
	struct stat		buf;
	t_long_format	lf;
	int				lstat_ret;

	if (flags->l == 1)
	{
		if ((-1 == (lstat_ret = lstat(full_filename, &buf))))
		{
			perror("cant open that file\n");
			exit(1);
		}
		lf.filemode = mode_to_str(buf.st_mode);
		lf.number_of_links = buf.st_nlink;
		lf.owner_name = get_username_by_uid(buf.st_uid);
		lf.group_name = get_group_by_gid(buf.st_gid);
		lf.num_of_bytes = buf.st_size;
		lf.last_modif_date = crop_time(ctime(
					(const time_t *)&buf.st_mtimespec));
		lf.filename = (S_ISLNK(buf.st_mode)) ?
			get_symlink_filename(full_filename) : ft_strdup(filename);
		display_and_free_file_lf(&lf);
	}
	else
		ft_printf("%s\n", filename);
}
