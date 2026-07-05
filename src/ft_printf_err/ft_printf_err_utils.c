/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_err_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msumiji <msumiji@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/05 11:58:26 by msumiji           #+#    #+#             */
/*   Updated: 2026/07/05 11:58:29 by msumiji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_putchar_err(char c)
{
	return (write(2, &c, 1));
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
	return (i);
}

static int	put_uint_err(unsigned int n)
{
	int	ret;

	ret = 0;
	if (n >= 10)
		ret = put_uint_err(n / 10);
	if (ret < 0 || ft_putchar_err(n % 10 + '0') < 0)
		return (-1);
	return (ret + 1);
}

int	ft_putint_err(int n)
{
	if (n < 0)
	{
		if (ft_putchar_err('-') < 0)
			return (-1);
		return (put_uint_err(-(unsigned int)n) + 1);
	}
	return (put_uint_err((unsigned int)n));
}

int	ft_putdouble_err(double n)
{
	int	ret;
	int	decimal;

	ret = ft_putint_err((int)n);
	if (ret < 0 || ft_putchar_err('.') < 0)
		return (-1);
	decimal = (int)((n - (int)n) * 10);
	if (decimal < 0)
		decimal = -decimal;
	if (ft_putchar_err(decimal + '0') < 0)
		return (-1);
	return (ret + 2);
}
