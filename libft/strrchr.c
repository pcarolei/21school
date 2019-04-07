/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strrchr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcarolei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 18:43:01 by pcarolei          #+#    #+#             */
/*   Updated: 2019/04/07 18:43:40 by pcarolei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*strrchr(const char *s, int c)
{
	int	i;
	i = strlen(s);
	while (s[i] != (c + '0'))
		i--;
	if (i == -1)
		return (NULL);
	return (s[i + 1]); 
}
