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

bool	is_sorted_stack(t_stack *stack, bool asc)
{
	uint64_t	i;
	uint64_t	index;
	uint64_t	next_index;

	if (stack == NULL)
		return (false);
	if (stack->size < 2)
		return (true);
	i = 0;
	while (i + 1 < stack->size)
	{
		index = stack->bottom + i;
		if (index >= stack->size)
			index -= stack->size;
		next_index = index + 1;
		if (next_index >= stack->size)
			next_index -= stack->size;
		if ((asc && stack->content[index] <= stack->content[next_index])
			|| (!asc && stack->content[index] >= stack->content[next_index]))
			return (false);
		i++;
	}
	return (true);
}

uint64_t	find_maximum_smaller(t_stack *stack, int n)
{
	int			*max;
	int			*max_smaller;
	uint64_t	i;
	uint64_t	index;

	if (stack == NULL || stack->len == 0)
		return (0);
	max = NULL;
	max_smaller = NULL;
	i = 0;
	while (i < stack->len)
	{
		index = stack->bottom + i;
		if (index >= stack->size)
			index -= stack->size;
		if (max == NULL || stack->content[index] > *max)
			max = stack->content + index;
		if (stack->content[index] < n
			&& (max_smaller == NULL || stack->content[index] > *max_smaller))
			max_smaller = stack->content + index;
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
	uint64_t	index;

	if (stack == NULL || stack->len == 0)
		return (0);
	min = NULL;
	min_bigger = NULL;
	i = 0;
	while (i < stack->len)
	{
		index = stack->bottom + i;
		if (index >= stack->size)
			index -= stack->size;
		if (min == NULL || stack->content[index] < *min)
			min = stack->content + index;
		if (stack->content[index] > n
			&& (min_bigger == NULL || stack->content[index] < *min_bigger))
			min_bigger = stack->content + index;
		i++;
	}
	if (min_bigger != NULL)
		return (min_bigger - stack->content);
	return (min - stack->content);
}

int	gap_to_top(t_stack *stack, uint64_t index, bool allow_bottom)
{
	uint64_t	v_index;
	uint64_t	v_top_index;

	if (stack == NULL || stack->len == 0)
		return (0);
	v_index = index;
	if (index < stack->bottom)
		v_index = stack->size + index;
	v_top_index = stack->top;
	if (stack->top <= stack->bottom)
		v_top_index = stack->size + stack->top;
	v_top_index--;
	if (v_top_index - v_index <= v_index - stack->bottom + 1 || !allow_bottom)
		return (v_top_index - v_index);
	return (stack->bottom - v_index - 1);
}
