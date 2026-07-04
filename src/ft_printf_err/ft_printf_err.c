/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_err.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohsawa <yohsawa@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/26 18:12:58 by msumiji           #+#    #+#             */
/*   Updated: 2026/07/04 14:52:52 by yohsawa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	convert(char c, va_list ap)
{
	if (c == 's')
		return (ft_putstr_err(va_arg(ap, char *)));
	if (c == 'd' || c == 'i')
		return (ft_putint_err(va_arg(ap, int)));
	if (c == 'f')
		return (ft_putdouble_err(va_arg(ap, double)));
	if (c == '%')
		return (ft_putchar_err('%'));
	return (ft_putchar_err(c));
}

int	ft_printf_err(const char *fmt, ...)
{
	va_list	ap;
	int		ret;
	int		total;

	if (!fmt)
		return (-1);
	va_start(ap, fmt);
	total = 0;
	while (*fmt)
	{
		if (*fmt == '%' && *(fmt + 1))
			ret = convert(*++fmt, ap);
		else
			ret = ft_putchar_err(*fmt);
		if (ret < 0)
			return (va_end(ap), -1);
		total += ret;
		fmt++;
	}
	va_end(ap);
	return (total);
}
