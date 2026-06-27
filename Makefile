# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yohsawa <yohsawa@student.42tokyo.jp>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/06/02 00:00:00 by yohsawa           #+#    #+#              #
#    Updated: 2026/06/27 18:36:57 by yohsawa          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = cc
CFLAGS = -Wall -Wextra -Werror
INCLUDES = -Iinclude -Ift_printf -I.

FT_PRINTF_DIR = ft_printf
FT_PRINTF = $(FT_PRINTF_DIR)/libftprintf.a

SRCS = \
	src/main.c \
	src/compress.c \
	src/sort/sort.c \
	src/sort/selection_sort.c \
	src/sort/radix_sort.c \
	src/sort/sort_small.c \
	src/utils.c \
	src/operations/push.c \
	src/operations/reverse_rotate.c \
	src/operations/rotate.c \
	src/operations/swap.c \
	src/stack_utils/stack_init.c \
	src/stack_utils/stack_check.c \
	src/stack_utils/stack_validate.c \

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(FT_PRINTF) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(FT_PRINTF) -o $(NAME)

$(FT_PRINTF):
	$(MAKE) -C $(FT_PRINTF_DIR)

%.o: %.c include/push_swap.h ft_printf/ft_printf.h
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	$(MAKE) -C $(FT_PRINTF_DIR) clean
	rm -f $(OBJS)

fclean: clean
	$(MAKE) -C $(FT_PRINTF_DIR) fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
