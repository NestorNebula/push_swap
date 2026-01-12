/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack-helpers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhoussie <nhoussie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 12:26:48 by nhoussie          #+#    #+#             */
/*   Updated: 2026/01/12 13:01:28 by nhoussie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

uint64_t	get_stack_len(t_stack *stack)
{
	uint64_t	top;
	
	if (stack == NULL)
		return (0);
	top = stack->top;
	if (top < stack->bottom)
		top += stack->size;
	return (top - stack->bottom);
}

bool		is_sorted_stack(t_stack *stack, bool asc)
{
	uint64_t	index;
	uint64_t	next_index;

	if (stack == NULL)
		return (false);
	if (stack->size < 2)
		return (true);
	index = stack->bottom;
	while (index + 1 != stack->top
		&& (index != stack->size - 1 || stack->top != 0))
	{
		next_index = index + 1;
		if (stack->bottom == stack->size - 1)
			next_index = 0;
		if ((asc && stack->content[index] <= stack->content[next_index])
			|| (!asc && stack->content[index] >= stack->content[next_index]))
			return (false);
		index++;
		if (index == stack->size)
			index = 0;
	}
	return (true);
}

uint64_t	find_maximum_smaller(t_stack *stack, int n)
{
	int			*max;
	int			*max_smaller;
	uint64_t	i;

	if (stack == NULL || get_stack_len(stack) == 0)
		return (0);
	if (stack->top == 0)
		stack->top = stack->size;
	i = stack->bottom;
	max = stack->content + i;
	max_smaller = NULL;
	while (i != stack->top)
	{
		if (i == stack->size)
			i = 0;
		if (stack->content[i] > *max)
			max = stack->content + i;
		if (stack->content[i] < n
			&& (max_smaller == NULL || stack->content[i] > *max_smaller))
			max_smaller = stack->content + i;
		i++;
	}
	if (max_smaller != NULL)
		return (max_smaller - stack->content);
	return (max - stack->content);
}

uint64_t	find_minimum_bigger(t_stack *stack, int n)
{
	int			*min;
	int			*min_bigger;
	uint64_t	i;

	if (stack == NULL || get_stack_len(stack) == 0)
		return (0);
	if (stack->top == 0)
		stack->top = stack->size;
	i = stack->bottom;
	min = stack->content + i;
	min_bigger = NULL;
	while (i != stack->top)
	{
		if (i == stack->size)
			i = 0;
		if (stack->content[i] < *min)
			min = stack->content + i;
		if (stack->content[i] > n
			&& (min_bigger == NULL || stack->content[i] < *min_bigger))
			min_bigger = stack->content + i;
		i++;
	}
	if (min_bigger != NULL)
		return (min_bigger - stack->content);
	return (min - stack->content);
}

int			gap_to_top(t_stack *stack, uint64_t index, bool allow_bottom)
{
	uint64_t	v_index;
	uint64_t	v_top_index;

	if (stack == NULL || get_stack_len(stack) == 0)
		return (0);
	v_index = index;
	if (index < stack->bottom)
		v_index = stack->size + index;
	v_top_index = stack->top;
	if (stack->top < stack->bottom)
		v_top_index = stack->size + stack->top;
	v_top_index--;
	if (v_top_index - v_index < v_index - stack->bottom || !allow_bottom)
		return (v_top_index - v_index);
	return (stack->bottom - v_index - 1);
}
