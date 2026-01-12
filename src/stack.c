/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhoussie <nhoussie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 08:51:02 by nhoussie          #+#    #+#             */
/*   Updated: 2026/01/12 12:27:20 by nhoussie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "stack.h"

t_stack	*init_stack(size_t size)
{
	t_stack	*stack;

	stack = malloc(sizeof(t_stack));
	if (stack == NULL)
		return (NULL);
	stack->content = malloc(sizeof(int) * size);
	if (stack->content == NULL)
	{
		free(stack);
		return (NULL);
	}
	stack->size = size;
	stack->top = 0;
	stack->bottom = 0;
	return (stack);
}

void		push_stack(t_stack *stack, int n)
{
	if (stack == NULL || get_stack_len(stack) == stack->size)
		return ;
	if (stack->top == stack->size)
		stack->top = 0;
	stack->content[stack->top++] = n;
}

int			pop_stack(t_stack *stack)
{
	if (stack == NULL || get_stack_len(stack) == 0)
		return (0);
	if (stack->top == 0)
		stack->top = stack->size;
	return (stack->content[--stack->top]);
}

void	free_stack(t_stack *stack)
{
	free(stack->content);
	free(stack);
}
