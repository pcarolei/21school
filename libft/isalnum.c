/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isalnum.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcarolei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 20:11:19 by pcarolei          #+#    #+#             */
/*   Updated: 2019/04/05 20:13:24 by pcarolei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int isalnum(int c)
{
	return ((c >= 48 && c <= 57) || (c >= 65 && c <= 90) || (c >= 97 && c <= 122));
}
