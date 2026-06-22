/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohsawa <yohsawa@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/05 19:26:08 by yohsawa           #+#    #+#             */
/*   Updated: 2026/05/22 03:56:06 by yohsawa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_convert(const char type, va_list vargs)
{
	if (type == 'c')
		return (ft_putchar(va_arg(vargs, int)));
	else if (type == 's')
		return (ft_putstr(va_arg(vargs, char *)));
	else if (type == 'd' || type == 'i')
		return (ft_putnbr(va_arg(vargs, int)));
	else if (type == 'u')
		return (ft_putnbr(va_arg(vargs, unsigned int)));
	else if (type == 'x' || type == 'X')
		return (ft_putnbr_hex(va_arg(vargs, unsigned int), type));
	else if (type == 'p')
		return (ft_putptr(va_arg(vargs, void *)));
	else if (type == '%')
		return (ft_putchar('%'));
	return (-1);
}

int	ft_printf(const char *str, ...)
{
	va_list	vargs;
	int		i;
	int		len;
	int		check;

	va_start(vargs, str);
	i = 0;
	len = 0;
	while (str[i])
	{
		if (str[i] == '%')
			check = ft_convert(str[++i], vargs);
		else
			check = ft_putchar(str[i]);
		if (check == -1)
			return (va_end(vargs), -1);
		len += check;
		i++;
	}
	va_end(vargs);
	return (len);
}

// #include <limits.h>
// #include <stdio.h>

// int	main(void)
// {
// 	int	a;
// 	int	b;

// 	a = printf("std: [%c] [%s] [%d] [%i] [%u] [%x] [%X] [%%]\n", 'A', "hello",
// 			-42, INT_MIN, UINT_MAX, UINT_MAX, 48879);
// 	b = ft_printf("ft : [%c] [%s] [%d] [%i] [%u] [%x] [%X] [%%]\n", 'A',
// 			"hello", -42, INT_MIN, UINT_MAX, UINT_MAX, 48879);
// 	printf("ret std=%d ft=%d\n", a, b);
// 	a = printf("std null: [%s] [%p]\n", (char *)0, (void *)0);
// 	b = ft_printf("ft  null: [%s] [%p]\n", (char *)0, (void *)0);
// 	printf("ret std=%d ft=%d\n", a, b);
// 	return (0);
// }
