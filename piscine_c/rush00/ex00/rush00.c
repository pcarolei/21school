/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kturnips <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/03 10:31:58 by kturnips          #+#    #+#             */
/*   Updated: 2019/02/03 17:28:26 by kturnips         ###   ########.fr       */
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
				ft_putchar('o');
			else if (((cx == 1) && (cy == y)) || ((cx == x) && (cy == y)))
				ft_putchar('o');
			else
			{
				if ((cy == 1) || (cy == y))
					ft_putchar('-');
				if ((cx == 1) || (cx == x))
					ft_putchar('|');
				if ((cx != 1) && (cx != x) && (cy != 1) && (cy != y))
					ft_putchar(' ');
			}
		}
		ft_putchar('\n');
	}
}
