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
