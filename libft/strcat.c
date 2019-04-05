/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strcat.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcarolei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 13:00:21 by pcarolei          #+#    #+#             */
/*   Updated: 2019/04/05 13:00:29 by pcarolei         ###   ########.fr       */
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

char	*strcat(char *dest, char *src)
{
	unsigned int i;
	unsigned int k;

	i = strlen(dest);
	k = 0;
	while (src[k] != '\0')
	{
		dest[i] = src[k];
		i++;
		k++;
	}
	dest[i] = '\0';
	return (dest);
}
