/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohsawa <yohsawa@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/02 15:53:30 by yohsawa           #+#    #+#             */
/*   Updated: 2026/07/10 16:21:56 by yohsawa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	exit_error(t_stack *a, t_stack *b)
{
	free_stack(a);
	free_stack(b);
	ft_printf_err("Error\n");
	return (1);
}

int	strategy_selector(char *c, t_context *context)
{
	if (ft_strncmp(c, "--simple", 9) == 0)
	{
		context->flag->simple = 1;
		return (1);
	}
	if (ft_strncmp(c, "--medium", 9) == 0)
	{
		context->flag->medium = 1;
		return (1);
	}
	if (ft_strncmp(c, "--complex", 10) == 0)
	{
		context->flag->complex = 1;
		return (1);
	}
	if (ft_strncmp(c, "--adaptive", 11) == 0)
	{
		context->flag->adaptive = 1;
		return (1);
	}
	context->flag->adaptive = 1;
	return (0);
}

int	get_bench(int ac, char **av, t_context *context)
{
	int	i;

	i = 1;
	if (ft_strncmp(av[i], "--bench", 8) == 0)
	{
		context->flag->bench = 1;
		i++;
		if (ac <= i)
			return (0);
	}
	if (strategy_selector(av[i], context))
		i++;
	if (ac <= i)
		return (0);
	return (i);
}

int	main(int ac, char **av)
{
	t_stack		a;
	t_stack		b;
	t_context	context;
	int			n;
	t_benchmark	flag;

	if (ac == 1)
		return (0);
	init_benchmark(&flag);
	init_context(&context, &a, &b, &flag);
	n = get_bench(ac, av, &context);
	if (!init_stack_a(&a, ac - n, av + n))
	{
		ft_printf_err("Error\n");
		return (1);
	}
	if (has_duplicate(&a) || !init_stack_b(&b, a.size))
		return (exit_error(&a, &b));
	if (!is_sorted(&a) && !sort_stack(&context))
		return (exit_error(&a, &b));
	if (context.flag->bench)
		print_bench(&context);
	free_stack(&a);
	free_stack(&b);
	return (0);
}
