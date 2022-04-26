/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_char.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataji <ataji@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 09:41:27 by ataji             #+#    #+#             */
/*   Updated: 2022/04/23 10:41:55 by ataji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*swap_char_a(t_stack **stack_a)
{
	int	tab;

	if (count_stack(stack_a) <= 1)
		return (NULL);
	tab = (*stack_a)->value;
	(*stack_a)->value = (*stack_a)->next->value;
	(*stack_a)->next->value = tab;
	return ("sa");
}

char	*swap_char_b(t_stack **stack_b)
{
	int	tab;

	if (count_stack(stack_b) <= 1)
		return (NULL);
	tab = (*stack_b)->value;
	(*stack_b)->value = (*stack_b)->next->value;
	(*stack_b)->next->value = tab;
	return ("sb");
}

void	swap_swap_char(t_stack **stack_a, t_stack **stack_b)
{
	swap_char_a(stack_a);
	swap_char_b(stack_b);
}
