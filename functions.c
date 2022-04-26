/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataji <ataji@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 13:08:42 by ataji             #+#    #+#             */
/*   Updated: 2022/04/26 04:19:26 by ataji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	my_is_sorted(t_stack *stack)
{
	t_stack	*ptr;
	int		f;

	f = 1;
	ptr = stack;
	while (ptr && ptr->next)
	{
		if (ptr->value > ptr->next->value)
			f = 0;
		ptr = ptr->next;
	}
	return (f);
}

void	ascii_int(t_swap *swap)
{
	swap->count_args = 0;
	while (swap->tab[swap->count_args])
		swap->count_args++;
	swap->k = malloc(sizeof(int) * swap->count_args);
	swap->i = 0;
	swap->j = 0;
	while (swap->i < swap->count_args)
		swap->k[swap->j++] = ft_atoi(swap->tab[swap->i++]);
	check_duplicate(swap->k, swap->count_args);
}

void	malloc_stack(t_stack **stack, int val)
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
			return (malloc_stack(&(current)->next, val));
	}
	(*stack) = (t_stack *)malloc(sizeof(t_stack));
	(*stack)->value = val;
	(*stack)->next = NULL;
}

void	push_k_to_stack(t_stack **stack, t_swap *swap)
{
	int	i;

	swap->tab = ft_split(swap->str, ' ');
	free(swap->str);
	ascii_int(swap);
	if (swap->count_args == 1)
		return ;
	i = 0;
	while (i < swap->count_args)
		malloc_stack(stack, swap->k[i++]);
}

// you must delet it after you finish
void	print_stack(t_stack *stack)
{
	if (stack == NULL)
		printf("Empty stack");
	while (stack != NULL)
	{
		printf("%d ", stack->value);
		stack = stack->next;
	}
	printf("\n");
}

void	minimiz_main(int ac, char **av, t_swap *swap)
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
