/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcarolei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/02 16:15:34 by pcarolei          #+#    #+#             */
/*   Updated: 2019/02/02 16:15:37 by pcarolei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_prime(int nb)
{
	int dvd;

	dvd = 6;
	if (nb == 2 || nb == 3 || nb == 5)
		return (1);
	if (nb <= 0 || nb == 1)
		return (0);
	if (nb % 2 == 0 || nb % 3 == 0)
		return (0);
	while (dvd * dvd < nb)
	{
		if (nb % (dvd - 1) == 0 || nb % (dvd + 1) == 0)
			return (0);
		dvd = dvd + 6;
	}
	return (1);
}

int	ft_find_next_prime(int nb)
{
	if (nb == 0)
		return (2);
	if (nb < 0)
		return (2);
	if (nb == 1)
		return (2);
	if (ft_is_prime(nb) == 1)
		return (nb);
	while (ft_is_prime(nb) == 0)
		nb++;
	return (nb);
}
