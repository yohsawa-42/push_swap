/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msumiji <msumiji@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/26 18:12:58 by msumiji           #+#    #+#             */
/*   Updated: 2026/07/03 09:02:57 by msumiji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ewrite(char *c)
{
	if (write(2, c, 1) < 0)
		return (-1);
	return (1);
}

static int	convert(char c, va_list ap)
{
	if (c == 'c')
		return (print_char(va_arg(ap, int)));
	else if (c == 's')
		return (print_str(va_arg(ap, char *)));
	else if (c == 'd' || c == 'i')
		return (print_int(va_arg(ap, int)));
	else if (c == 'f')
		return (print_double(va_arg(ap, double)));
	else if (c == '%')
		return (ewrite("%"));
	else
	{
		if (write(2, "%", 1) < 0)
			return (-1);
		if (write(2, &c, 1) < 0)
			return (-1);
		return (2);
	}
}

static int	read_fmt(va_list ap, const char *fmt)
{
	int	ret;
	int	count;

	count = 0;
	while (*fmt)
	{
		if (*fmt == '%')
		{
			if (!*(fmt + 1))
				return (-1);
			ret = convert(*(fmt + 1), ap);
			if (ret < 0)
				return (-1);
			count += ret;
			fmt = fmt + 2;
		}
		else
		{
			if (write(2, fmt, 1) < 0)
				return (-1);
			fmt++;
			count++;
		}
	}
	return (count);
}

int	ft_printf(const char *fmt, ...)
{
	va_list	ap;
	int		count;

	if (!fmt)
		return (-1);
	va_start(ap, fmt);
	count = read_fmt(ap, fmt);
	va_end(ap);
	return (count);
}
