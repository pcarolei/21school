/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   toupper.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcarolei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 18:15:10 by pcarolei          #+#    #+#             */
/*   Updated: 2019/04/07 18:18:37 by pcarolei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int toupper(int c)
{
	if ((c <= 97) || (c >= 122))
		return (c);	
	return (c - 32);
}
