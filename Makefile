# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yohsawa <yohsawa@student.42tokyo.jp>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/06/02 00:00:00 by yohsawa           #+#    #+#              #
#    Updated: 2026/07/10 15:50:33 by yohsawa          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = cc
CFLAGS = -Wall -Wextra -Werror
INCLUDES = -Iinclude -I.

SRCS = \
	src/main.c \
	src/sort/sort.c \
	src/sort/selection_sort.c \
	src/sort/radix_sort.c \
	src/sort/chunk_sort.c \
	src/operations/push.c \
	src/operations/rotate_and_push.c \
	src/operations/reverse_rotate.c \
	src/operations/rotate.c \
	src/operations/swap.c \
	src/stack_utils/stack_init.c \
	src/stack_utils/stack_check.c \
	src/stack_utils/stack_validate.c \
	src/ft_printf_err/ft_printf_err.c \
	src/ft_printf_err/ft_printf_err_utils.c \
	src/others/print_bench.c \
	src/others/compress.c \
	src/others/utils.c \
	src/libft/ft_atoi.c \
	src/libft/ft_strdup.c \
	src/libft/ft_split.c \
	src/libft/ft_strlen.c \
	src/libft/ft_strncmp.c \
	src/libft/ft_putnbr.c

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
