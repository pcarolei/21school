/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcarolei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/02 13:53:05 by pcarolei          #+#    #+#             */
/*   Updated: 2019/02/02 13:53:08 by pcarolei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_power(int nb, int power)
{
	int	i;
	int	res;

	res = 1;
	i = 1;
	if (power < 0 || nb == 0)
		return (0);
	if (nb == 1)
		return (1);
	while (i <= power)
	{
		res *= nb;
		i++;
	}
	return (res);
}
