/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhoussie <nhoussie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 12:12:01 by nhoussie          #+#    #+#             */
/*   Updated: 2026/01/14 08:24:27 by nhoussie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SORT_H
# define SORT_H

# include "stack.h"

typedef struct s_operations {
	int	src_stack_ops;
	int	dest_stack_ops;
	int	sum;
}				t_operations;

/**
 * Sorts first stack using second stack and allowed operations.
 *
 * @param stack_a The stack to be sorted
 * @param stack_b An empty stack that can be used during the sorting process
 * If this stack isn't empty, the result of calling the function is undefined
 */
void			sort(t_stack *stack_a, t_stack *stack_b);

/**
 * Sorts a stack with exactly two elements inside of it.
 *
 * @param A stack of size two.
 * Every stack with another size will remain unsorted
 */
void			sort_two(t_stack *stack);

/**
 * Sorts a stack with exactly three elements inside of it.
 *
 * @param A stack of size three.
 * Every stack with another size will remain unsorted
 */
void			sort_three(t_stack *stack);

/**
 * Finds the minimum number of operations to move an element
 * from a source stack to a destination stack.
 *
 * @param index The index of the element to move in the source stack
 * @param src_stack The source stack
 * @param dest_stack The destination stack
 * @bool asc True if the destination stack is sorted in ascending order,
 * false otherwise
 * @return An operations structure
 */
t_operations	find_minimum_operations(unsigned int index,
					t_stack *src_stack, t_stack *dest_stack, bool asc);

/**
 * Finds the element with the smallest number of operations to be moved
 * from a source stack to a destination stack.
 *
 * @param src_stack The source stack
 * @param dest_stack The destination stack
 * @param asc True if the destination stack is sorted in ascending order,
 * false otherwise
 * @return An operations structure
 */
t_operations	find_best_operations(t_stack *src_stack,
					t_stack *dest_stack, bool asc);

/**
 * Executes the given operations on a source stack and a destination stack.
 *
 * @param src_stack The source stack
 * @param dest_stack The destination stack
 * @param ops A pointer to an operations structure
 * @param asc True if the destination stack is sorted in ascending order,
 * false otherwise
 */
void			do_operations(t_stack *src_stack, t_stack *dest_stack,
					t_operations *ops, bool asc);

/**
 * Calls an operation function on a stack structure,
 * printing the executed operation.
 *
 * @param stack The stack on which the operation will be executed
 * @param op A pointer to an operation function
 * @param op_str The string that will be printed after operation execution
 */
void			do_stack_op(t_stack *stack,
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
void			do_both_stack_op(t_stack *stack_a, t_stack *stack_b,
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
void			do_push(t_stack *src_stack, t_stack *dest_stack,
					void (*push)(t_stack *, t_stack *), const char *op_str);

#endif // !SORT_H
