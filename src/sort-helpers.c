/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort-helpers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhoussie <nhoussie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 11:52:52 by nhoussie          #+#    #+#             */
/*   Updated: 2026/01/13 11:53:15 by nhoussie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "sort.h"

void	do_stack_op(t_stack *stack,
		void (*op)(t_stack *), const char *op_str)
{
	op(stack);
	ft_printf("%s\n", op_str);
}

void	do_both_stack_op(t_stack *stack_a, t_stack *stack_b,
		void (*op)(t_stack *), const char *op_str)
{
	op(stack_a);
	op(stack_b);
	ft_printf("%s\n", op_str);
}

void	do_push(t_stack *src_stack, t_stack *dest_stack,
		void (*push)(t_stack *, t_stack *), const char *op_str)
{
	push(src_stack, dest_stack);
	ft_printf("%s\n", op_str);
}
