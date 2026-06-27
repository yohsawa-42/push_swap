/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msumiji <msumiji@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/02 15:40:02 by yohsawa           #+#    #+#             */
/*   Updated: 2026/06/27 10:44:01 by msumiji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../ft_printf/ft_printf.h"
# include <stdlib.h>
# include <unistd.h>

typedef struct s_stack
{
	int	*data;
	int	size;
}		t_stack;

typedef struct s_benchmark
{
	int	bench;
	int	simple;
	int	medium;
	int	complex;
	int	adaptive;
}		t_benchmark;

// src/operations/swap.c
void	sa(t_stack *a);
void	sb(t_stack *b);
void	ss(t_stack *a, t_stack *b);

// src/operations/push.c
void	pa(t_stack *a, t_stack *b);
void	pb(t_stack *a, t_stack *b);

// src/operations/rotate.c
void	ra(t_stack *a);
void	rb(t_stack *b);
void	rr(t_stack *a, t_stack *b);

// src/operations/reverce_rotate.c
void	rra(t_stack *a);
void	rrb(t_stack *b);
void	rrr(t_stack *a, t_stack *b);

// src/utils.h
int		ft_atoi(const char *nptr);
void	print_error(void);
void	free_stack(t_stack *stack);

// src/sort.c
int		sort_stack(t_stack *a, t_stack *b);
int		compress_stack(t_stack *a);
void	sort_small(t_stack *a, t_stack *b);

// stack_utils/stack_init.c
int		init_stack_a(t_stack *a, int ac, char **av, int n);
int		init_stack_b(t_stack *b, int size);

// stack_utils/stack_check.c
int		is_sorted(t_stack *stack);
int		is_valid_input(int ac, char **av, int n);
int		has_duplicate(t_stack *stack);
int		get_bench(int ac, char **av, t_benchmark *flag);
int		strategy_selector(char *c, t_benchmark *flag);

int	ft_strncmp(const char *s1, const char *s2, size_t n);

#endif
