/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_conv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhoussie <nhoussie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 10:55:39 by nhoussie          #+#    #+#             */
/*   Updated: 2025/11/24 13:18:55 by nhoussie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"
#include "conv.h"
#include "typeutils.h"

static void	prepare_special_cases(t_conv *conv);

static int	handle_complex_conv(t_conv *conv, int fd);

static int	print_width(t_conv *conv, int fd);

static int	print_precision(t_conv *conv, int fd);

int	print_conv(t_conv *conv, int fd)
{
	int		res;

	if (conv->err)
	{
		write(fd, "%", 1);
		return (-1);
	}
	prepare_special_cases(conv);
	if (!(conv->flags & DOT_F) && !conv->width)
	{
		res = write(fd, conv->pref, conv->pref_len);
		res += write(fd, conv->val, conv->val_len);
		if (res < 0 || (size_t) res != (conv->pref_len + conv->val_len))
			return (-1);
		return (res);
	}
	return (handle_complex_conv(conv, fd));
}

static void	prepare_special_cases(t_conv *conv)
{
	if (conv->type == 'X')
	{
		if (conv->pref_len > 0)
			str_toupper(conv->pref);
		str_toupper(conv->val);
	}
	else if (conv->type == 's' || conv->type == '%')
		conv->prec = 0;
	if (conv->type == '%')
		conv->width = 0;
	if (((conv->flags & DOT_F) && conv->type != 'p') || (conv->flags & DASH_F))
		conv->flags &= (~ZERO_F);
	if (conv->type == 'c')
		conv->val_len = 1;
	if (ft_strchr("pdiuxX", conv->type) && (conv->flags & DOT_F)
		&& conv->val[0] == '0')
		conv->val_len = 0;
}

static int	handle_complex_conv(t_conv *conv, int fd)
{
	int	res;

	res = 0;
	if ((conv->flags & DOT_F) && conv->val_len < conv->prec)
		conv->prec_len = conv->prec;
	else
		conv->prec_len = conv->val_len;
	if (!(conv->flags & DASH_F) && !(conv->flags & ZERO_F))
		res += print_width(conv, fd);
	res += write(fd, conv->pref, conv->pref_len);
	if (!(conv->flags & DASH_F) && (conv->flags & ZERO_F))
		res += print_width(conv, fd);
	res += print_precision(conv, fd);
	res += write(fd, conv->val, conv->val_len);
	if (conv->flags & DASH_F)
		res += print_width(conv, fd);
	if (conv->width < conv->pref_len + conv->prec_len)
		conv->width = conv->pref_len + conv->prec_len;
	if (res != (int) conv->width)
		return (-1);
	return (conv->width);
}

static int	print_width(t_conv *conv, int fd)
{
	int		res;
	size_t	i;
	char	c;

	res = 0;
	if ((conv->flags & ZERO_F) && !(conv->flags & DASH_F))
		c = '0';
	else
		c = ' ';
	i = conv->pref_len + conv->prec_len;
	while (i < conv->width)
	{
		res += write(fd, &c, 1);
		i++;
	}	
	return (res);
}

static int	print_precision(t_conv *conv, int fd)
{
	int		res;
	size_t	i;

	res = 0;
	i = conv->val_len;
	while (i < conv->prec_len)
	{
		res += write(fd, "0", 1);
		i++;
	}
	return (res);
}
