/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isprint.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcarolei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/06 16:28:51 by pcarolei          #+#    #+#             */
/*   Updated: 2019/04/06 16:30:10 by pcarolei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int isprint(int c)
{
	return ((c >= 32) && (c <= 126));
}