/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohsawa <yohsawa@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/02 16:48:40 by yohsawa           #+#    #+#             */
/*   Updated: 2026/07/06 20:36:34 by yohsawa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_benchmark(t_benchmark *flag)
{
	flag->bench = 0;
	flag->simple = 0;
	flag->medium = 0;
	flag->complex = 0;
	flag->adaptive = 0;
	flag->disorder = 1.0;
}

void	init_context(t_context *context, t_stack *a, t_stack *b,
		t_benchmark *flag)
{
	a->data = NULL;
	b->data = NULL;
	context->a = a;
	context->b = b;
	context->flag = flag;
	context->op.pa = 0;
	context->op.pb = 0;
	context->op.sa = 0;
	context->op.sb = 0;
	context->op.ss = 0;
	context->op.ra = 0;
	context->op.rb = 0;
	context->op.rr = 0;
	context->op.rra = 0;
	context->op.rrb = 0;
	context->op.rrr = 0;
	context->count = 0;
}

void	free_stack(t_stack *stack)
{
	if (stack->data)
		free(stack->data);
	stack->data = NULL;
	stack->size = 0;
}
