/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msumiji <msumiji@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/21 00:00:00 by yohsawa           #+#    #+#             */
/*   Updated: 2026/06/25 16:03:48 by msumiji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_max_bits(int size)
{
	int	max;
	int	bits;

	max = size - 1;
	bits = 0;
	while ((max >> bits) != 0)
		bits++;
	return (bits);
}

static void	radix_sort(t_stack *a, t_stack *b)
{
	int	i;
	int	bit;
	int	size;
	int	max_bits;

	size = a->size;
	max_bits = get_max_bits(size);
	bit = 0;
	while (bit < max_bits)
	{
		i = 0;
		while (i < size)
		{
			if (((a->data[0] >> bit) & 1) == 1)
				ra(a);
			else
				pb(a, b);
			i++;
		}
		while (b->size > 0)
			pa(a, b);
		bit++;
	}
}

int	sort_stack(t_stack *a, t_stack *b)
{
	if (!compress_stack(a))
		return (0);
	if (a->size <= 5)
		sort_small(a, b);
	else
		radix_sort(a, b);
	return (1);
}
