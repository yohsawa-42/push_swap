/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohsawa <yohsawa@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/27 18:54:54 by yohsawa           #+#    #+#             */
/*   Updated: 2026/07/04 15:14:08 by yohsawa          ###   ########.fr       */
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

int	radix_sort(t_stack *a, t_stack *b, t_operations *op)
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
				ra(a, op);
			else
				pb(a, b, op);
			i++;
		}
		while (b->size > 0)
			pa(a, b, op);
		bit++;
	}
	return (1);
}
