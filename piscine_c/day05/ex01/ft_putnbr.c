/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcarolei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/31 12:54:36 by pcarolei          #+#    #+#             */
/*   Updated: 2019/02/04 13:01:45 by pcarolei         ###   ########.fr       */
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
	if (nb == 0)
	{
		ft_putchar('0');
		return ;
	}
	sign = -2 + (nb > 0) + (nb > 0) + (nb > 0) + (nb < 0);
	if (nb < 0)
		ft_putchar('-');
	rm = 0;
	while (nb != 0)
	{
		array_digits[i] = sign * (nb % 10);
		rm = 10 * rm + sign * (nb % 10);
		nb /= 10;
		i++;
	}
	i--;
	while (i >= 0)
		ft_putchar(array_digits[i--] + '0');
}
