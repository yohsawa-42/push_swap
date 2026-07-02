/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msumiji <msumiji@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/26 18:16:26 by msumiji           #+#    #+#             */
/*   Updated: 2026/07/02 18:53:55 by msumiji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	count_ldigit(long nb)
{
	int	i;

	i = 0;
	while (nb != 0)
	{
		nb = nb / 10;
		i++;
	}
	return (i);
}

static int	output(long nb, int m)
{
	char	*c;
	int		i;

	i = 0;
	c = malloc(sizeof(char) * m);
	while (i < m)
	{
		c[m - i - 1] = nb % 10 + '0';
		nb = nb / 10;
		i++;
	}
	i = 0;
	while (i < m)
	{
		if (write(2, &c[i], 1) < 0)
			return (-1);
		i++;
	}
	free(c);
	return (i);
}

int	print_int(int n)
{
	int		i;
	long	nb;

	i = 0;
	nb = (long)n;
	if (nb == 0)
	{
		if (write(2, "0", 1) < 0)
			return (-1);
		return (1);
	}
	if (nb < 0)
	{
		if (write(2, "-", 1) < 0)
			return (-1);
		nb = -nb;
		i++;
	}
	i += count_ldigit(nb);
	if (output(nb, count_ldigit(nb)) < 0)
		return (-1);
	return (i);
}
