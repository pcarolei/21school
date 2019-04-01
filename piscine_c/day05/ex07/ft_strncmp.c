/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcarolei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/05 15:51:02 by pcarolei          #+#    #+#             */
/*   Updated: 2019/02/05 15:51:06 by pcarolei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] != '\0' && (i < n))
		i++;
	if (s2[i] == '\0' && s1[i] != '\0')
		return ((int)s1[i]);
	else if (s1[i] == '\0' && s2[i] != '\0')
		return ((int)s2[i]);
	else if ((int)s1[i] != (int)s2[i])
		return ((int)s1[i] - (int)s2[i]);
	return (0);
}
