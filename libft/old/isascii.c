/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isascii.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcarolei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 16:38:46 by pcarolei          #+#    #+#             */
/*   Updated: 2019/04/05 16:38:55 by pcarolei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int isascii(int c)
{
	return (c >= 0 && c <= 127);
}