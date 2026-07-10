/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohsawa <yohsawa@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/02 16:15:49 by yohsawa           #+#    #+#             */
/*   Updated: 2026/07/10 15:50:17 by yohsawa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate_stack(t_stack *stack)
{
	int	i;
	int	temp;

	if (stack->size < 2)
		return ;
	i = 0;
	temp = stack->data[i];
	while (i < stack->size - 1)
	{
		stack->data[i] = stack->data[i + 1];
		i++;
	}
	stack->data[i] = temp;
}

void	ra(t_context *context)
{
	if (context->a->size < 2)
		return ;
	rotate_stack(context->a);
	write(1, "ra\n", 3);
	context->op.ra++;
	context->count++;
}

void	rb(t_context *context)
{
	if (context->b->size < 2)
		return ;
	rotate_stack(context->b);
	write(1, "rb\n", 3);
	context->op.rb++;
	context->count++;
}

void	rr(t_context *context)
{
	if (context->a->size < 2 && context->b->size < 2)
		return ;
	rotate_stack(context->a);
	rotate_stack(context->b);
	write(1, "rr\n", 3);
	context->op.rr++;
	context->count++;
}
