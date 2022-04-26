/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataji <ataji@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 15:56:33 by ataji             #+#    #+#             */
/*   Updated: 2022/04/26 18:00:54 by ataji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ascii_to_int(t_swap *swap)
{
	swap->count_args = 0;
	while (swap->tab[swap->count_args])
		swap->count_args++;
	swap->k = malloc(sizeof(int) * swap->count_args);
	swap->i = 0;
	swap->j = 0;
	while (swap->i < swap->count_args)
		swap->k[swap->j++] = ft_atoi(swap->tab[swap->i++]);
	ft_freeing(swap->tab);
	check_duplicate(swap->k, swap->count_args);
}

void	malloc_stack_a(t_stack **stack, int val)
{
	t_stack	*current;
	t_stack	*new;

	current = *stack;
	if (current)
	{
		if (current->next == NULL)
		{
			new = malloc(sizeof(t_stack));
			new->value = val;
			new->next = NULL;
			current->next = new;
			return ;
		}
		else
			return (malloc_stack_a(&(current)->next, val));
	}
	(*stack) = (t_stack *)malloc(sizeof(t_stack));
	(*stack)->value = val;
	(*stack)->next = NULL;
}

void	push_k_to_stack_a(t_stack **stack, t_swap *swap)
{
	int	i;

	swap->tab = ft_split(swap->str, ' ');
	free(swap->str);
	ascii_to_int(swap);
	if (swap->count_args == 1)
		return ;
	i = 0;
	while (i < swap->count_args)
		malloc_stack_a(stack, swap->k[i++]);
}

// you must delet it after you finish
// void	print_stack(t_stack *stack)
// {
// 	if (stack == NULL)
// 		printf("Empty stack");
// 	while (stack != NULL)
// 	{
// 		printf("%d ", stack->value);
// 		stack = stack->next;
// 	}
// 	printf("\n");
// }

void	mini_main(int ac, char **av, t_swap *swap)
{
	if (ac == 1)
		return ;
	while (++swap->j < ac)
		if (av[1][swap->j] == '\0' && (!check_space_char(av[swap->j])))
			write_error("Error\n");
	if (!check_space_char(av[1]))
		write_error("Error\n");
	swap->str = ft_strdup("");
	while (swap->i < ac)
	{
		swap->str = ft_strjoin(swap->str, av[swap->i++]);
		swap->str = ft_strjoin(swap->str, " ");
	}
}

// delete AR in makefile
int	main(int ac, char **av)
{
	t_swap	*swap;
	t_oper	*oper;
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (ac == 1 || ac == 2)
		return (0);
	swap = malloc(sizeof(t_swap));
	stack_a = malloc(sizeof(t_stack));
	stack_b = malloc(sizeof(t_stack));
	oper = malloc(sizeof(t_oper));
	stack_a = NULL;
	stack_b = NULL;
	oper = NULL;
	swap->i = 1;
	swap->j = 0;
	mini_main(ac, av, swap);
	push_k_to_stack_a(&stack_a, swap);
	free(swap->k);
	sorting(&stack_a, &stack_b, swap, &oper);
	optim_operations(&oper);
	print_operations(oper);
	remove_oper(&oper);
	clear_memory(&stack_a, &stack_b, swap);
}
