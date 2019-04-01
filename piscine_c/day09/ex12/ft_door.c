/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_door.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcarolei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/08 05:10:42 by pcarolei          #+#    #+#             */
/*   Updated: 2019/02/08 05:11:32 by pcarolei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_door.h"

void	ft_putstr(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}

t_bool	open_door(t_door *door)
{
	if ((*door).state != OPEN)
	{
		ft_putstr("Door opening...\n");
		(*door).state = OPEN;
	}
	return (OPEN);
}

t_bool	close_door(t_door *door)
{
	ft_putstr("Door closing...\n");
	(*door).state = CLOSE;
	return (CLOSE);
}

t_bool	is_door_open(t_door *door)
{
	ft_putstr("Door is open ?\n");
	return (*door).state;
}

t_bool	is_door_close(t_door *door)
{
	ft_putstr("Door is close ?\n");
	return (*door).state;
}
