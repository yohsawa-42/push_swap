/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   selection_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohsawa <yohsawa@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/27 18:55:21 by yohsawa           #+#    #+#             */
/*   Updated: 2026/07/03 18:42:58 by yohsawa          ###   ########.fr       */
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
	int	size;

	target = 0;
	size = a->size;
	while (target < size)
	{
		rotate_target_to_top(a, target);
		pb(a, b);
		target++;
	}
	while (b->size > 0)
		pa(a, b);
	return (1);
}
