/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_wordtab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcarolei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 17:24:42 by pcarolei          #+#    #+#             */
/*   Updated: 2019/02/11 17:24:44 by pcarolei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_strcmp(char *s1, char *s2)
{
	unsigned int i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] != '\0')
		i++;
	if (s2[i] == '\0' && s1[i] != '\0')
		return ((int)s1[i]);
	else if (s1[i] == '\0' && s2[i] != '\0')
		return ((int)s2[i]);
	else if ((int)s1[i] != (int)s2[i])
		return ((int)s1[i] - (int)s2[i]);
	return (0);
}

char	**ft_b_sort(char **arr, int arr_len)
{
	int		i;
	int		j;
	char	*buf;

	i = 0;
	j = 0;
	while (i < arr_len)
	{
		while (j < arr_len - 1)
		{
			if (ft_strcmp(arr[j], arr[j + 1]) > 0)
			{
				buf = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = buf;
			}
			else
				j++;
		}
		j = 0;
		i++;
	}
	return (arr);
}

void	ft_sort_wordtab(char **tab)
{
	int i;

	i = 0;
	while (tab[i])
		i++;
	tab = ft_b_sort(tab, i);
}
