/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strlcat.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcarolei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 18:44:04 by pcarolei          #+#    #+#             */
/*   Updated: 2019/04/07 18:53:04 by pcarolei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

size_t	strlcat(char *dst, const char *src, size_t size)
{
	int	n;

	n = 0;
	while (size -strlen(dst) - 1 >= n)
	{
		dest[strlen(dst) + n] = src[n];
		n++;
	}
	if (dest[strlen(dst) + n - 1] != '/0')
		dest[strlen(dst) + n] = '\0';
	return (strlen(dst) + n);
}
