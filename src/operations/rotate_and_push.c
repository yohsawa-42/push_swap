/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_and_push.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohsawa <yohsawa@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/04 14:45:00 by yohsawa           #+#    #+#             */
/*   Updated: 2026/07/04 15:13:55 by yohsawa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra_and_pb(t_stack *a, t_stack *b, int pos, t_operations *op)
{
	int	steps;

	steps = 0;
	if (pos <= a->size / 2)
	{
		while (steps < pos)
		{
			ra(a, op);
			steps++;
		}
	}
	else
	{
		while (steps < a->size - pos)
		{
			rra(a, op);
			steps++;
		}
	}
	pb(a, b, op);
}

void	rb_and_pa(t_stack *a, t_stack *b, int pos, t_operations *op)
{
	int	steps;

	steps = 0;
	if (pos <= b->size / 2)
	{
		while (steps < pos)
		{
			rb(b, op);
			steps++;
		}
	}
	else
	{
		while (steps < b->size - pos)
		{
			rrb(b, op);
			steps++;
		}
	}
	pa(a, b, op);
}
