/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_part1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcarolei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 19:34:20 by pcarolei          #+#    #+#             */
/*   Updated: 2020/03/12 19:12:51 by pcarolei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"

void	sa(t_stack *a, int verbose)
{
	stack_swap(a);
	if (verbose)
		ft_printf("sa\n");
}

void	sb(t_stack *b, int verbose)
{
	stack_swap(b);
	if (verbose)
		ft_printf("sb\n");
}

void	ss(t_stack *a, t_stack *b, int verbose)
{
	stack_swap(a);
	stack_swap(b);
	if (verbose)
		ft_printf("ss\n");
}

void	pa(t_stack *a, t_stack *b, int verbose)
{
	int	data;

	data = stack_pop(b);
	stack_push(a, data);
	if (verbose)
		ft_printf("pa\n");
}

void	pb(t_stack *a, t_stack *b, int verbose)
{
	int	data;

	data = stack_pop(a);
	stack_push(b, data);
	if (verbose)
		ft_printf("pb\n");
}
