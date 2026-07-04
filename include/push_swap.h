/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msumiji <msumiji@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/02 15:40:02 by yohsawa           #+#    #+#             */
/*   Updated: 2026/07/04 11:21:57 by msumiji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

typedef struct s_stack
{
	int	*data;
	int	size;
	int	sa;
	int	sb;
	int	ss;
	int	pa;
	int	pb;
	int	ra;
	int	rb;
	int	rr;
	int	rra;
	int	rrb;
	int	rrr;
}		t_stack;

typedef struct s_benchmark
{
	int	bench;
	int	simple;
	int	medium;
	int	complex;
	int	adaptive;
	double	disorder;
}		t_benchmark;

// src/operations/swap.c
void	sa(t_stack *a);
void	sb(t_stack *b);
void	ss(t_stack *a, t_stack *b);

// src/operations/push.c
void	pa(t_stack *a, t_stack *b);
void	pb(t_stack *a, t_stack *b);
void	ra_and_pb(t_stack *a, t_stack *b, int i);
void	rb_and_pa(t_stack *a, t_stack *b, int i);

// src/operations/rotate.c
void	ra(t_stack *a);
void	rb(t_stack *b);
void	rr(t_stack *a, t_stack *b);

// src/operations/reverse_rotate.c
void	rra(t_stack *a);
void	rrb(t_stack *b);
void	rrr(t_stack *a, t_stack *b);

// src/utils.c
int		ft_atoi(const char *nptr);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	print_error(void);
void	free_stack(t_stack *stack);
int		print_bench(t_benchmark *flag, t_stack *a, t_stack *b);

// src/compress.c
int		compress_stack(t_stack *a);
void	sort_array(int *arr, int size);

// src/chunk_sort.c
int		chunk_sort(t_stack *a, t_stack *b);

// src/sort/sort.c
int		sort_stack(t_stack *a, t_stack *b, t_benchmark *flag);

// src/sort/selection_sort.c
int		selection_sort(t_stack *a, t_stack *b);

// src/sort/radix_sort.c
int		radix_sort(t_stack *a, t_stack *b);

// src/sort/sort_small.c
int		sort_small(t_stack *a, t_stack *b);

// src/stack_utils/stack_init.c
int		init_stack_a(t_stack *a, int ac, char **av, int n);
int		init_stack_b(t_stack *b, int size);

// src/stack_utils/stack_check.c
int		is_sorted(t_stack *stack);
int		has_duplicate(t_stack *stack);

// src/stack_utils/stack_validate.c
int		is_valid_input(int ac, char **av, int n);

// src/main.c
int		get_bench(int ac, char **av, t_benchmark *flag);
int		strategy_selector(char *c, t_benchmark *flag);

// src/printf
int		ft_printf(const char *fmt, ...);
int		print_char(int n);
int		print_int(int n);
int		print_str(char *s);
int		print_double(double n);

// src/print_bench
int		print_bench(t_benchmark *flag, t_stack *a, t_stack *b);

#endif
