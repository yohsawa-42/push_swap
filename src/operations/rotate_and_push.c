/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_and_push.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msumiji <msumiji@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/04 14:45:00 by yohsawa           #+#    #+#             */
/*   Updated: 2026/07/05 14:42:26 by msumiji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra_and_pb(t_stack *a, t_stack *b, int pos)
{
	int	steps;

	steps = 0;
	if (pos <= a->size / 2)
	{
		while (steps < pos)
		{
			ra(a);
			steps++;
		}
	}
	else
	{
		while (steps < a->size - pos)
		{
			rra(a);
			steps++;
		}
	}
	pb(a, b);
}

void	rb_and_pa(t_stack *a, t_stack *b, int pos)
{
	int	steps;

	steps = 0;
	if (pos <= b->size / 2)
	{
		while (steps < pos)
		{
			rb(b);
			steps++;
		}
	}
	else
	{
		while (steps < b->size - pos)
		{
			rrb(b);
			steps++;
		}
	}
	pa(a, b);
}
