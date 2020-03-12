/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcarolei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 16:28:20 by pcarolei          #+#    #+#             */
/*   Updated: 2020/03/12 19:12:50 by pcarolei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACKS_H
# define STACKS_H
# include "nodes.h"

typedef struct	s_stack
{
	t_node	*root;
	t_node	*top;
	int		count;
}				t_stack;

void			stack_init(t_stack *stack);
void			stack_init_with_inttab(t_stack *stack_a, int *tab, int size);
void			stack_push(t_stack *stack, int data);
int				stack_pop(t_stack *stack);
void			stack_swap(t_stack *stack);

void			stack_rotate(t_stack *stack);
void			stack_reverse_rotate(t_stack *stack);
char			*stack_to_str(t_stack *stack, int num);
int				stack_check_if_sorted(t_stack *stack);
int				count_ops_to_push_elem(t_stack *a, t_stack *b, int elem);

int				stack_get_shortest_path_to_elem(t_stack *s, int elem);
int				stack_b_pick_elem_to_push(t_stack *a, t_stack *b);
void			stack_a_shift_lesser(t_stack *a, int lesser);
void			stack_b_shift_elem(t_stack *b, int elem);
void			stack_b_push(t_stack *a, t_stack *b);

void			stack_rotate_two(t_stack *stack);

#endif
