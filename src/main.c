/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhoussie <nhoussie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 10:32:55 by nhoussie          #+#    #+#             */
/*   Updated: 2026/01/15 11:48:13 by nhoussie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include "parse.h"
#include "sort.h"
#include "stack.h"
#include "unistd.h"

#define ERR "Error\n"

static void	init_prog(int argc, char *argv[],
		t_stack **stack_a, t_stack **stack_b);

int main(int argc, char *argv[])
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (argc < 2)
		return (0);
	init_prog(argc, argv, &stack_a, &stack_b);
	sort(stack_a, stack_b);
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
