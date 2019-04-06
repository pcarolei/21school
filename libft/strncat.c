/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strncat.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcarolei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 19:37:23 by pcarolei          #+#    #+#             */
/*   Updated: 2019/04/06 17:40:00 by pcarolei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		strlen(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*strncat(char *dest, char *src, int n)
{
	unsigned int i;
	unsigned int k;

	i = strlen(dest);
	k = 1;
	while (src[k] != '\0' && k < n)
	{
		dest[i] = src[k];
		i++;
		k++;
	}
	dest[i] = '\0';
	return (dest);
}
