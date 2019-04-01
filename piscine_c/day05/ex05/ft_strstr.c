/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcarolei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 19:32:58 by pcarolei          #+#    #+#             */
/*   Updated: 2019/02/04 19:33:02 by pcarolei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strstr(char *str, char *to_find)
{
	int i;
	int j;
	int length_to_find;

	i = 0;
	j = 0;
	length_to_find = ft_strlen(to_find);
	while (str[i] != '\0')
	{
		if (str[i] == to_find[0])
		{
			while (str[i + j] == to_find[j] && str[i + j] != '\0')
				j++;
			if (j == length_to_find)
				return (&str[i]);
			else
			{
				i += j;
				j = 0;
			}
		}
		else
			i++;
	}
	return (0);
}
