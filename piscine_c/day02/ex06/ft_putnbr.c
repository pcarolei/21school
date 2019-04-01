/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcarolei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/31 12:54:36 by pcarolei          #+#    #+#             */
/*   Updated: 2019/01/31 12:54:45 by pcarolei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_putchar(char c);

void	ft_putnbr(int nb)
{
	int rm;
	int sign;
	int array_digits[10];
	int i;

	i = 0;
	sign = (nb > 0) ? 1 : -1;
	rm = 0;
	while (nb != 0)
	{
		array_digits[i] = sign * (nb % 10);
		rm = 10 * rm + sign * nb % 10;
		nb = nb / 10;
		i++;
	}
	if (sign == -1)
		ft_putchar('-');
	i--;
	while (i >= 0)
	{
		ft_putchar(array_digits[i] + '0');
		i--;
	}
}
