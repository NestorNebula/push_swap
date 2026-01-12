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

/**
 * Sorts first stack using second stack and allowed operations.
 *
 * @param stack_a The stack to be sorted
 * @param stack_b An empty stack that can be used during the sorting process
 * If this stack isn't empty, the result of calling the function is undefined
 */
void	sort(t_stack *stack_a, t_stack *stack_b);

#endif // !SORT_H
