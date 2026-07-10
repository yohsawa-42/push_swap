/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohsawa <yohsawa@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/02 15:59:03 by yohsawa           #+#    #+#             */
/*   Updated: 2026/07/10 16:21:44 by yohsawa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push_stack(t_stack *dst, t_stack *src)
{
	int	i;

	if (src->size == 0)
		return ;
	i = dst->size;
	while (i > 0)
	{
		dst->data[i] = dst->data[i - 1];
		i--;
	}
	dst->data[0] = src->data[0];
	dst->size++;
	i = 0;
	while (i < src->size - 1)
	{
		src->data[i] = src->data[i + 1];
		i++;
	}
	src->size--;
}

void	pa(t_context *context)
{
	if (context->b->size == 0)
		return ;
	push_stack(context->a, context->b);
	write(1, "pa\n", 3);
	context->op.pa++;
	context->count++;
}

void	pb(t_context *context)
{
	if (context->a->size == 0)
		return ;
	push_stack(context->b, context->a);
	write(1, "pb\n", 3);
	context->op.pb++;
	context->count++;
}
