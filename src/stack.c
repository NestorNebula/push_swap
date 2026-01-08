/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhoussie <nhoussie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 08:51:02 by nhoussie          #+#    #+#             */
/*   Updated: 2026/01/08 08:51:04 by nhoussie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"
#include <stdlib.h>

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

void	free_stack(t_stack *stack)
{
	free(stack->content);
	free(stack);
}
