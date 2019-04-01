/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_takes_place.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcarolei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 17:23:02 by pcarolei          #+#    #+#             */
/*   Updated: 2019/02/07 17:23:04 by pcarolei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_takes_place2(int hour)
{
	int x;

	x = hour;
	if (x == 12)
	{
		printf("12.00 P.M. AND ");
		printf("%d.00 P.M.\n", (x + 1) % 12);
	}
	else if (x >= 13 && x <= 22)
	{
		printf("%d.00 P.M. AND ", x % 12);
		printf("%d.00 P.M.\n", (x + 1) % 12);
	}
	else if (x == 23)
	{
		printf("11.00 P.M. AND ");
		printf("12.00 A.M.\n");
	}
}

void	ft_takes_place(int hour)
{
	int x;

	x = hour;
	printf("THE FOLLOWING TAKES PLACE BETWEEN ");
	if (x == 0)
	{
		printf("12.00 A.M. AND ");
		printf("01.00 A.M.\n");
	}
	else if (x >= 1 && x < 11)
	{
		printf("%d.00 A.M. AND ", x % 12);
		printf("%d.00 A.M.\n", (x + 1) % 12);
	}
	else if (x == 11)
	{
		printf("11.00 A.M. AND ");
		printf("12.00 A.M.\n");
	}
	else
		ft_takes_place2(x);
}
