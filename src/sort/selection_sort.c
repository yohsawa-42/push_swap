/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   selection_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohsawa <yohsawa@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/27 18:55:21 by yohsawa           #+#    #+#             */
/*   Updated: 2026/07/04 15:14:10 by yohsawa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

static void	rotate_target_to_top(t_stack *a, int target, t_operations *op)
{
	int	pos;

	pos = find_pos(a, target);
	if (pos <= a->size / 2)
	{
		while (pos-- > 0)
			ra(a, op);
	}
	else
	{
		pos = a->size - pos;
		while (pos-- > 0)
			rra(a, op);
	}
}

int	selection_sort(t_stack *a, t_stack *b, t_operations *op)
{
	int	target;
	int	size;

	target = 0;
	size = a->size;
	while (target < size)
	{
		rotate_target_to_top(a, target, op);
		pb(a, b, op);
		target++;
	}
	while (b->size > 0)
		pa(a, b, op);
	return (1);
}
