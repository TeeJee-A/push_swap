/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_char.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataji <ataji@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 09:45:54 by ataji             #+#    #+#             */
/*   Updated: 2022/04/23 10:41:34 by ataji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*rotate_char_a(t_stack *stack_a)
{
	int	tmp;

	if (count_stack(&stack_a) <= 1)
		return (NULL);
	tmp = stack_a->value;
	while (stack_a->next != NULL)
	{
		stack_a->value = stack_a->next->value;
		stack_a = stack_a->next;
	}
	stack_a->value = tmp;
	return ("ra");
}

char	*rotate_char_b(t_stack *stack_b)
{
	int	tmp;

	if (count_stack(&stack_b) <= 1)
		return (NULL);
	tmp = stack_b->value;
	while (stack_b->next != NULL)
	{
		stack_b->value = stack_b->next->value;
		stack_b = stack_b->next;
	}
	stack_b->value = tmp;
	return ("rb");
}

void	rotate_rotate_char(t_stack *stack_a, t_stack *stack_b)
{
	rotate_char_a(stack_a);
	rotate_char_b(stack_b);
}
