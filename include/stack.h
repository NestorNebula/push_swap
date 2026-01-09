/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhoussie <nhoussie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 14:34:25 by nhoussie          #+#    #+#             */
/*   Updated: 2026/01/09 09:23:12 by nhoussie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H

#include <stddef.h>
#include <stdint.h>

typedef struct s_stack {
	int			*content;
	size_t		size;
	uint64_t	top;
	uint64_t	bottom;
}				t_stack;

/**
 * Inits a stack structure and returns a pointer to it.
 *
 * @param size The size of the stack's content
 * @return A pointer to a stack structure. NULL if an error occurs
 */
t_stack	*init_stack(size_t size);

/**
 * Pushes n at the top of stack.
 *
 * @param stack A pointer to a stack structure
 * @param n The integer to push at the top of the stack
 */
void	push_stack(t_stack *stack, int n);

/*
 * Pops the element at the top of stack.
 *
 * @param A pointer to a non-empty stack structure
 * @return The integer popped from the stack.
 * If the given stack is empty, the return value is undefined.
 */
int		pop_stack(t_stack *stack);

/**
 * Frees a stack structure.
 *
 * @param stack A pointer to a stack structure
 */
void	free_stack(t_stack *stack);

#endif // !STACK_H

