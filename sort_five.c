/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataji <ataji@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 08:20:41 by ataji             #+#    #+#             */
/*   Updated: 2022/04/23 10:26:03 by ataji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_three_a_b(t_stack **stack_a, t_stack **stack_b, t_oper **oper)
{
	add_oper(oper, push_char_b(stack_a, stack_b));
	sort_three(stack_a, oper);
	add_oper(oper, push_char_a(stack_a, stack_b));
}

void	sort_four(t_stack **stack_a, t_stack **stack_b, t_oper **oper)
{
	if (get_index(*stack_a, get_min(*stack_a)) == 0)
		push_three_a_b(stack_a, stack_b, oper);
	else if (get_index(*stack_a, get_min(*stack_a)) == 1)
	{
		add_oper(oper, swap_char_a(stack_a));
		push_three_a_b(stack_a, stack_b, oper);
	}
	else if (get_index(*stack_a, get_min(*stack_a)) == 2)
	{
		add_oper(oper, rotate_char_a(*stack_a));
		add_oper(oper, rotate_char_a(*stack_a));
		push_three_a_b(stack_a, stack_b, oper);
	}
	else if (get_index(*stack_a, get_min(*stack_a)) == 3)
	{
		add_oper(oper, rev_rotate_char_a(stack_a));
		push_three_a_b(stack_a, stack_b, oper);
	}
}

void	push_four_a_b(t_stack **stack_a, t_stack **stack_b, t_oper **oper)
{
	add_oper(oper, push_char_b(stack_a, stack_b));
	sort_four(stack_a, stack_b, oper);
	add_oper(oper, push_char_a(stack_a, stack_b));
}

void	sort_five(t_stack **stack_a, t_stack **stack_b, t_oper **oper)
{
	if (get_index(*stack_a, get_min(*stack_a)) == 0)
		push_four_a_b(stack_a, stack_b, oper);
	else if (get_index(*stack_a, get_min(*stack_a)) == 1)
	{
		add_oper(oper, swap_char_a(stack_a));
		push_four_a_b(stack_a, stack_b, oper);
	}
	else if (get_index(*stack_a, get_min(*stack_a)) == 2)
	{
		add_oper(oper, rotate_char_a(*stack_a));
		add_oper(oper, rotate_char_a(*stack_a));
		push_four_a_b(stack_a, stack_b, oper);
	}
	else if (get_index(*stack_a, get_min(*stack_a)) == 3)
	{
		add_oper(oper, rev_rotate_char_a(stack_a));
		add_oper(oper, rev_rotate_char_a(stack_a));
		push_four_a_b(stack_a, stack_b, oper);
	}
	else if (get_index(*stack_a, get_min(*stack_a)) == 4)
	{
		add_oper(oper, rev_rotate_char_a(stack_a));
		push_four_a_b(stack_a, stack_b, oper);
	}
}
