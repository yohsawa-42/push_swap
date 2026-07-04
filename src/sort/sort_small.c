/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohsawa <yohsawa@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/21 00:00:00 by yohsawa           #+#    #+#             */
/*   Updated: 2026/07/04 15:14:11 by yohsawa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	find_min_pos(t_stack *a)
{
	int	i;
	int	min;
	int	pos;

	i = 1;
	min = a->data[0];
	pos = 0;
	while (i < a->size)
	{
		if (a->data[i] < min)
		{
			min = a->data[i];
			pos = i;
		}
		i++;
	}
	return (pos);
}

static void	sort_three(t_stack *a, t_operations *op)
{
	if (a->data[0] < a->data[1] && a->data[1] < a->data[2])
		return ;
	if (a->data[0] > a->data[1] && a->data[0] < a->data[2])
		sa(a, op);
	else if (a->data[0] > a->data[1] && a->data[1] > a->data[2])
	{
		sa(a, op);
		rra(a, op);
	}
	else if (a->data[0] > a->data[1] && a->data[1] < a->data[2])
		ra(a, op);
	else if (a->data[0] < a->data[1] && a->data[1] > a->data[2]
		&& a->data[0] < a->data[2])
	{
		sa(a, op);
		ra(a, op);
	}
	else if (a->data[0] < a->data[1] && a->data[0] > a->data[2])
		rra(a, op);
}

static void	push_min_to_b(t_stack *a, t_stack *b, t_operations *op)
{
	int	pos;

	pos = find_min_pos(a);
	while (pos != 0)
	{
		if (pos <= a->size / 2)
			ra(a, op);
		else
			rra(a, op);
		pos = find_min_pos(a);
	}
	pb(a, b, op);
}

int	sort_small(t_stack *a, t_stack *b, t_operations *op)
{
	if (a->size == 2)
		sa(a, op);
	else if (a->size == 3)
		sort_three(a, op);
	else
	{
		while (a->size > 3)
			push_min_to_b(a, b, op);
		sort_three(a, op);
		while (b->size > 0)
			pa(a, b, op);
	}
	return (1);
}
