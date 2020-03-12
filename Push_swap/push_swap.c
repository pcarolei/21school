/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcarolei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 10:28:58 by pcarolei          #+#    #+#             */
/*   Updated: 2020/03/03 03:33:48 by pcarolei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		free_resources(t_stack *a, int *tab)
{
	node_free_list(a->top);
	free(tab);
	return (0);
}

void	sort_triple(t_stack *s)
{
	int	fst;
	int	snd;
	int	trd;

	fst = s->top->data;
	snd = s->top->next->data;
	trd = s->root->data;
	if ((fst > snd) && (snd < trd) && (fst < trd))
		sa(s, 1);
	else if ((fst > snd) && (snd > trd))
	{
		sa(s, 1);
		rra(s, 1);
	}
	else if ((fst > snd) && (snd < trd))
		ra(s, 1);
	else if ((fst < snd) && (snd > trd) && (fst < trd))
	{
		sa(s, 1);
		ra(s, 1);
	}
	else
		rra(s, 1);
}

void	sort_five(t_stack *a, t_stack *b)
{
	int	min;
	int max;

	min = node_find_min(a->top);
	max = node_find_max(a->top);
	while (a->count > 3)
	{
		if ((a->top->data != min) && (a->top->data != max))
			ra(a, 1);
		else
			pb(a, b, 1);
	}
	if (!stack_check_if_sorted(a))
		sort_triple(a);
	if (b->top->data > b->top->next->data)
		sb(b, 1);
	pa(a, b, 1);
	pa(a, b, 1);
	ra(a, 1);
}

void	sort(t_stack *a, t_stack *b)
{
	int	min;
	int	med;
	int	max;
	int	end;

	min = node_find_min(a->top);
	max = node_find_max(a->top);
	while (a->count > 3)
	{
		end = a->root->data;
		med = node_find_med(a->top, a->count);
		while (a->top->data != end)
		{
			if ((a->top->data != max) && (a->top->data != min) &&
												(a->top->data <= med))
				pb(a, b, 1);
			else
				ra(a, 1);
		}
	}
	if (!stack_check_if_sorted(a))
		sort_triple(a);
	while (b->count > 0)
		stack_b_push(a, b);
	stack_shift_sort(a, max);
}

int		main(int ac, char **av)
{
	int		*tab;
	t_stack	stack_a;
	t_stack	stack_b;

	tab = read_integer_list(ac, av, 0);
	stack_init(&stack_a);
	stack_init(&stack_b);
	stack_init_with_inttab(&stack_a, tab, ac - 1);
	if (stack_check_if_sorted(&stack_a))
		return (free_resources(&stack_a, tab));
	if (stack_a.count == 3)
		sort_triple(&stack_a);
	else if (stack_a.count == 5)
		sort_five(&stack_a, &stack_b);
	else if (!stack_check_if_sorted(&stack_a))
		sort(&stack_a, &stack_b);
	return (free_resources(&stack_a, tab));
}
