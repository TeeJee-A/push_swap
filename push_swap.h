/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataji <ataji@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 00:56:00 by ataji             #+#    #+#             */
/*   Updated: 2022/04/27 02:04:21 by ataji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include "checker_/get_next_line.h"

typedef struct s_stack
{
	int				value;
	struct s_stack	*next;
}t_stack;

typedef struct s_oper
{
	char			*data;
	struct s_oper	*next;
}t_oper;

typedef struct s_swap
{
	int		i;
	int		j;
	int		x;
	int		pivot;
	int		count_args;
	int		*k;
	char	*str;
	char	**tab;
	t_oper	*tmp;
	t_oper	*prev;
	t_oper	*fi;
	t_oper	*se;
}t_swap;

int		ft_strlen(char *str);
int		count_words(char *str, char c);
int		check_space_char(char *str);
int		ft_atoi(char *str);
int		count_stack(t_stack **stack);
int		is_sorted(t_stack *stack);
int		get_index(t_stack *stack, int min);
int		get_min(t_stack *stack);
int		*push_list_to_tab(t_stack *stack, t_swap *swap);
int		push_to_b(t_stack **stack_a, t_stack **stack_b, int len, t_oper **oper);
int		push_to_a(t_stack **stack_a, t_stack **stack_b, int len, t_oper **oper);
int		ft_sort_asc(t_stack **stack_a, int len, t_oper **oper);
int		ft_sort_desc(t_stack **stack_b, int len, t_oper **oper);
int		ft_pivot(t_stack *a, int len);
char	*ft_strdup(char *s1);
char	*ft_strjoin(char *s1, char *s2);
char	**ft_freeing(char **tab);
char	*ft_substr(char *s, int start, int len);
char	**set_words(char *s, char c);
char	**ft_split(char *s, char c);
char	*push_char_a(t_stack **stack_a, t_stack **stack_b);
char	*push_char_b(t_stack **stack_a, t_stack **stack_b);
char	*rev_rotate_char_a(t_stack **stack_a);
char	*rev_rotate_char_b(t_stack **stack_b);
char	*rotate_char_a(t_stack *stack_a);
char	*rotate_char_b(t_stack *stack_b);
char	*swap_char_a(t_stack **stack_a);
char	*swap_char_b(t_stack **stack_b);
void	swap_swap_char(t_stack **stack_a, t_stack **stack_b);
void	rotate_rotate_char(t_stack *stack_a, t_stack *stack_b);
void	rev_rotate_rotate_char(t_stack **stack_a, t_stack **stack_b);
void	write_error(char *str);
void	check_duplicate(int *args, int k);
void	ascii_to_int(t_swap *swap);
void	back_a(t_stack **stack_a, int ra, t_oper **oper);
void	back_b(t_stack **stack_b, int r, t_oper **oper);
void	sorting(t_stack **stack_a, t_stack **stack_b, \
	t_swap *swap, t_oper **oper);
void	push_three_a_b(t_stack **stack_a, t_stack **stack_b, t_oper **oper);
void	push_four_a_b(t_stack **stack_a, t_stack **stack_b, t_oper **oper);
void	sort_two(t_stack **stack, t_oper **oper);
void	sort_three(t_stack **stack, t_oper **oper);
void	sort_four(t_stack **stack_a, t_stack **stack_b, t_oper **oper);
void	sort_five(t_stack **stack_a, t_stack **stack_b, t_oper **oper);
void	sort_rev(t_stack **stack, int len, t_oper **oper);
void	sort(t_stack **stack, int len, t_oper **oper);
void	bubble_sort(int *array, int size);
void	printArray(int *arr, int n);
void	print_stack(t_stack *stack_a);
void	print_operations(t_oper *oper);
void	add_oper(t_oper **oper, char *data);
void	remove_oper(t_oper **oper);
void	double_remove(t_oper *second, t_oper *first);
void	remove_ele(t_oper *oper);
int		ft_sequ(char const *s1, char const *s2);
void	ft_strdel(char **as);
void	ft_putendl(char const *s);
void	ft_putstr(char const *s);
void	ft_putchar(char c);
void	double_remove(t_oper *second, t_oper *first);
void	add_oper(t_oper **head, char *data);
void	print_operations(t_oper *oper);
void	optim_rrarrb(t_oper **oper, int *flag, int *all);
void	optim_sasb(t_oper **oper, int *flag, int *all);
void	optim_rarb(t_oper **oper, int *flag, int *all);
void	optim_rrbrb(t_oper **oper, int *flag, int *all);
void	optim_rrara(t_oper **oper, int *flag, int *all);
void	optim_pbpa(t_oper **oper, int *flag, int *all);
void	optim_sbsb(t_oper **oper, int *flag, int *all);
void	optim_sasa(t_oper **oper, int *flag, int *all);
void	facl2(t_oper *prev, t_oper *tmp);
void	facl1(t_oper *fi, t_oper *se, t_oper *prev, t_oper *tmp);
void	optim_operations(t_oper **oper);
//checker
void	read_commands(t_stack **stack_a, t_stack **stack_b, t_swap *swap);
void	init_commands(char *comm, t_stack **stack_a, \
	t_stack **stack_b, t_swap *swap);
void	break_programm(t_stack **stack_a, t_stack **stack_b, t_swap *swap);
int		ft_strcmp(char *s1, char *s2);
void	clear_memory(t_stack **stack_a, t_stack **stack_b, t_swap *swap);
void	remove_stack(t_stack **head);
void	minimiz_main(int ac, char **av, t_swap *swap);
void	push_k_to_stack(t_stack **stack, t_swap *swap);
void	malloc_stack(t_stack **stack, int val);
void	ascii_int(t_swap *swap);
int		my_is_sorted(t_stack *stack);
char	*push(t_stack **a, t_stack **b, int id);

#endif