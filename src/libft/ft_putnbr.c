/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohsawa <yohsawa@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/06 18:26:29 by yohsawa           #+#    #+#             */
/*   Updated: 2026/07/10 16:21:39 by yohsawa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_putnbr(long n)
{
	char	c;
	long	divisor;

	if (n < 0)
	{
		write(1, "-", 1);
		n *= -1;
	}
	divisor = 1;
	while (n / divisor >= 10)
		divisor *= 10;
	while (divisor > 0)
	{
		c = (n / divisor) % 10 + '0';
		write(1, &c, 1);
		divisor /= 10;
	}
	write(1, "\n", 1);
}
