/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_door.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcarolei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/08 04:28:29 by pcarolei          #+#    #+#             */
/*   Updated: 2019/02/08 05:20:15 by pcarolei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_DOOR_H
# define FT_DOOR_H
# include <unistd.h>

typedef	int		t_bool;
# define true 	1
# define false 	0

# define OPEN true
# define CLOSE false

typedef	struct	s_door
{
	t_bool	state;
}				t_door;

void	ft_putstr(char *str);
t_bool	open_door(t_door *door);
t_bool	close_door(t_door *door);
t_bool	is_door_open(t_door *door);
t_bool	is_door_close(t_door *door);

#endif
