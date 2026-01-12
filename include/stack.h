/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhoussie <nhoussie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 14:34:25 by nhoussie          #+#    #+#             */
/*   Updated: 2026/01/12 12:32:57 by nhoussie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H
#define STACK_H

#include <stdbool.h>
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
t_stack		*init_stack(size_t size);

/**
 * Pushes an integer at the top of a stack.
 * If the given stack is full, does nothing.
 *
 * @param stack A pointer to a stack structure
 * @param n The integer to push at the top of the stack
 */
void		push_stack(t_stack *stack, int n);

/*
 * Pops the element at the top of a stack.
 * If the given stack is empty, does nothing.
 *
 * @param stack A pointer to a stack structure
 * @return The integer popped from the stack.
 * If the given stack is empty, the return value is undefined
 */
int			pop_stack(t_stack *stack);

/**
 * Computes the number of integers currently stored in a stack.
 *
 * @param stack A pointer to a stack structure
 * @return The number of integers stored in the stack
 */
uint64_t	get_stack_len(t_stack *stack);

/**
 * Checks that a stack is sorted.
 *
 * @param stack A pointer to a stack structure
 * @param asc If set to true, the order checked will be ascending,
 * else descending.
 * @return True if the stack is sorted, false otherwise
 */
bool		is_sorted_stack(t_stack *stack, bool asc);

/**
 * Searches for the maximum number in a stack that is
 * smaller than a given number.
 * If every number in the stack is bigger than the given number,
 * searches for the maximum number.
 *
 * @param stack A pointer to a stack structure
 * @param n The number against which the stack's numbers will be compared
 * @return The index of the result number
 */
uint64_t	find_maximum_smaller(t_stack *stack, int n);

/**
 * Searches for the minimum number in a stack that is
 * bigger than a given number.
 * If every number in the stack is smaller than the given number,
 * searches for the minimum number.
 *
 * @param stack A pointer to a stack structure
 * @param n The number against which the stack's numbers will be compared
 * @return The index of the result number
 */
uint64_t	find_minimum_bigger(t_stack *stack, int n);

/**
 * Computes the number of elements in the stack separing
 * an element at a certain index from the top of the stack.
 *
 * @param stack A pointer to a stack structure
 * @param index The index of an element in the stack
 * @param allow_bottom If true, the function will return a negative value
 * corresponding to the gap to the top if by going down instead of up.
 * A negative value will be returned only if the gap is closest by going down
 * @return The gap to the top of the stack for the given index
 */
int			gap_to_top(t_stack *stack, uint64_t index, bool allow_bottom);

/**
 * Frees a stack structure.
 *
 * @param stack A pointer to a stack structure
 */
void		free_stack(t_stack *stack);

#endif // !STACK_H
