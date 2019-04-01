/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcarolei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/02 14:04:05 by pcarolei          #+#    #+#             */
/*   Updated: 2019/02/02 14:04:10 by pcarolei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_recursive_power(int nb, int power)
{
	int res;

	res = 1;
	if (power < 0 || nb == 0)
		return (0);
	if (nb == 1 || power == 0)
		return (1);
	res = nb * ft_recursive_power(nb, power - 1);
}
