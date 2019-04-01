/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cat.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcarolei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 16:58:30 by pcarolei          #+#    #+#             */
/*   Updated: 2019/02/14 23:09:27 by pcarolei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <errno.h>

#include "ft_cat.h"
#include "ft_helper_funcs.h"

int		ft_display_file(char *filename)
{
	int		fd;
	int		ret;
	char	buf[BUFF_SIZE + 1];

	fd = open(filename, O_RDONLY | O_RDWR);
	if (fd == -1)
	{
		ft_display_error_message(filename, errno);
		return (-1);
	}
	ret = read(fd, buf, BUFF_SIZE);
	while (ret)
	{
		buf[ret] = '\0';
		ft_putstr_fd(1, buf);
		ret = read(fd, buf, BUFF_SIZE);
	}
	ret = close(fd);
	if (ret == -1)
	{
		ft_display_error_message(filename, errno);
		return (-1);
	}
	return (0);
}

void	ft_display_user_input(void)
{
	int		i;
	char	buf[BUFF_SIZE];

	i = read(0, buf, sizeof(buf));
	while (i != 0)
	{
		write(1, buf, i);
		i = read(0, buf, sizeof(buf));
	}
}

int		main(int argc, char **argv)
{
	int i;
	int res;

	i = 1;
	res = 0;
	if (argc == 1)
		ft_display_user_input();
	else
		while (argv[i])
		{
			if (argv[i][0] == '-' && argv[i][1] == '\0')
				ft_display_user_input();
			else
				res = ft_display_file(argv[i++]);
		}
	return (res);
}
