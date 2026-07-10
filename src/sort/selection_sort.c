/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   selection_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohsawa <yohsawa@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/27 18:55:21 by yohsawa           #+#    #+#             */
/*   Updated: 2026/07/10 16:19:20 by yohsawa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_three(t_context *context)
{
	t_stack	*a;

	a = context->a;
	if (a->data[0] < a->data[1] && a->data[1] < a->data[2])
		return ;
	if (a->data[0] > a->data[1] && a->data[0] < a->data[2])
		sa(context);
	else if (a->data[0] > a->data[1] && a->data[1] > a->data[2])
	{
		sa(context);
		rra(context);
	}
	else if (a->data[0] > a->data[1] && a->data[1] < a->data[2])
		ra(context);
	else if (a->data[0] < a->data[1] && a->data[1] > a->data[2]
		&& a->data[0] < a->data[2])
	{
		sa(context);
		ra(context);
	}
	else if (a->data[0] < a->data[1] && a->data[0] > a->data[2])
		rra(context);
}

static void	rotate_target_to_top(t_context *context, int target)
{
	t_stack	*a;
	int		pos;

	a = context->a;
	pos = find_pos(a, target);
	if (pos <= a->size / 2)
	{
		while (pos-- > 0)
			ra(context);
	}
	else
	{
		pos = a->size - pos;
		while (pos-- > 0)
			rra(context);
	}
}

int	selection_sort(t_context *context)
{
	t_stack	*a;
	t_stack	*b;
	int		target;

	a = context->a;
	b = context->b;
	target = 0;
	if (a->size == 2)
	{
		sa(context);
		return (1);
	}
	while (a->size > 3)
	{
		rotate_target_to_top(context, target);
		if (is_sorted(a))
			break ;
		pb(context);
		target++;
	}
	if (a->size == 3)
		sort_three(context);
	while (b->size > 0)
		pa(context);
	return (1);
}
