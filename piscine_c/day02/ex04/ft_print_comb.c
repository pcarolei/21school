/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcarolei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 19:47:19 by pcarolei          #+#    #+#             */
/*   Updated: 2019/01/31 00:42:30 by pcarolei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_putchar(char c);

void	ft_print_comb(void)
{
	char n1;
	char n2;
	char n3;

	n1 = '0';
	while (n1 <= '7' && (n2 = n1 + 1))
	{
		while (n2 <= '8' && (n3 = n2 + 1))
		{
			while (n3 <= '9')
			{
				ft_putchar(n1);
				ft_putchar(n2);
				ft_putchar(n3++);
				if (n1 != '7')
				{
					ft_putchar(',');
					ft_putchar(' ');
				}
			}
			n2++;
		}
		n1++;
	}
}
