/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohsawa <yohsawa@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/02 15:40:02 by yohsawa           #+#    #+#             */
/*   Updated: 2026/07/04 17:19:59 by yohsawa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_stack
{
	int		*data;
	int		size;
}			t_stack;

typedef struct s_operations
{
	int		pa;
	int		pb;
	int		sa;
	int		sb;
	int		ss;
	int		ra;
	int		rb;
	int		rr;
	int		rra;
	int		rrb;
	int		rrr;
}			t_operations;

typedef struct s_benchmark
{
	int		bench;
	int		simple;
	int		medium;
	int		complex;
	int		adaptive;
	double	disorder;
}			t_benchmark;

// src/operations/push.c
void		pa(t_stack *a, t_stack *b, t_operations *op);
void		pb(t_stack *a, t_stack *b, t_operations *op);

// src/operations/swap.c
void		sa(t_stack *a, t_operations *op);
void		sb(t_stack *b, t_operations *op);
void		ss(t_stack *a, t_stack *b, t_operations *op);

// src/operations/rotate_and_push.c
void		ra_and_pb(t_stack *a, t_stack *b, int pos, t_operations *op);
void		rb_and_pa(t_stack *a, t_stack *b, int pos, t_operations *op);

// src/operations/rotate.c
void		ra(t_stack *a, t_operations *op);
void		rb(t_stack *b, t_operations *op);
void		rr(t_stack *a, t_stack *b, t_operations *op);

// src/operations/reverse_rotate.c
void		rra(t_stack *a, t_operations *op);
void		rrb(t_stack *b, t_operations *op);
void		rrr(t_stack *a, t_stack *b, t_operations *op);

// libft/ft_atoi.c
int			ft_atoi(const char *nptr);

// libft/ft_strncmp.c
int			ft_strncmp(const char *s1, const char *s2, size_t n);

// libft/ft_putnbr.c
void		ft_putnbr(long n);

// src/utils.c
void		init_benchmark(t_stack *a, t_stack *b, t_benchmark *flag);
void		init_operations(t_operations *op);
void		free_stack(t_stack *stack);
int			count_operations(t_operations *op);

// src/print_bench.c
int			print_bench(t_benchmark *flag, t_operations *op);

// src/compress.c
int			compress_stack(t_stack *a);

// src/sort/chunk_sort.c
int			chunk_sort(t_stack *a, t_stack *b, t_operations *op);

// src/sort/sort.c
int			sort_stack(t_stack *a, t_stack *b, t_benchmark *flag,
				t_operations *op);

// src/sort/selection_sort.c
int			selection_sort(t_stack *a, t_stack *b, t_operations *op);

// src/sort/radix_sort.c
int			radix_sort(t_stack *a, t_stack *b, t_operations *op);

// src/sort/sort_small.c
int			sort_small(t_stack *a, t_stack *b, t_operations *op);

// src/stack/stack_init.c
int			init_stack_a(t_stack *a, int ac, char **av, int n);
int			init_stack_b(t_stack *b, int size);

// src/stack/stack_check.c
int			is_sorted(t_stack *stack);
int			has_duplicate(t_stack *stack);

// src/stack/stack_validate.c
int			is_valid_input(int ac, char **av, int n);

// src/main.c
int			get_bench(int ac, char **av, t_benchmark *flag);
int			strategy_selector(char *c, t_benchmark *flag);

// src/ft_printf_err/ft_printf_err.c
int			ft_printf_err(const char *fmt, ...);

// src/ft_printf_err/ft_printf_err_utils.c
int			ft_putchar_err(char c);
int			ft_putstr_err(char *s);
int			ft_putint_err(int n);
int			ft_putdouble_err(double n);

#endif
