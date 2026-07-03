/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohsawa <yohsawa@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/27 18:11:10 by msumiji           #+#    #+#             */
/*   Updated: 2026/07/03 18:42:53 by yohsawa          ###   ########.fr       */
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

static void	push_target(t_stack *a, t_stack *b, int target, int rotate)
{
	int	j;

	j = 0;
	while (j <= a->size / 2)
	{
		if (a->data[j] == target)
		{
			ra_and_pb(a, b, j);
			if (rotate && b->size > 1)
				rb(b);
			return ;
		}
		if (a->data[a->size - j - 1] == target)
		{
			ra_and_pb(a, b, a->size - j - 1);
			if (rotate && b->size > 1)
				rb(b);
			return ;
		}
		j++;
	}
}

static void	a_to_b(t_stack *a, t_stack *b, int *data, int chunk_size)
{
	int	i;
	int	start;
	int	size;

	size = a->size;
	start = 0;
	while (start < size)
	{
		i = start;
		while (i < start + chunk_size && i < size)
		{
			push_target(a, b, data[i], i < start + chunk_size / 2);
			i++;
		}
		start += chunk_size;
	}
}

static void	b_to_a(t_stack *a, t_stack *b, int *data)
{
	int	i;
	int	j;
	int	size;

	i = 0;
	size = b->size;
	while (i < size)
	{
		j = 0;
		while (j <= b->size / 2)
		{
			if (b->data[j] == data[size - i - 1])
			{
				rb_and_pa(a, b, j);
				break ;
			}
			if (b->data[b->size - j - 1] == data[size - i - 1])
			{
				rb_and_pa(a, b, b->size - j - 1);
				break ;
			}
			j++;
		}
		i++;
	}
}

int	chunk_sort(t_stack *a, t_stack *b)
{
	int	*data;
	int	i;
	int	size;

	i = 0;
	size = a->size;
	data = malloc(sizeof(int) * size);
	if (!data)
		return (0);
	while (i < size)
	{
		data[i] = a->data[i];
		i++;
	}
	sort_array(data, size);
	a_to_b(a, b, data, get_chunk_size(size));
	b_to_a(a, b, data);
	free(data);
	return (1);
}
