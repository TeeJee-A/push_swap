/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataji <ataji@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 11:46:48 by ataji             #+#    #+#             */
/*   Updated: 2022/04/27 01:33:53 by ataji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	if (!s2)
		return (1);
	while (s1[i] != '\0' || s2[i] != '\0')
	{
		if (s1[i] != s2[i])
		{
			return (s1[i] - s2[i]);
		}
		i++;
	}
	return (0);
}

void	break_programm(t_stack **stack_a, t_stack **stack_b, t_swap *swap)
{
	clear_memory(stack_a, stack_b, swap);
	write(2, "Error\n", 6);
	exit(0);
}

void	init_commands(char *comm, t_stack **stack_a, \
	t_stack **stack_b, t_swap *swap)
{
	if (!ft_strcmp(comm, "sa\n"))
		swap_char_a(stack_a);
	else if (!ft_strcmp(comm, "sb\n"))
		swap_char_b(stack_b);
	else if (!ft_strcmp(comm, "ss\n"))
		swap_swap_char(stack_a, stack_b);
	else if (!ft_strcmp(comm, "pa\n"))
		push(stack_a, stack_b, 1);
	else if (!ft_strcmp(comm, "pb\n"))
		push(stack_b, stack_a, 2);
	else if (!ft_strcmp(comm, "ra\n"))
		rotate_char_a(*stack_a);
	else if (!ft_strcmp(comm, "rb\n"))
		rotate_char_b(*stack_b);
	else if (!ft_strcmp(comm, "rr\n"))
		rotate_rotate_char(*stack_a, *stack_b);
	else if (!ft_strcmp(comm, "rra\n"))
		rev_rotate_char_a(stack_a);
	else if (!ft_strcmp(comm, "rrb\n"))
		rev_rotate_char_b(stack_b);
	else if (!ft_strcmp(comm, "rrr\n"))
		rev_rotate_rotate_char(stack_a, stack_b);
	else
		break_programm(stack_a, stack_b, swap);
}

void	read_commands(t_stack **stack_a, t_stack **stack_b, t_swap *swap)
{
	char	*line;

	line = get_next_line(0);
	while (line != NULL)
	{
		init_commands(line, stack_a, stack_b, swap);
		line = get_next_line(0);
	}
}

int	main(int ac, char **av)
{
	t_swap	*swap;
	t_stack	*stack_a;
	t_stack	*stack_b;

	swap = malloc(sizeof(t_swap));
	swap->i = 1;
	swap->j = 0;
	minimiz_main(ac, av, swap);
	push_k_to_stack(&stack_a, swap);
	read_commands(&stack_a, &stack_b, swap);
	if (my_is_sorted(stack_a) && !stack_b)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	return (0);
}
