/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhoussie <nhoussie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 15:40:01 by nhoussie          #+#    #+#             */
/*   Updated: 2026/01/15 11:46:53 by nhoussie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include <stdbool.h>
#include "libft.h"
#include "parse.h"

static bool		int_from_str(const char **str_ptr, int *int_ptr);

static size_t	parse_arg(const char *arg, t_stack *stack);

static bool		check_duplicates(t_stack *stack);

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
	if (stack != NULL && !check_duplicates(stack))
		return (0);
	if (stack != NULL)
		stack->len = count;
	return (count);
}

static bool	int_from_str(const char **str_ptr, int *int_ptr)
{
	uint64_t		nbr;
	int				tmp;
	bool			is_negative;

	nbr = 0;
	is_negative = **str_ptr == '-';
	if (**str_ptr == '-' || **str_ptr == '+')
		(void)(*str_ptr)++;
	if (**str_ptr == '\0')
		return (false);
	while (ft_isdigit(**str_ptr))
	{
		nbr = nbr * 10 + (**str_ptr - '0');
		if ((!is_negative && nbr > INT_MAX)
			|| (is_negative && nbr > (uint64_t) INT_MAX + 1))
			return (false);
		(void)(*str_ptr)++;
	}
	tmp = nbr;
	if (is_negative)
		tmp = -((int) nbr);
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

static bool		check_duplicates(t_stack *stack)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < stack->size - 1)
	{
		j = i + 1;
		while (j < stack->size)
			if (stack->content[i] == stack->content[j++])
				return (false);
		i++;
	}
	return (true);
}
