/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_advanced_sort_wordtab.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcarolei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 21:37:02 by pcarolei          #+#    #+#             */
/*   Updated: 2019/02/12 21:37:06 by pcarolei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	**ft_b_sort(char **arr, int arr_len, int (*cmp)(char *, char *))
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
			if (cmp(arr[j], arr[j + 1]) > 0)
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

void	ft_sort_wordtab(char **tab, int (*cmp)(char *, char *))
{
	int i;

	i = 0;
	while (tab[i])
		i++;
	tab = ft_b_sort(tab, i);
}
