/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhoussie <nhoussie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/17 08:02:20 by nhoussie          #+#    #+#             */
/*   Updated: 2026/01/17 09:11:46 by nhoussie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "get_next_line.h"
#include "libft.h"
#include "operations.h"
#include "parse.h"
#include "sort.h"
#include "stack.h"
#include "unistd.h"

#define ERR "Error\n"

static void	init_prog(int argc, char *argv[],
				t_stack **stack_a, t_stack **stack_b);

static void	read_commands(t_stack *stack_a, t_stack *stack_b);

static bool	exec_command(t_stack *stack_a, t_stack *stack_b,
				const char *command);

static bool command_switch(t_stack *stack_a, t_stack *stack_b,
				const char *command, size_t command_len);

int main(int argc, char *argv[])
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (argc < 2)
		return (0);
	init_prog(argc, argv, &stack_a, &stack_b);
	read_commands(stack_a, stack_b);
	if (stack_a->len == stack_a->size && is_sorted_stack(stack_a, true))
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	free_stack(stack_a);
	free_stack(stack_b);
	return (0);
}

static void	init_prog(int argc, char *argv[],
		t_stack **stack_a, t_stack **stack_b)
{
	size_t	size;

	size = parse_args((const char **) argv + 1, argc - 1, NULL);
	if (size == 0)
	{
		write(STDERR_FILENO, ERR, ft_strlen(ERR));
		exit(EXIT_FAILURE);
	}
	*stack_a = init_stack(size);
	*stack_b = init_stack(size);
	if (*stack_a == NULL || *stack_b == NULL
		|| parse_args((const char **) argv + 1, argc - 1, *stack_a) == 0)
	{
		if (*stack_a != NULL)
			free_stack(*stack_a);
		if (*stack_b != NULL)
			free_stack(*stack_b);
		write(STDERR_FILENO, ERR, ft_strlen(ERR));
		exit(EXIT_FAILURE);
	}
}

static void	read_commands(t_stack *stack_a, t_stack *stack_b)
{
	const char	*command;
	bool		err;

	err = false;
	command = get_next_line(STDIN_FILENO);
	while (command != NULL && !err)
	{
		if (!exec_command(stack_a, stack_b, command))
			err = true;
		free((void *) command);
		command = get_next_line(STDIN_FILENO);
	}
	while (command != NULL)
	{
		free((void *) command);
		command = get_next_line(STDIN_FILENO);
	}
	if (err)
	{
		write(STDERR_FILENO, ERR, ft_strlen(ERR));
		free_stack(stack_a);
		free_stack(stack_b);
		exit(EXIT_FAILURE);
	}
}

static bool	exec_command(t_stack *stack_a, t_stack *stack_b,
				const char *command)
{
	size_t	command_len;

	command_len = ft_strlen(command);
	return (command_switch(stack_a, stack_b, command, command_len));
}

static bool command_switch(t_stack *stack_a, t_stack *stack_b,
				const char *command, size_t command_len)
{
	if (ft_strncmp(command, "sa\n", command_len + 1) == 0
		|| ft_strncmp(command, "ss\n", command_len + 1) == 0)
		op_swap(stack_a);
	else if (ft_strncmp(command, "sb\n", command_len + 1) == 0
		|| ft_strncmp(command, "ss\n", command_len + 1) == 0)
		op_swap(stack_b);
	else if (ft_strncmp(command, "pa\n", command_len + 1) == 0)
		op_push(stack_b, stack_a);
	else if (ft_strncmp(command, "pb\n", command_len + 1) == 0)
		op_push(stack_a, stack_b);
	else if (ft_strncmp(command, "ra\n", command_len + 1) == 0
		|| ft_strncmp(command, "rr\n", command_len + 1) == 0)
		op_rotate(stack_a);
	else if (ft_strncmp(command, "rb\n", command_len + 1) == 0
		|| ft_strncmp(command, "rr\n", command_len + 1) == 0)
		op_rotate(stack_b);
	else if (ft_strncmp(command, "rra\n", command_len + 1) == 0
		|| ft_strncmp(command, "rrr\n", command_len + 1) == 0)
		op_reverse_rotate(stack_a);
	else if (ft_strncmp(command, "rrb\n", command_len + 1) == 0
		|| ft_strncmp(command, "rrr\n", command_len + 1) == 0)
		op_reverse_rotate(stack_b);
	else
		return (false);
	return (true);
}
