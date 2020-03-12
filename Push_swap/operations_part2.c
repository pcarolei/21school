/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_part2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcarolei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 10:28:58 by pcarolei          #+#    #+#             */
/*   Updated: 2020/03/12 19:12:52 by pcarolei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"

void	ra(t_stack *a, int verbose)
{
	stack_rotate(a);
	if (verbose)
		ft_printf("ra\n");
}

void	rb(t_stack *b, int verbose)
{
	stack_rotate(b);
	if (verbose)
		ft_printf("rb\n");
}

void	rr(t_stack *a, t_stack *b, int verbose)
{
	stack_rotate(a);
	stack_rotate(b);
	if (verbose)
		ft_printf("rr\n");
}

void	rra(t_stack *a, int verbose)
{
	stack_reverse_rotate(a);
	if (verbose)
		ft_printf("rra\n");
}

void	rrb(t_stack *b, int verbose)
{
	stack_reverse_rotate(b);
	if (verbose)
		ft_printf("rrb\n");
}
