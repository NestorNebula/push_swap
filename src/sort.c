/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhoussie <nhoussie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 11:52:56 by nhoussie          #+#    #+#             */
/*   Updated: 2026/01/13 15:39:31 by nhoussie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"
#include <stdint.h>
#include "sort.h"

static void			handle_three_cases(t_stack *stack,
		uint64_t b, uint64_t m, uint64_t t);

static void			sort_three(t_stack *stack);



void	sort(t_stack *stack_a, t_stack *stack_b)
{
	// If sorted or size a == 1, do nothing
	// If size equals to 2, swap numbers if needs be
	// Push numbers to stack b until size a == 3
	// Sort stack a
	// Push numbers to stack a until size b == 0
	// Rotate stack a until sorted
}

static void			handle_three_cases(t_stack *stack,
		uint64_t b, uint64_t m, uint64_t t)
{
	const int *c = stack->content;
	
	if (c[b] < c[m] && c[m] > c[t] && c[b] < c[t])
		do_stack_op(stack, op_reverse_rotate, "rra");
	else if (c[b] > c[m] && c[m] < c[t] && c[b] < c[t])
		do_stack_op(stack, op_rotate, "ra");
	else if (c[b] < c[m] && c[m] > c[t] && c[b] > c[t])
	{
		do_stack_op(stack, op_swap, "sa");
		do_stack_op(stack, op_rotate, "ra");
	}
	else if (c[b] > c[m] && c[m] < c[t] && c[b] > c[t])
		do_stack_op(stack, op_swap, "sa");
	else if (c[b] < c[m] && c[m] < c[t])
	{
		do_stack_op(stack, op_swap, "sa");
		do_stack_op(stack, op_reverse_rotate, "rra");
	}
}

static void			sort_three(t_stack *stack)
{
	uint64_t	middle;
	uint64_t	top;

	middle = stack->bottom + 1;
	if (middle == stack->size)
		middle = 0;
	top = stack->top - 1;
	if (stack->top == 0)
		middle = stack->size - 1;
	handle_three_cases(stack, stack->bottom, middle, top);
}
