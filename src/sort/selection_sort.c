/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   selection_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msumiji <msumiji@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/27 18:55:21 by yohsawa           #+#    #+#             */
/*   Updated: 2026/07/05 15:06:52 by msumiji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

static int	find_pos(t_stack *a, int target)
{
	int	i;

	i = 0;
	while (i < a->size)
	{
		if (a->data[i] == target)
			return (i);
		i++;
	}
	return (-1);
}

static void	rotate_target_to_top(t_stack *a, int target)
{
	int	pos;

	pos = find_pos(a, target);
	if (pos <= a->size / 2)
	{
		while (pos-- > 0)
			ra(a);
	}
	else
	{
		pos = a->size - pos;
		while (pos-- > 0)
			rra(a);
	}
}

int	selection_sort(t_stack *a, t_stack *b)
{
	int	target;

	target = 0;
	if (a->size == 2)
	{
		sa(a);
		return (1);
	}
	while (a->size > 3)
	{
		rotate_target_to_top(a, target);
		if (is_sorted(a))
			break ;
		pb(a, b);
		target++;
	}
	if (a->size == 3)
		sort_three(a);
	while (b->size > 0)
		pa(a, b);
	return (1);
}
