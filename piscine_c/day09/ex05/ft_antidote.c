/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_antidote.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcarolei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 21:24:09 by pcarolei          #+#    #+#             */
/*   Updated: 2019/02/07 21:24:12 by pcarolei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_antidote(int i, int j, int k)
{
	int t;
	int	buf;
	int	arr[3];

	t = 0;
	buf = 0;
	arr[0] = i;
	arr[1] = j;
	arr[2] = k;
	while (arr[t] != '\0' && t != 2)
	{
		if (arr[t] > arr[t + 1])
		{
			buf = arr[t];
			arr[t] = arr[t + 1];
			arr[t + 1] = buf;
			t = 0;
		}
		else
			t++;
	}
	return (arr[1]);
}
