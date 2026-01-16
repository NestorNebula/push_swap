/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort-operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhoussie <nhoussie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 12:29:20 by nhoussie          #+#    #+#             */
/*   Updated: 2026/01/14 12:29:22 by nhoussie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort.h"
#include <stdint.h>

static int	abs(int n);

static int	get_ops_sum(t_operations *ops);

static int	gap_to_top_force_bottom(t_stack *stack, uint64_t index);

t_operations	find_minimum_operations(uint64_t index,
		t_stack *src_stack, t_stack *dest_stack, bool asc)
{
	t_operations	min_ops;
	t_operations	ops;
	uint64_t		target;

	if (asc)
		target = find_minimum_bigger(dest_stack, src_stack->content[index]);
	else
		target = find_maximum_smaller(dest_stack, src_stack->content[index]);
	ops.src_stack_ops = gap_to_top(src_stack, index, false);
	ops.dest_stack_ops = gap_to_top(dest_stack, target, false);
	ops.sum = get_ops_sum(&ops);
	min_ops = ops;
	ops.src_stack_ops = gap_to_top_force_bottom(src_stack, index);
	ops.dest_stack_ops = gap_to_top_force_bottom(dest_stack, target);
	ops.sum = get_ops_sum(&ops);
	if (ops.sum < min_ops.sum)
		min_ops = ops;
	ops.src_stack_ops = gap_to_top(src_stack, index, true);
	ops.dest_stack_ops = gap_to_top(dest_stack, target, true);
	ops.sum = get_ops_sum(&ops);
	if (ops.sum < min_ops.sum)
		min_ops = ops;
	return (min_ops);
}

t_operations	find_best_operations(t_stack *src_stack,
		t_stack *dest_stack, bool asc)
{
	t_operations	best_ops;
	t_operations	ops;
	uint64_t		i;
	uint64_t		index;

	i = 0;
	best_ops.sum = src_stack->size + dest_stack->size;
	while (i < src_stack->len)
	{
		index = src_stack->bottom + i;
		if (index >= src_stack->size)
			index -= src_stack->size;
		ops = find_minimum_operations(index, src_stack, dest_stack, asc);
		if (ops.sum < best_ops.sum)
			best_ops = ops;
		i++;
	}
	return (best_ops);
}

static int	abs(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

static int	get_ops_sum(t_operations *ops)
{
	if (ops->src_stack_ops == 0)
		return (abs(ops->dest_stack_ops));
	if (ops->dest_stack_ops == 0)
		return (abs(ops->src_stack_ops));
	if (ops->src_stack_ops > 0 && ops->dest_stack_ops > 0)
	{
		if (ops->src_stack_ops > ops->dest_stack_ops)
			return (ops->src_stack_ops);
		return (ops->dest_stack_ops);
	}
	if (ops->src_stack_ops < 0 && ops->dest_stack_ops < 0)
	{
		if (ops->src_stack_ops < ops->dest_stack_ops)
			return (-(ops->src_stack_ops));
		return (-(ops->dest_stack_ops));
	}
	return (abs(ops->src_stack_ops) + abs(ops->dest_stack_ops));
}

static int	gap_to_top_force_bottom(t_stack *stack, uint64_t index)
{
	uint64_t	v_index;

	if (stack == NULL || stack->len <= 1)
		return (0);
	v_index = index;
	if (v_index < stack->bottom)
		v_index += stack->size;
	return (stack->bottom - v_index - 1);
}
