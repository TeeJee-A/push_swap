/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   freeing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataji <ataji@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 03:06:06 by ataji             #+#    #+#             */
/*   Updated: 2022/04/26 05:48:13 by ataji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	remove_stack(t_stack **stack)
{
	if (*stack)
	{
		if ((*stack)->next)
			remove_stack(&(*stack)->next);
		free((*stack)->next);
	}
}

void	clear_memory(t_stack **stack_a, t_stack **stack_b, t_swap *swap)
{
	remove_stack(stack_a);
	remove_stack(stack_b);
	free(swap);
}

