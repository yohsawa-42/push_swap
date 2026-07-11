/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msumiji <msumiji@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/27 18:54:54 by yohsawa           #+#    #+#             */
/*   Updated: 2026/07/11 10:14:48 by msumiji          ###   ########.fr       */
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

int	radix_sort(t_context *context)
{
	int			i;
	int			bit;
	int			max_bits;

	max_bits = get_max_bits(context->a->size);
	bit = 0;
	if (context->a->size <= 5)
		return (selection_sort(context));
	while (bit < max_bits)
	{
		i = 0;
		while (i < context->a->size + context->b->size)
		{
			if (((context->a->data[0] >> bit) & 1) == 1)
				ra(context);
			else
				pb(context);
			i++;
		}
		while (context->b->size > 0)
			pa(context);
		bit++;
	}
	return (1);
}
