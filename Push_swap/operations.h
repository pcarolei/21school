/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcarolei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 16:28:20 by pcarolei          #+#    #+#             */
/*   Updated: 2020/02/26 03:41:45 by pcarolei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPERATIONS_H
# define OPERATIONS_H

# include "stacks.h"

void	sa(t_stack *a, int verbose);
void	sb(t_stack *b, int verbose);
void	ss(t_stack *a, t_stack *b, int verbose);
void	pa(t_stack *a, t_stack *b, int verbose);
void	pb(t_stack *a, t_stack *b, int verbose);
void	ra(t_stack *a, int verbose);
void	rb(t_stack *b, int verbose);
void	rr(t_stack *a, t_stack *b, int verbose);
void	rra(t_stack *a, int verbose);
void	rrb(t_stack *b, int verbose);
void	rrr(t_stack *a, t_stack *b, int verbose);
void	stack_shift_sort(t_stack *a, int max);
void	execute(t_stack *stack_a, t_stack *stack_b, char *instruction);

#endif
