/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcarolei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/29 06:10:51 by pcarolei          #+#    #+#             */
/*   Updated: 2019/08/04 21:01:32 by pcarolei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define BUFF_SIZE 32
#include <stdlib.h>
#include "./libft/libft.h"

int	get_next_line(const int fd, char **line);

/*
 *  DEV HEADERS BELOW
 * 	DELETE BEFORE PUSHING TO GIT
 */

#include <stdio.h>
#include <string.h>
#include <fcntl.h>			// Тут всякие O_RDONLY и тд
