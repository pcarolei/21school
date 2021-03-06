/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcarolei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/31 15:39:02 by pcarolei          #+#    #+#             */
/*   Updated: 2019/01/31 15:39:07 by pcarolei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrev(char *str)
{
	char	swp;
	int		i;
	int		k;

	i = 0;
	k = 0;
	while (str[i] != '\0')
		i++;
	i--;
	while (k <= i)
	{
		swp = str[k];
		str[k] = str[i];
		str[i] = swp;
		k++;
		i--;
	}
	return (str);
}
