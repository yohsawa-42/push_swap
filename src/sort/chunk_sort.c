/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msumiji <msumiji@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/27 18:11:10 by msumiji           #+#    #+#             */
/*   Updated: 2026/07/11 11:16:08 by msumiji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

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
	int		size;

	a = context->a;
	b = context->b;
	size = a->size + b->size;
	middle = start + (end - start) / 2;
	pushed = 0;
	while (pushed < end - start
		&& !(is_sorted(a) && a->data[0] == size - a->size))
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

static void	rb_and_pa(t_context *context, int pos)
{
	int	steps;

	steps = 0;
	if (pos <= context->b->size / 2)
	{
		while (steps < pos)
		{
			rb(context);
			steps++;
		}
	}
	else
	{
		while (steps < context->b->size - pos)
		{
			rrb(context);
			steps++;
		}
	}
	pa(context);
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
	if (size <= 5)
		return (selection_sort(context));
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
