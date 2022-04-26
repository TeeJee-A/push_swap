/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_a_b_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataji <ataji@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 09:53:55 by ataji             #+#    #+#             */
/*   Updated: 2022/04/26 04:50:34 by ataji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*push_char_a(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*ptr;

	if (count_stack(stack_b) < 1)
		return (NULL);
	ptr = *stack_a;
	*stack_a = *stack_b;
	*stack_b = (*stack_b)->next;
	(*stack_a)->next = ptr;
	ptr = NULL;
	return ("pa");
}

char	*push_char_b(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*ptr;

	if (count_stack(stack_a) < 1)
		return (NULL);
	ptr = *stack_b;
	*stack_b = *stack_a;
	*stack_a = (*stack_a)->next;
	(*stack_b)->next = ptr;
	ptr = NULL;
	return ("pb");
}

char	*push(t_stack **a, t_stack **b, int id)
{
	t_stack	*tmp;

	tmp = *b;
	if (!tmp)
		return ("");
	(*b) = (*b)->next;
	tmp->next = (*a);
	(*a) = tmp;
	if (id == 1)
		return ("pa");
	return ("pb");
}
