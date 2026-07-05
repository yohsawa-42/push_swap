/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msumiji <msumiji@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/02 15:59:03 by yohsawa           #+#    #+#             */
/*   Updated: 2026/07/05 14:17:02 by msumiji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push_stack(t_stack *dst, t_stack *src)
{
	int	i;

	if (src->size == 0)
		return ;
	i = dst->size;
	while (i > 0)
	{
		dst->data[i] = dst->data[i - 1];
		i--;
	}
	dst->data[0] = src->data[0];
	dst->size++;
	i = 0;
	while (i < src->size - 1)
	{
		src->data[i] = src->data[i + 1];
		i++;
	}
	src->size--;
}

void	pa(t_stack *a, t_stack *b)
{
	if (b->size == 0)
		return ;
	push_stack(a, b);
	write(1, "pa\n", 3);
	a->pa++;
}

void	pb(t_stack *a, t_stack *b)
{
	if (a->size == 0)
		return ;
	push_stack(b, a);
	write(1, "pb\n", 3);
	b->pb++;
}
