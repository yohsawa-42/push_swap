/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohsawa <yohsawa@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/02 15:40:02 by yohsawa           #+#    #+#             */
/*   Updated: 2026/06/13 17:44:14 by yohsawa          ###   ########.fr       */
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
int		init_stack_a(t_stack *a, int ac, char **av);

// stack_utils/stack_check.c
int		is_sorted(t_stack *stack);
int		is_valid_input(int ac, char **av);
int		has_duplicate(t_stack *stack);

#endif
