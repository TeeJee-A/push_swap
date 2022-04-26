/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_asc_desc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataji <ataji@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 23:10:14 by ataji             #+#    #+#             */
/*   Updated: 2022/04/23 10:17:35 by ataji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_sort_asc(t_stack **stack_a, int len, t_oper **oper)
{
	while (len-- > 1)
	{
		if ((*stack_a)->value > (*stack_a)->next->value)
		{
			add_oper(oper, swap_char_a(stack_a));
			add_oper(oper, rotate_char_a(*stack_a));
		}
		else
			add_oper(oper, rotate_char_a(*stack_a));
	}
	while (++len < 3)
		add_oper(oper, rev_rotate_char_a(stack_a));
	if ((*stack_a)->value > (*stack_a)->next->value)
		add_oper(oper, swap_char_a(stack_a));
	return (0);
}

int	ft_sort_desc(t_stack **stack_b, int len, t_oper **oper)
{
	while (len-- > 1)
	{
		if ((*stack_b)->value < (*stack_b)->next->value)
		{
			add_oper(oper, swap_char_b(stack_b));
			add_oper(oper, rotate_char_b(*stack_b));
		}
		else
			add_oper(oper, rotate_char_b(*stack_b));
	}
	while (++len < 3)
	{
		add_oper(oper, rev_rotate_char_b(stack_b));
		if ((*stack_b)->value < (*stack_b)->value)
			add_oper(oper, swap_char_b(stack_b));
	}
	if ((*stack_b)->value < (*stack_b)->next->value)
		add_oper(oper, swap_char_b(stack_b));
	return (0);
}
