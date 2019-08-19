/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcarolei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/19 11:06:03 by pcarolei          #+#    #+#             */
/*   Updated: 2019/08/19 11:10:21 by pcarolei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE 32
# include <stdlib.h>
# include "./libft/libft.h"

typedef struct	s_fd_list
{
	int					fd;
	char				*fd_str;
	char				*tmp;
	struct s_fd_list	*next;
}				t_fd_list;

int				get_next_line(const int fd, char **line);
# define NODE (find_node_by_fd(fd, fd_list))

#endif
