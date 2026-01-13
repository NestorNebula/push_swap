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


static t_operations	find_minimum_operations(uint64_t index,
		t_stack *src_stack, t_stack *dest_stack, bool asc);

static t_operations	find_best_operations(t_stack *src_stack,
		t_stack *dest_stack, bool asc);

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

static t_operations	find_minimum_operations(uint64_t index,
		t_stack *src_stack, t_stack *dest_stack, bool asc)
{
	t_operations	min_ops;
	uint64_t		target;

	min_ops.src_stack_ops = gap_to_top(src_stack, index, true);
	if (asc)
		target = find_minimum_bigger(dest_stack, src_stack->content[index]);
	else
		target = find_maximum_smaller(dest_stack, src_stack->content[index]);
	min_ops.dest_stack_ops = gap_to_top(dest_stack, target, true);
	if ((min_ops.src_stack_ops < 0 && min_ops.dest_stack_ops < 0)
		|| (min_ops.src_stack_ops > 0 && min_ops.dest_stack_ops > 0))
		min_ops.sum = min_ops.src_stack_ops - min_ops.dest_stack_ops;
	else if (min_ops.src_stack_ops < 0)
		min_ops.sum = min_ops.src_stack_ops - min_ops.dest_stack_ops;
	else
		min_ops.sum = min_ops.dest_stack_ops - min_ops.src_stack_ops;
	if (min_ops.sum < 0)
		min_ops.sum = -min_ops.sum;
	min_ops.sum++;
	return (min_ops);
}

static t_operations	find_best_operations(t_stack *src_stack,
		t_stack *dest_stack, bool asc)
{
	t_operations	best_ops;
	t_operations	ops;
	uint64_t		i;

	i = src_stack->bottom;
	if (src_stack->top == 0)
		src_stack->top = src_stack->size;
	best_ops.sum = src_stack->size + dest_stack->size;
	while (i != src_stack->top)
	{
		if (i == src_stack->size)
			i = 0;
		ops = find_minimum_operations(i, src_stack, dest_stack, asc);
		if (ops.sum < best_ops.sum)
			best_ops = ops;
		i++;
	}
	return (best_ops);
}
