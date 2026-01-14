/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhoussie <nhoussie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 11:52:56 by nhoussie          #+#    #+#             */
/*   Updated: 2026/01/14 10:27:51 by nhoussie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"
#include "sort.h"
#include "stack.h"
#include <limits.h>

static void	set_min_to_top(t_stack *stack);

void	sort(t_stack *stack_a, t_stack *stack_b)
{
	t_operations	ops;

	// If sorted or size a == 1, do nothing
	if (stack_a == NULL || stack_b == NULL || is_sorted_stack(stack_a, true))
		return ;
	if (stack_a->len <= 1)
		return ;
	// If size equals to 2, swap numbers if needs be
	if (stack_a->len == 2)
		sort_two(stack_a);
	else
	{
		// Push numbers to stack b until size a == 3
		while (stack_a->len > 3)
		{
			ops = find_best_operations(stack_a, stack_b, false);
			do_operations(stack_a, stack_b, &ops, false);
		}
		// Sort stack a
		sort_three(stack_a);
		// Push numbers to stack a until size b == 0 while (stack_len > 0)
		while (stack_b->len > 0)
		{
			ops = find_best_operations(stack_b, stack_a, true);
			do_operations(stack_b, stack_a, &ops, true);
		}
		// Rotate stack a until sorted
		set_min_to_top(stack_a);
	};
}

static void	set_min_to_top(t_stack *stack)
{
	int	gap;

	gap = gap_to_top(stack, find_minimum_bigger(stack, INT_MAX), true);
	while (gap > 0)
	{
		do_stack_op(stack, op_rotate, "ra");
		gap--;
	}
	while (gap < 0)
	{
		do_stack_op(stack, op_reverse_rotate, "rra");
		gap++;
	}
}

// If sorted or size a == 1, do nothing
// If size equals to 2, swap numbers if needs be
// Push numbers to stack b until size a == 3
// Sort stack a
// Push numbers to stack a until size b == 0
// Rotate stack a until sorted
