/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_error_message.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcarolei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 22:16:12 by pcarolei          #+#    #+#             */
/*   Updated: 2019/02/14 22:16:14 by pcarolei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_helper_funcs.h"
#include "ft_display_error_message.h"

void	ft_display_error_message(char *filename, int error_code)
{
	int i;

	i = 0;
	while (g_error_code_msg[i].error_code != error_code)
		i++;
	ft_putstr_fd(1, "cat: ");
	ft_putstr_fd(1, filename);
	ft_putstr_fd(1, ": ");
	ft_putstr_fd(1, g_error_code_msg[i].str_msg);
}
