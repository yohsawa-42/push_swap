/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_err_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohsawa <yohsawa@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/05 11:58:26 by msumiji           #+#    #+#             */
/*   Updated: 2026/07/10 16:56:45 by yohsawa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_putchar_err(char c)
{
	if (write(2, &c, 1) < 0)
		return (-1);
	return (0);
}

int	ft_putstr_err(char *s)
{
	int	i;

	if (!s)
		s = "(null)";
	i = 0;
	while (s[i])
	{
		if (ft_putchar_err(s[i]) < 0)
			return (-1);
		i++;
	}
	return (0);
}

static int	put_uint_err(unsigned int n)
{
	if (n >= 10 && put_uint_err(n / 10) < 0)
		return (-1);
	if (ft_putchar_err(n % 10 + '0') < 0)
		return (-1);
	return (0);
}

int	ft_putint_err(int n)
{
	if (n < 0)
	{
		if (ft_putchar_err('-') < 0)
			return (-1);
		return (put_uint_err(-(unsigned int)n));
	}
	return (put_uint_err((unsigned int)n));
}

int	ft_putdouble_err(double n)
{
	int	scaled;

	scaled = (int)(n * 100 + 0.5);
	if (ft_putint_err(scaled / 100) < 0 || ft_putchar_err('.') < 0)
		return (-1);
	if (ft_putchar_err((scaled / 10) % 10 + '0') < 0 || ft_putchar_err(scaled
			% 10 + '0') < 0)
		return (-1);
	return (0);
}
