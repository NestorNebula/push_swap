/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhoussie <nhoussie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 13:23:35 by nhoussie          #+#    #+#             */
/*   Updated: 2025/11/25 09:43:06 by nhoussie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>
#include "conv.h"

static int	handle_char(char c, bool *err);

static int	handle_conversion(const char **format, va_list ap, bool *err);

/**
 *  Writes formatted output to stdout using format and others arguments.
 *
 *  @param format The format of the output
 *  @param ... Optional arguments to use in combination with the format
 *  @return The number of characters printed. -1 if an error occurs
 */
int	ft_printf(const char *format, ...)
{
	int		res;
	bool	err;
	va_list	ap;

	res = 0;
	err = false;
	if (format == NULL)
		return (-1);
	va_start(ap, format);
	while (*format != '\0')
	{
		if (*format != '%')
			res += handle_char(*format++, &err);
		else
			res += handle_conversion(&format, ap, &err);
	}
	va_end(ap);
	if (err)
		return (-1);
	return (res);
}

static int	handle_char(char c, bool *err)
{
	int	res;

	res = write(STDOUT_FILENO, &c, 1);
	if (res != 1)
	{
		*err = true;
		return (-1);
	}
	return (res);
}

static int	handle_conversion(const char **format, va_list ap, bool *err)
{
	int		res;
	t_conv	conv;

	res = -1;
	(*format)++;
	*format += read_conv(*format, &conv);
	check_conv(&conv);
	if (conv.err)
	{
		if (conv.type != '\0')
			res = handle_char('%', err);
		if (res != 1)
			*err = true;
	}
	else if (set_conv_val(ap, &conv) == NULL)
		*err = true;
	else
	{
		set_conv_pref(&conv);
		res = print_conv(&conv, STDOUT_FILENO);
		if (res == -1)
			*err = true;
		free(conv.val);
	}
	return (res);
}
