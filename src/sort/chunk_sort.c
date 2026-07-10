/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohsawa <yohsawa@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/27 18:11:10 by msumiji           #+#    #+#             */
/*   Updated: 2026/07/10 15:50:24 by yohsawa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_chunk_size(int size)
{
	int	chunk_size;

	chunk_size = 1;
	while (chunk_size <= size / chunk_size)
		chunk_size++;
	return (chunk_size);
}

static void	push_chunk_to_b(t_context *context, int start, int end)
{
	t_stack	*a;
	t_stack	*b;
	int		middle;
	int		pushed;

	a = context->a;
	b = context->b;
	middle = start + (end - start) / 2;
	pushed = 0;
	while (pushed < end - start)
	{
		if (start <= a->data[0] && a->data[0] < end)
		{
			pb(context);
			if (b->data[0] < middle && b->size > 1)
				rb(context);
			pushed++;
		}
		else
			ra(context);
	}
}

static int	find_pos(t_stack *stack, int target)
{
	int	pos;

	pos = 0;
	while (pos < stack->size)
	{
		if (stack->data[pos] == target)
			return (pos);
		pos++;
	}
	return (-1);
}

static void	b_to_a(t_context *context)
{
	t_stack	*b;
	int		target;
	int		pos;

	b = context->b;
	target = b->size - 1;
	while (target >= 0)
	{
		pos = find_pos(b, target);
		rb_and_pa(context, pos);
		target--;
	}
}

int	chunk_sort(t_context *context)
{
	t_stack	*a;
	int		chunk_size;
	int		start;
	int		end;
	int		size;

	a = context->a;
	size = a->size;
	chunk_size = get_chunk_size(size);
	start = 0;
	while (start < size)
	{
		end = start + chunk_size;
		if (end > size)
			end = size;
		push_chunk_to_b(context, start, end);
		start = end;
	}
	b_to_a(context);
	return (1);
}
