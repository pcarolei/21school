/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcarolei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 22:50:36 by pcarolei          #+#    #+#             */
/*   Updated: 2019/02/06 22:50:40 by pcarolei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_putchar(char c);

void	ft_putstr(const char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		ft_putchar(str[i]);
		i++;
	}
}

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
		while (j < arr_len)
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

int		main(int argc, char **argv)
{
	int		i;
	char	**arr;

	i = 0;
	arr = ft_b_sort(argv, argc - 1);
	if (argc && argv)
	{
		while (arr[i] != '\0')
		{
			if (arr[i] != argv[0])
			{
				ft_putstr(arr[i]);
				ft_putchar('\n');
			}
			i++;
		}
	}
	return (0);
}
