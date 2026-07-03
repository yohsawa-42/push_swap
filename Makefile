# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: msumiji <msumiji@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/06/02 00:00:00 by yohsawa           #+#    #+#              #
#    Updated: 2026/07/03 14:46:05 by msumiji          ###   ########.fr        #
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
	src/operations/reverse_rotate.c \
	src/operations/rotate.c \
	src/operations/swap.c \
	src/stack_utils/stack_init.c \
	src/stack_utils/stack_check.c \
	src/stack_utils/stack_validate.c \
	src/printf/ft_printf.c \
	src/printf/print_char.c \
	src/printf/print_int.c \
	src/printf/print_str.c \
	src/printf/print_double.c \
	src/print_bench.c \

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
