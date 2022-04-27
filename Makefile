# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ataji <ataji@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/06 23:28:50 by ataji             #+#    #+#              #
#    Updated: 2022/04/27 02:04:21 by ataji            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
NAME_B = checker
INC = push_swap.h
SRC = push_swap.c \
	sort_two.c \
	sort_three.c \
	sort_five.c \
	get.c \
	ft_strdup.c \
	parsing/numbers.c \
	parsing/split.c \
	parsing/strjoin.c \
	parsing/write_error.c \
	sort_without_instraction.c \
	push_to_b.c \
	get_pivot.c \
	sort_asc_desc.c \
	add_oper.c \
	list_function.c \
	push_a_b_char.c \
	rev_rotate_char.c \
	rotate_char.c \
	swap_char.c \
	optim_one.c \
	optim_two.c \
	optim_operation.c \
	count_stack.c \
	freeing.c
SRC_B = checker_/checker.c \
	checker_/get_next_line.c \
	checker_/get_next_line_utils.c \
	freeing.c \
	push_a_b_char.c \
	rev_rotate_char.c \
	rotate_char.c \
	swap_char.c \
	functions.c \
	count_stack.c \
 	parsing/write_error.c \
	parsing/numbers.c \
	parsing/strjoin.c \
	parsing/split.c \
	ft_strdup.c

OBJ = $(SRC:%.c=%.o)
OBJ_B = $(SRC_B:%.c=%.o)
CFLAGS = -Werror -Wextra -Wall
CC = cc

all: $(NAME) $(NAME_B)

$(NAME):$(OBJ) $(OBJ_B) $(INC)
	@$(CC) $(CFLAGS) $(SRC) -o $(NAME)
	@$(CC) $(CFLAGS) $(SRC_B) -o $(NAME_B)
	@echo "done"

%.o: %.c $(INC)
	@$(CC) $(CFLAGS) -c $< -o $@

clean :
	@$(RM) $(OBJ) $(OBJ_B)

fclean:clean
	@$(RM) $(NAME) $(NAME_B)

re: fclean all