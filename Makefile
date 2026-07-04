# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yohsawa <yohsawa@student.42tokyo.jp>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/06/02 00:00:00 by yohsawa           #+#    #+#              #
#    Updated: 2026/07/04 15:18:58 by yohsawa          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = cc
CFLAGS = -Wall -Wextra -Werror
INCLUDES = -Iinclude -I.

SRCS = \
	src/main.c \
	src/compress.c \
	src/sort/sort.c \
	src/sort/selection_sort.c \
	src/sort/radix_sort.c \
	src/sort/sort_small.c \
	src/sort/chunk_sort.c \
	src/utils.c \
	src/operations/push.c \
	src/operations/rotate_and_push.c \
	src/operations/reverse_rotate.c \
	src/operations/rotate.c \
	src/operations/swap.c \
	src/stack/stack_init.c \
	src/stack/stack_check.c \
	src/stack/stack_validate.c \
	src/ft_printf_err/ft_printf_err.c \
	src/ft_printf_err/ft_printf_err_utils.c \
	src/print_bench.c \
	libft/ft_atoi.c \
	libft/ft_strncmp.c \

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.c include/push_swap.h
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
