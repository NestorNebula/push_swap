/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort-special-cases.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhoussie <nhoussie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 08:25:41 by nhoussie          #+#    #+#             */
/*   Updated: 2026/01/14 08:34:58 by nhoussie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"
#include "sort.h"

static void			handle_three_cases(t_stack *stack,
		uint64_t b, uint64_t m, uint64_t t);

void			sort_two(t_stack *stack)
{
	uint64_t	top;

	if (stack == NULL || stack->len != 2)
		return ;
	top = stack->top - 1;
	if (stack->top == 0)
		top = stack->size - 1;
	if (stack->content[stack->bottom] < stack->content[top])
		do_stack_op(stack, op_swap, "sa");
}

void	sort_three(t_stack *stack)
{
	uint64_t	middle;
	uint64_t	top;

	if (stack == NULL || stack->len != 3)
		return ;
	middle = stack->bottom + 1;
	if (middle == stack->size)
		middle = 0;
	top = stack->top - 1;
	if (stack->top == 0)
		top = stack->size - 1;
	handle_three_cases(stack, stack->bottom, middle, top);
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
