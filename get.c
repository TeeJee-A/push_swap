/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataji <ataji@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 01:54:12 by ataji             #+#    #+#             */
/*   Updated: 2022/04/25 12:03:09 by ataji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sorting(t_stack **stack_a, t_stack **stack_b, \
	t_swap *swap, t_oper **oper)
{
	if (!is_sorted(*stack_a))
	{
		if (count_stack(stack_a) == 2)
			sort_two(stack_a, oper);
		if (count_stack(stack_a) == 3)
			sort_three(stack_a, oper);
		if (count_stack(stack_a) == 4)
			sort_four(stack_a, stack_b, oper);
		if (count_stack(stack_a) == 5)
			sort_five(stack_a, stack_b, oper);
		if (count_stack(stack_a) > 5)
			push_to_b(stack_a, stack_b, swap->count_args, oper);
	}
	else
		return ;
}

int	get_index(t_stack *stack, int min)
{
	t_stack	*ptr;
	int		i;

	ptr = stack;
	i = -1;
	while (ptr != NULL)
	{
		if (ptr->value == min)
			return (++i);
		i++;
		ptr = ptr->next;
	}
	return (i);
}

int	get_min(t_stack *stack)
{
	t_stack	*ptr;
	int		min;

	ptr = stack->next;
	min = stack->value;
	while (ptr != NULL)
	{
		if (ptr->value < min)
			min = ptr->value;
		ptr = ptr->next;
	}
	return (min);
}
