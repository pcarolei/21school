/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_error_message.h                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcarolei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 22:16:17 by pcarolei          #+#    #+#             */
/*   Updated: 2019/02/14 23:16:47 by pcarolei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_DISPLAY_ERROR_MESSAGE_H
# define FT_DISPLAY_ERROR_MESSAGE_H

# include <errno.h>

typedef struct		s_error_code_msg
{
	int		error_code;
	char	*str_msg;
}					t_error_code_msg;

t_error_code_msg	g_error_code_msg[] =
{
	{EPERM, "Operation not permitted\n"},
	{ENOENT, "No such file or directory\n"},
	{EINTR, "Interrupted system call\n"},
	{EIO, "I/O error\n"},
	{EAGAIN, "Try again\n"},
	{ENOMEM, "Out of memory\n"},
	{EACCES, "Permission denied\n"},
	{EBUSY, "Device or resource busy\n"},
	{EEXIST, "File exists\n"},
	{EISDIR, "Is a directory\n"},
	{EINVAL, "Invalid argument\n"},
	{ENOSPC, "No space left on device\n"},
	{ETXTBSY, "Text file busy\n"},
	{EMFILE, "Too many open files\n"},
	{EROFS, "Read-only file system\n"},
	{ENAMETOOLONG, "File name too long\n"},
};

void				ft_display_error_message(char *filename, int error);

#endif
