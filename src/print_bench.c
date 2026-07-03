/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_bench.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msumiji <msumiji@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/03 14:29:19 by msumiji           #+#    #+#             */
/*   Updated: 2026/07/03 16:28:24 by msumiji          ###   ########.fr       */
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
	else if (flag->small)
		return("Small");
	else
		return ("Adaptive");
}

int	print_bench(t_benchmark *flag)
{
	ft_printf("[bench] disorder: %f%%\n", 100 * flag->disorder);
	ft_printf("[bench] strategy: %s\n", strategy(flag));
	return (0);
}
