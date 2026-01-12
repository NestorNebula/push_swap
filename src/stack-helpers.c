/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack-helpers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhoussie <nhoussie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 12:26:48 by nhoussie          #+#    #+#             */
/*   Updated: 2026/01/12 12:27:14 by nhoussie         ###   ########.fr       */
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
