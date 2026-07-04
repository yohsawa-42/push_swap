/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohsawa <yohsawa@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/27 18:11:10 by msumiji           #+#    #+#             */
/*   Updated: 2026/07/04 17:25:27 by yohsawa          ###   ########.fr       */
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

static void	push_chunk_to_b(t_stack *a, t_stack *b, int range[2],
		t_operations *op)
{
	int	start;
	int	end;
	int	middle;
	int	pushed;

	start = range[0];
	end = range[1];
	middle = start + (end - start) / 2;
	pushed = 0;
	while (pushed < end - start)
	{
		if (start <= a->data[0] && a->data[0] < end)
		{
			pb(a, b, op);
			if (b->data[0] < middle && b->size > 1)
				rb(b, op);
			pushed++;
		}
		else
			ra(a, op);
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

static void	b_to_a(t_stack *a, t_stack *b, t_operations *op)
{
	int	target;
	int	pos;

	target = b->size - 1;
	while (target >= 0)
	{
		pos = find_pos(b, target);
		rb_and_pa(a, b, pos, op);
		target--;
	}
}

int	chunk_sort(t_stack *a, t_stack *b, t_operations *op)
{
	int	chunk_size;
	int	start;
	int	end;
	int	range[2];
	int	size;

	size = a->size;
	chunk_size = get_chunk_size(size);
	start = 0;
	while (start < size)
	{
		end = start + chunk_size;
		if (end > size)
			end = size;
		range[0] = start;
		range[1] = end;
		push_chunk_to_b(a, b, range, op);
		start = end;
	}
	b_to_a(a, b, op);
	return (1);
}
