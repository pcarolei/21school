/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_concat_params.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcarolei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 16:01:37 by pcarolei          #+#    #+#             */
/*   Updated: 2019/02/07 16:01:39 by pcarolei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int		ft_char_count(char **arr)
{
	int		char_count;
	int		i;
	int		j;

	char_count = 0;
	i = 1;
	j = 0;
	while (arr[i] != '\0')
	{
		while (arr[i][j] != '\0')
		{
			char_count++;
			j++;
		}
		j = 0;
		char_count++;
		i++;
	}
	return (char_count);
}

char	*ft_concat_params(int argc, char **argv)
{
	int		i;
	int		j;
	int		k;
	int		char_count;
	char	*str;

	char_count = ft_char_count(argv);
	str = (char*)malloc(sizeof(char) * char_count);
	i = 1;
	j = 0;
	k = 0;
	while (argv[i] != '\0')
	{
		while (argv[i][j] != '\0')
		{
			str[k] = argv[i][j];
			j++;
			k++;
			if (k != char_count - 1)
				str[k++] = '\n';
		}
		j = 0;
		i++;
	}
	return (str);
}
