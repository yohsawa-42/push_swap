/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msumiji <msumiji@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/27 18:11:10 by msumiji           #+#    #+#             */
/*   Updated: 2026/07/05 14:31:35 by msumiji          ###   ########.fr       */
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

static void	push_chunk_to_b(t_stack *a, t_stack *b, int start, int end)
{
	int	middle;
	int	pushed;

	middle = start + (end - start) / 2;
	pushed = 0;
	while (pushed < end - start)
	{
		if (start <= a->data[0] && a->data[0] < end)
		{
			pb(a, b);
			if (b->data[0] < middle && b->size > 1)
				rb(b);
			pushed++;
		}
		else
			ra(a);
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

static void	b_to_a(t_stack *a, t_stack *b)
{
	int	target;
	int	pos;

	target = b->size - 1;
	while (target >= 0)
	{
		pos = find_pos(b, target);
		rb_and_pa(a, b, pos);
		target--;
	}
}

int	chunk_sort(t_stack *a, t_stack *b)
{
	int	chunk_size;
	int	start;
	int	end;
	int	size;

	size = a->size;
	chunk_size = get_chunk_size(size);
	start = 0;
	while (start < size)
	{
		end = start + chunk_size;
		if (end > size)
			end = size;
		push_chunk_to_b(a, b, start, end);
		start = end;
	}
	b_to_a(a, b);
	return (1);
}
