/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohsawa <yohsawa@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/05 19:55:58 by yohsawa           #+#    #+#             */
/*   Updated: 2026/05/22 03:55:45 by yohsawa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

int	ft_putstr(const char *str)
{
	int	len;

	if (!str)
		return (write(1, "(null)", 6));
	len = 0;
	while (str[len])
		len++;
	if (write(1, str, len) == -1)
		return (-1);
	return (len);
}

int	ft_putnbr(long n)
{
	char	c;
	int		len;
	long	divisor;

	len = 0;
	if (n < 0)
	{
		if (write(1, "-", 1) == -1)
			return (-1);
		n *= -1;
		len++;
	}
	divisor = 1;
	while (n / divisor >= 10)
		divisor *= 10;
	while (divisor > 0)
	{
		c = (n / divisor) % 10 + '0';
		if (write(1, &c, 1) == -1)
			return (-1);
		len++;
		divisor /= 10;
	}
	return (len);
}

int	ft_putnbr_hex(unsigned long n, char type)
{
	char			*base;
	unsigned long	divisor;
	int				len;

	len = 0;
	if (type == 'X')
		base = "0123456789ABCDEF";
	else
		base = "0123456789abcdef";
	divisor = 1;
	while (n / divisor >= 16)
		divisor *= 16;
	while (divisor > 0)
	{
		if (write(1, &base[(n / divisor) % 16], 1) == -1)
			return (-1);
		len++;
		divisor /= 16;
	}
	return (len);
}

int	ft_putptr(void *ptr)
{
	int	len;

	if (!ptr)
		return (write(1, "(nil)", 5));
	if (ft_putstr("0x") == -1)
		return (-1);
	len = ft_putnbr_hex((unsigned long)ptr, 'x');
	if (len == -1)
		return (-1);
	return (len + 2);
}
