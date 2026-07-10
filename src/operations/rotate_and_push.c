/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_and_push.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohsawa <yohsawa@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/04 14:45:00 by yohsawa           #+#    #+#             */
/*   Updated: 2026/07/10 15:50:16 by yohsawa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rb_and_pa(t_context *context, int pos)
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
