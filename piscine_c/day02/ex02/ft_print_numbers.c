/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_numbers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcarolei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/31 12:48:36 by pcarolei          #+#    #+#             */
/*   Updated: 2019/01/31 12:48:47 by pcarolei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_putchar(char c);

void	ft_print_alphabet(void)
{
	char c;

	c = '0';
	while (c <= '9')
	{
		ft_putchar(c);
		c++;
	}
	ft_putchar('\n');
	return ;
}
