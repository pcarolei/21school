/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcarolei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/29 06:10:17 by pcarolei          #+#    #+#             */
/*   Updated: 2019/08/05 02:29:42 by pcarolei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*separator(char *fd_str, int opt)
{
	size_t	n_pos;
	char	*new_line;

	if (opt == 1 && !(ft_strchr(fd_str, '\n')))
		return (fd_str);
	if (opt == 2 && !(ft_strchr(fd_str, '\n')))
		return (NULL);
	n_pos = ft_strchr(fd_str, '\n') - fd_str;
	if (opt == 1)
		return (ft_strsub(fd_str, 0, n_pos));
	new_line = ft_strsub(fd_str, n_pos + 1, ft_strlen(fd_str));
	free(fd_str);
	return (new_line);
}

char	*joiner(char *fd_str, char *read_buf)
{
	char	*new_fd_str;

	new_fd_str = ft_strjoin(fd_str, read_buf);
	free(fd_str);
	return (new_fd_str);
}

int		get_next_line(const int fd, char **line)
{
	int			ret;
	char		read_buf[BUFF_SIZE + 1];
	static char	*fd_str;

	if (fd < 0 || BUFF_SIZE < 0 || !line)
		return (-1);
	if (!fd_str)
		fd_str = ft_strnew(1);
	while (!(ft_strchr(fd_str, '\n')) && (ret = 1))
	{
		ret = read(fd, read_buf, BUFF_SIZE);
		if (ret == -1)
			return (-1);
		read_buf[ret] = '\0';
		fd_str = joiner(fd_str, read_buf);
		if (ret == 0 && fd_str[0] == '\0')
			return (0);
		if (ret == 0)
			break;
	}
	*line = separator(fd_str, 1);
	fd_str = separator(fd_str, 2);
	return (1);
}
