/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhoussie <nhoussie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 12:12:01 by nhoussie          #+#    #+#             */
/*   Updated: 2026/01/12 12:25:19 by nhoussie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SORT_H
#define SORT_H

#include "stack.h"

typedef struct s_operations {
	int	src_stack_ops;
	int dest_stack_ops;
	int sum;
}				t_operations;

/**
 * Sorts first stack using second stack and allowed operations.
 *
 * @param stack_a The stack to be sorted
 * @param stack_b An empty stack that can be used during the sorting process
 * If this stack isn't empty, the result of calling the function is undefined
 */
void	sort(t_stack *stack_a, t_stack *stack_b);

/**
 * Calls an operation function on a stack structure,
 * printing the executed operation.
 *
 * @param stack The stack on which the operation will be executed
 * @param op A pointer to an operation function
 * @param op_str The string that will be printed after operation execution
 */
void	do_stack_op(t_stack *stack,
		void (*op)(t_stack *), const char *op_str);

/**
 * Calls an operation function on two stack structures,
 * printing the executed operation.
 *
 * @param stack_a The first stack on which the operation will be executed
 * @param stack_b The second stack on which the operation will be executed
 * @param op A pointer to an operation function
 * @param op_str The string that will be printed after operation executions
 */
void	do_both_stack_op(t_stack *stack_a, t_stack *stack_b,
		void (*op)(t_stack *), const char *op_str);

/**
 * Calls the push operation with a source and a destination stack,
 * printing the executed operation.
 *
 * @param src_stack The stack that will be used as source stack
 * @param dest_stack The stack that will be used as destination stack
 * @param push A pointer to a push operation function
 * @param op_str The string that will be printed after operation execution
 */
void	do_push(t_stack *src_stack, t_stack *dest_stack,
		void (*push)(t_stack *, t_stack *), const char *op_str);

#endif // !SORT_H
