/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_bench.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msumiji <msumiji@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/03 14:29:19 by msumiji           #+#    #+#             */
/*   Updated: 2026/07/05 14:40:22 by msumiji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static char	*strategy(t_benchmark *flag)
{
	if (!flag->adaptive && flag->simple)
		return ("Simple");
	else if (!flag->adaptive && flag->medium)
		return ("Medium");
	else if (!flag->adaptive && flag->complex)
		return ("Complex");
	else if (flag->simple)
		return ("Adaptive / O(n2)");
	else if (flag->medium)
		return ("Adaptive / O(n√n)");
	else
		return ("Adaptive / O(nlogn)");
}

int	print_bench(t_stack *a, t_stack *b, t_benchmark *flag)
{
	int	sum;

	sum = a->pa + b->pb + a->sa + b->sb + a->ss + a->ra + b->rb + a->rr
		+ a->rra + b->rrb + a->rrr;
	ft_printf_err("[bench] disorder: %f%%\n", 100 * flag->disorder);
	ft_printf_err("[bench] strategy: %s\n", strategy(flag));
	ft_printf_err("[bench] total_ops: %d\n", sum);
	ft_printf_err("[bench] sa: %d sb: %d ss: %d pa: %d pb: %d\n", a->sa,
		b->sb, a->ss, a->pa, b->pb);
	ft_printf_err("[bench] ra: %d rb: %d rr: %d rra: %d rrb: %d rrr: %d\n",
		a->ra, b->rb, a->rr, a->rra, b->rrb, a->rrr);
	return (0);
}
