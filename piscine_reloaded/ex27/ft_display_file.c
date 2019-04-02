/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcarolei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 15:39:33 by pcarolei          #+#    #+#             */
/*   Updated: 2019/04/02 18:29:47 by pcarolei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include "ft_display_file.h"

int		ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

void	ft_putstr_fd(int fd, char *str)
{
	write(fd, str, ft_strlen(str));
}

void	ft_display_file(char *filename)
{
	int		fd;
	int		ret;
	char	buf[BUFF_SIZE + 1];

	fd = open(filename, O_RDONLY | O_RDWR);
	ret = read(fd, buf, BUFF_SIZE);
	while (ret)
	{
		buf[ret] = '\0';
		ft_putstr_fd(1, buf);
		ret = read(fd, buf, BUFF_SIZE);
	}
	close(fd);
	return ;
}

int		main(int argc, char **argv)
{
	if (argc == 1)
		ft_putstr_fd(2, "File name missing.\n");
	else if (argc > 2)
		ft_putstr_fd(2, "Too many arguments.\n");
	else
		ft_display_file(argv[1]);
	return (0);
}
