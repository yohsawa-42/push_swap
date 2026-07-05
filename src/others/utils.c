/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msumiji <msumiji@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/02 16:48:40 by yohsawa           #+#    #+#             */
/*   Updated: 2026/07/05 14:14:23 by msumiji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_benchmark(t_stack *a, t_stack *b, t_benchmark *flag)
{
	a->data = NULL;
	b->data = NULL;
	flag->bench = 0;
	flag->simple = 0;
	flag->medium = 0;
	flag->complex = 0;
	flag->adaptive = 0;
	flag->disorder = 1.0;
}

void	init_operations(t_stack *a, t_stack *b)
{
	a->pa = 0;
	a->pb = 0;
	a->sa = 0;
	a->sb = 0;
	a->ss = 0;
	a->ra = 0;
	a->rb = 0;
	a->rr = 0;
	a->rra = 0;
	a->rrb = 0;
	a->rrr = 0;
	b->pa = 0;
	b->pb = 0;
	b->sa = 0;
	b->sb = 0;
	b->ss = 0;
	b->ra = 0;
	b->rb = 0;
	b->rr = 0;
	b->rra = 0;
	b->rrb = 0;
	b->rrr = 0;
}

void	free_stack(t_stack *stack)
{
	if (stack->data)
		free(stack->data);
	stack->data = NULL;
	stack->size = 0;
}
