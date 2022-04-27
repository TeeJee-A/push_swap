/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   freeing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataji <ataji@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 03:06:06 by ataji             #+#    #+#             */
/*   Updated: 2022/04/26 21:58:18 by ataji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	remove_stack(t_stack **stack)
{
	t_stack	*curr;
	t_stack	*aux;

	curr = *stack;
	while (curr != NULL)
	{		
		aux = curr;
		curr = curr->next;
		free(aux);
	}
	*stack = NULL;
}

void	clear_memory(t_stack **stack_a, t_stack **stack_b, t_swap *swap)
{
	remove_stack(stack_a);
	remove_stack(stack_b);
	free(swap);
}
