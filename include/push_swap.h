/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msumiji <msumiji@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/02 15:40:02 by yohsawa           #+#    #+#             */
/*   Updated: 2026/07/10 14:22:56 by msumiji          ###   ########.fr       */
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

typedef struct s_benchmark
{
	int		bench;
	int		simple;
	int		medium;
	int		complex;
	int		adaptive;
	double	disorder;
}			t_benchmark;

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

typedef struct s_context
{
	t_stack			*a;
	t_stack			*b;
	t_benchmark		*flag;
	t_operations	op;
	int				count;
}			t_context;

// src/operations/push.c
void		pa(t_context *context);
void		pb(t_context *context);

// src/operations/swap.c
void		sa(t_context *context);
void		sb(t_context *context);
void		ss(t_context *context);

// src/operations/rotate.c
void		ra(t_context *context);
void		rb(t_context *context);
void		rr(t_context *context);

// src/operations/reverse_rotate.c
void		rra(t_context *context);
void		rrb(t_context *context);
void		rrr(t_context *context);

// src/others/utils.c
void		init_benchmark(t_benchmark *flag);
void		init_context(t_context *context, t_stack *a, t_stack *b,
				t_benchmark *flag);
void		free_stack(t_stack *stack);

// src/others/print_bench.c
int			print_bench(t_context *context);

// src/others/compress.c
int			compress_stack(t_stack *a);

// src/libft/ft_split.c
char		**ft_split(char const *s);

// src/libft/ft_strlen.c
int			ft_strlen(const char *s);

// src/libft/ft_strdup.c
char		*ft_strdup(const char *src);

// src/libft/ft_atoi.c
int			ft_atoi(const char *nptr);

// src/libft/ft_strncmp.c
int			ft_strncmp(const char *s1, const char *s2, size_t n);

// src/libft/ft_putnbr.c
void		ft_putnbr(long n);

// src/sort/chunk_sort.c
int			chunk_sort(t_context *context);

// src/sort/sort.c
int			sort_stack(t_context *context);

// src/sort/selection_sort.c
int			selection_sort(t_context *context);
int			find_pos(t_stack *a, int target);

// src/sort/radix_sort.c
int			radix_sort(t_context *context);

// src/stack_utils/stack_init.c
int			init_stack_a(t_stack *a, int ac, char **av);
int			init_stack_b(t_stack *b, int size);

// src/stack_utils/stack_check.c
int			is_sorted(t_stack *stack);
int			has_duplicate(t_stack *stack);

// src/stack_utils/stack_validate.c
int			is_valid_input(int ac, char **av);

// src/main.c
int			get_bench(int ac, char **av, t_context *context);
int			strategy_selector(char *c, t_context *context);

// src/ft_printf_err/ft_printf_err.c
int			ft_printf_err(const char *fmt, ...);

// src/ft_printf_err/ft_printf_err_utils.c
int			ft_putchar_err(char c);
int			ft_putstr_err(char *s);
int			ft_putint_err(int n);
int			ft_putdouble_err(double n);

#endif
