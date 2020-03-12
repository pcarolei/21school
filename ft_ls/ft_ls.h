/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcarolei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 02:20:27 by pcarolei          #+#    #+#             */
/*   Updated: 2020/03/05 12:07:02 by pcarolei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include "libft/libft.h"
# include <dirent.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <pwd.h>
# include <uuid/uuid.h>
# include <grp.h>
# include <sys/xattr.h>
# include <time.h>
# include <errno.h>
# include <stdio.h>
# include <string.h>

# define PATH_MAX 512

typedef struct	s_flags
{
	int		l;
	int		a;
	int		t;
	int		rev;
	int		rec;
}				t_flags;

typedef struct	s_long_format
{
	char	*filemode;
	int		number_of_links;
	char	*owner_name;
	char	*group_name;
	int		num_of_bytes;
	char	*last_modif_date;
	char	*filename;
}				t_long_format;

int				ft_error(char *msg);
void			display_rec(t_flags *flags, char **filenames);
void			display_and_free_file_lf(t_long_format *lf);
void			display_file(t_flags *flags, char *full_filename,
															char *filename);
char			**command_line_args_parser(t_flags *flags, int ac, char **av);
void			display(t_flags *flags, char **filenames);
void			free_filenames(char **filenames);
int				get_total(char **filenames, char *dirname);
void			add_dirname_prefix_to_filenames(char **filenames,
														char *dirname);
char			*add_dirname_prefix(char *filename, char *dirname);
char			**dir_filter(char **filenames);
int				get_filenames_size(char **filenames);
int				check_if_dir(char *filename);
char			*add_postfix_slash(char *filename);
char			*get_username_by_uid(uid_t uid);
char			*get_group_by_gid(int gid);
char			*crop_time(char *timestr);
char			*mode_to_str(int mode);
char			**get_all_filenames_in_dir(t_flags *flags, char *dirname);
char			*get_symlink_filename(char *full_filename);
long long int	get_file_last_modif_time(char *filename);
int				compare_two_modif_times(char *f1, char *f2);
char			**sort(t_flags *flags, char **arr_filenames, int size);
void			lexicographical_sort(char **arr_filenames, int size);

#endif
