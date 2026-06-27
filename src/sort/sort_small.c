/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohsawa <yohsawa@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/21 00:00:00 by yohsawa           #+#    #+#             */
/*   Updated: 2026/06/21 00:00:00 by yohsawa          ###   ########.fr       */
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

static void	sort_three(t_stack *a)
{
	if (a->data[0] < a->data[1] && a->data[1] < a->data[2])
		return ;
	if (a->data[0] > a->data[1] && a->data[0] < a->data[2])
		sa(a);
	else if (a->data[0] > a->data[1] && a->data[1] > a->data[2])
	{
		sa(a);
		rra(a);
	}
	else if (a->data[0] > a->data[1] && a->data[1] < a->data[2])
		ra(a);
	else if (a->data[0] < a->data[1] && a->data[1] > a->data[2]
		&& a->data[0] < a->data[2])
	{
		sa(a);
		ra(a);
	}
	else if (a->data[0] < a->data[1] && a->data[0] > a->data[2])
		rra(a);
}

static void	push_min_to_b(t_stack *a, t_stack *b)
{
	int	pos;

	pos = find_min_pos(a);
	while (pos != 0)
	{
		if (pos <= a->size / 2)
			ra(a);
		else
			rra(a);
		pos = find_min_pos(a);
	}
	pb(a, b);
}

void	sort_small(t_stack *a, t_stack *b)
{
	if (a->size == 2)
		sa(a);
	else if (a->size == 3)
		sort_three(a);
	else
	{
		while (a->size > 3)
			push_min_to_b(a, b);
		sort_three(a);
		while (b->size > 0)
			pa(a, b);
	}
}
