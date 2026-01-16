/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhoussie <nhoussie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 08:51:59 by nhoussie          #+#    #+#             */
/*   Updated: 2026/01/08 08:59:32 by nhoussie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H

# include "stack.h"

/**
 * Parse the program's arguments and store them in stack.
 *
 * @param args The program's arguments
 * @param args_size The size of args
 * @param stack A pointer to a stack that will store the parsed arguments.
 * If NULL, the parsed arguments will not be stored anywhere
 * @return The number of ints parsed,
 * 0 if no int was found or if an error occurred
 */
size_t	parse_args(const char **args, size_t args_size, t_stack *stack);

#endif // !PARSE_H
