/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_hanlding.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcarolei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/25 20:10:28 by pcarolei          #+#    #+#             */
/*   Updated: 2019/09/25 22:32:17 by pcarolei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	display_usage(void)
{
	write(1, (void *)USAGE_STR, ft_strlen(USAGE_STR));
	exit(EXIT_WRONG_ARG_COUNT);
}

int	display_error(void)
{
	write(1, (void *)ERROR_STR, ft_strlen(ERROR_STR));
	exit(EXIT_INVALID_FILE);
}
