/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhoussie <nhoussie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 08:27:12 by nhoussie          #+#    #+#             */
/*   Updated: 2026/01/12 08:38:07 by nhoussie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"
#include "stack.h"

void	op_swap(t_stack *stack)
{
	int	*swap[2];
	int	tmp;

	if (stack == NULL || stack->len < 2)
		return ;
	if (stack->top > 0)
		swap[0] = stack->content + stack->top - 1;
	else
	 swap[0] = stack->content + stack->size - 1;
	if (swap[0] > stack->content)
		swap[1] = swap[0] - 1;
	else
		swap[1] = stack->content + stack->size - 1;
	tmp = *swap[0];
	*swap[0] = *swap[1];
	*swap[1] = tmp;
}

void	op_push(t_stack *src_stack, t_stack *dest_stack)
{
	int	n;

	if (src_stack == NULL || dest_stack == NULL || src_stack->len == 0)
		return ;
	n = pop_stack(src_stack);
	push_stack(dest_stack, n);
}

void	op_rotate(t_stack *stack)
{
	if (stack == NULL || stack->len < 2)
		return ;
	if (stack->top == 0)
		stack->top = stack->size;
	if (stack->len < stack->size)
	{
		if (stack->bottom == 0)
			stack->bottom = stack->size;
		stack->content[--stack->bottom] = stack->content[--stack->top];
	}
	else
		stack->bottom = --stack->top;
}

void	op_reverse_rotate(t_stack *stack)
{
	if (stack == NULL || stack->len < 2)
		return ;
	if (stack->len < stack->size)
	{
		if (stack->top == stack->size)
			stack->top = 0;
		stack->content[stack->top++] = stack->content[stack->bottom++];
	}
	else {
		stack->top = ++stack->bottom;
	}
	if (stack->bottom == stack->size)
		stack->bottom = 0;
}
