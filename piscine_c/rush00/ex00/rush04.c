/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush04.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kturnips <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/03 10:31:58 by kturnips          #+#    #+#             */
/*   Updated: 2019/02/03 19:41:43 by kturnips         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	rush(int x, int y)
{
	int i;
	int j;

	j = 0;
	while ((j++ < y) && (x > 0))
	{
		i = 0;
		while (i++ < x)
		{
			if ((i == 1 && j == 1) || (x == i && j != 1 && j == y && i != 1))
				ft_putchar('A');
			else if ((i == 1 && j == y) || (i == x && j == 1 && i != 1))
				ft_putchar('C');
			else
			{
				if ((j == 1) || (j == y))
					ft_putchar('B');
				if ((i == 1) || (i == x))
					ft_putchar('B');
				if ((i != 1) && (i != x) && (j != 1) && (j != y))
					ft_putchar(' ');
			}
		}
		ft_putchar('\n');
	}
}
