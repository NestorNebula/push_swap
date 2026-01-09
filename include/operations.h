/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhoussie <nhoussie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 11:52:23 by nhoussie          #+#    #+#             */
/*   Updated: 2026/01/09 12:03:46 by nhoussie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPERATIONS_H

#include "stack.h"

/**
 * Swaps the first 2 elements at the top of a stack.
 *
 * @param stack A pointer to a stack structure
 */
void	op_swap(t_stack *stack);

/**
 * Takes the first element of a stack and puts it at the top of another.
 * Does nothing if the source stack is empty.
 *
 * @param src_stack A pointer to the stack structure from which
 * to take the first element
 * @param dest_stack A pointer to the stack structure to which
 * the element will be pushed
 */
void	op_push(t_stack *src_stack, t_stack *dest_stack);

/**
 * Shifts up all elements of a stack by 1.
 * The first element becomes the last one.
 *
 * @param stack A pointer to a stack structure
 */
void	op_rotate(t_stack *stack);

/**
 * Shifts down all elements of a stack by 1.
 * The last element becomes the first one.
 *
 * @param stack A pointer to a stack structure
 */
void	op_reverse_rotate(t_stack *stack);

#endif // !OPERATIONS_H
