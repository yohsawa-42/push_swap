/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_bench.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msumiji <msumiji@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/03 14:29:19 by msumiji           #+#    #+#             */
/*   Updated: 2026/07/04 11:25:58 by msumiji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static char *strategy(t_benchmark *flag)
{
	if (flag->simple)
		return ("Simple");
	else if (flag->medium)
		return ("Medium");
	else if (flag->complex)
		return ("Complex");
	else
		return ("Adaptive");
}

int	print_bench(t_benchmark *flag, t_stack *a, t_stack *b)
{
	int	sum;
	sum = a->pa + b->pb + a->rra + b->rrb + a->rrr + a->ra + b->rb
		 + a->rr + a->sa + b->sb + a->ss;
	ft_printf("[bench] disorder: %f%%\n", 100 * flag->disorder);
	ft_printf("[bench] strategy: %s\n", strategy(flag));
	ft_printf("[bench] total_ops: %d\n", sum);
	ft_printf("[bench] sa: %d sb: %d ss: %d pa: %d pb: %d\n", a->sa, b->sb, a->ss, a->pa, b->pb);
	ft_printf("[bench] ra: %d rb: %d rr: %d rra: %d rrb: %d rrr: %d\n", a->ra, b->rb, a->rr, a->rra, b->rrb, a->rrr);
	return (0);
}
