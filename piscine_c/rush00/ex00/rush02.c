/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush02.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kturnips <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/03 17:59:47 by kturnips          #+#    #+#             */
/*   Updated: 2019/02/03 18:01:42 by kturnips         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	rush(int x, int y)
{
	int cx;
	int cy;

	cy = 0;
	while ((cy++ < y) && (x > 0))
	{
		cx = 0;
		while (cx++ < x)
		{
			if (((cx == 1) && (cy == 1)) || ((cx == x) && (cy == 1)))
				ft_putchar('A');
			else if (((cx == 1) && (cy == y)) || ((cx == x) && (cy == y)))
				ft_putchar('C');
			else
			{
				if ((cy == 1) || (cy == y))
					ft_putchar('B');
				if ((cx == 1) || (cx == x))
					ft_putchar('B');
				if ((cx != 1) && (cx != x) && (cy != 1) && (cy != y))
					ft_putchar(' ');
			}
		}
		ft_putchar('\n');
	}
}
