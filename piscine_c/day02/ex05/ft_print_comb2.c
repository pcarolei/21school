/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcarolei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/31 12:52:07 by pcarolei          #+#    #+#             */
/*   Updated: 2019/01/31 12:52:25 by pcarolei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_putchar(char c);

void	ft_print_comb2(void)
{
	int f;
	int s;

	f = 0;
	s = 0;
	while (f <= 98)
	{
		s = f + 1;
		while (s <= 99)
		{
			ft_putchar(f / 10 + '0');
			ft_putchar(f % 10 + '0');
			ft_putchar(' ');
			ft_putchar(s / 10 + '0');
			ft_putchar(s % 10 + '0');
			if (f < 98)
			{
				ft_putchar(',');
				ft_putchar(' ');
			}
			s++;
		}
		f++;
	}
}
