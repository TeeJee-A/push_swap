/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate_char.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataji <ataji@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 09:50:40 by ataji             #+#    #+#             */
/*   Updated: 2022/04/23 10:41:14 by ataji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*rev_rotate_char_a(t_stack **stack_a)
{
	t_stack	*tmp;

	if (count_stack(stack_a) <= 1)
		return (NULL);
	tmp = *stack_a;
	while ((*stack_a)->next->next != NULL)
		*stack_a = (*stack_a)->next;
	(*stack_a)->next->next = tmp;
	tmp = (*stack_a)->next;
	(*stack_a)->next = NULL;
	*stack_a = tmp;
	tmp = NULL;
	return ("rra");
}

char	*rev_rotate_char_b(t_stack **stack_b)
{
	t_stack	*tmp;

	if (count_stack(stack_b) <= 1)
		return (NULL);
	tmp = *stack_b;
	while ((*stack_b)->next->next != NULL)
		*stack_b = (*stack_b)->next;
	(*stack_b)->next->next = tmp;
	tmp = (*stack_b)->next;
	(*stack_b)->next = NULL;
	*stack_b = tmp;
	tmp = NULL;
	return ("rrb");
}

void	rev_rotate_rotate_char(t_stack **stack_a, t_stack **stack_b)
{
	rev_rotate_char_a(stack_a);
	rev_rotate_char_b(stack_b);
}
