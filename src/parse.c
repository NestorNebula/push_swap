/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhoussie <nhoussie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 15:40:01 by nhoussie          #+#    #+#             */
/*   Updated: 2026/01/08 15:45:31 by nhoussie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include <stdbool.h>
#include "libft.h"
#include "parse.h"

static bool		int_from_str(const char **str_ptr, int *int_ptr);

static size_t	parse_arg(const char *arg, t_stack *stack);

size_t	parse_args(const char **args, size_t args_size, t_stack *stack)
{
	size_t	count;
	size_t	tmp;
	size_t	i;

	count = 0;
	i = 0;
	if (stack)
	{
		stack->top = stack->size;
		stack->bottom = stack->top;
	}
	while (i < args_size)
	{
		tmp = parse_arg(args[i++], stack);
		if (tmp == 0)
			return (0);
		count += tmp;
	}
	return (count);
}

static bool	int_from_str(const char **str_ptr, int *int_ptr)
{
	long			tmp;
	bool			is_negative;

	tmp = 0;
	is_negative = **str_ptr == '-';
	if (**str_ptr == '-' || **str_ptr == '+')
		(void)(*str_ptr)++;
	while (ft_isdigit(**str_ptr))
	{
		if (INT_MAX / 10 - (**str_ptr - '0') < tmp)
			return (false);
		tmp = tmp * 10 + (**str_ptr - '0');
		(void)(*str_ptr)++;
	}
	if (is_negative)
		tmp = -tmp;
	if (int_ptr != NULL)
		*int_ptr = tmp;
	return (**str_ptr == '\0' || **str_ptr == ' ');
}

static size_t	parse_arg(const char *arg, t_stack *stack)
{
	size_t	count;
	bool	is_valid_int;

	count = 0;
	while (*arg != '\0')
	{
		while (*arg == ' ')
			(void) *arg++;
		if (*arg == '\0')
			return (count);
		if (stack != NULL)
			is_valid_int = int_from_str(&arg, stack->content + --stack->bottom);
		else
			is_valid_int = int_from_str(&arg, NULL);
		if (!is_valid_int)
			return (0);
		count++;
	}
	return (count);
}
