/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do-operations.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhoussie <nhoussie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 07:55:13 by nhoussie          #+#    #+#             */
/*   Updated: 2026/01/14 08:13:12 by nhoussie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "operations.h"
#include "sort.h"

#define OPS_STR_LEN 3

static void		do_common_operations(t_stack *src_stack, t_stack *dest_stack,
		t_operations *ops);

static void		do_individual_operations(t_stack *stack,
		const char *stack_char, int ops);

void			do_operations(t_stack *src_stack, t_stack *dest_stack,
		t_operations *ops, bool asc)
{

	do_common_operations(src_stack, dest_stack, ops);
	if (asc)
	{
		do_individual_operations(src_stack, "b", ops->src_stack_ops);
		do_individual_operations(dest_stack, "a", ops->dest_stack_ops);
		do_push(src_stack, dest_stack, op_push, "pa");
	}
	else
	{
		do_individual_operations(src_stack, "a", ops->src_stack_ops);
		do_individual_operations(dest_stack, "b", ops->dest_stack_ops);
		do_push(src_stack, dest_stack, op_push, "pb");
	}
}

static void		do_common_operations(t_stack *src_stack, t_stack *dest_stack,
		t_operations *ops)
{
	while (ops->src_stack_ops > 0 && ops->dest_stack_ops > 0)
	{
		do_both_stack_op(src_stack, dest_stack, op_rotate, "rr");
		ops->src_stack_ops--;
		ops->dest_stack_ops--;
	}
	while (ops->src_stack_ops < 0 && ops->dest_stack_ops < 0)
	{
		do_both_stack_op(src_stack, dest_stack, op_reverse_rotate, "rrr");
		ops->src_stack_ops++;
		ops->dest_stack_ops++;
	}
}

static void		do_individual_operations(t_stack *stack,
		const char *stack_char, int ops)
{
	char	op_str[OPS_STR_LEN];

	ft_strlcpy(op_str, "r", OPS_STR_LEN);
	ft_strlcat(op_str, stack_char, OPS_STR_LEN);
	while (ops > 0)
	{
		do_stack_op(stack, op_rotate, op_str);
		ops--;
	}
	ft_strlcpy(op_str, "rr", OPS_STR_LEN);
	ft_strlcat(op_str, stack_char, OPS_STR_LEN);
	while (ops < 0)
	{
		do_stack_op(stack, op_reverse_rotate, op_str);
		ops++;
	}
}
