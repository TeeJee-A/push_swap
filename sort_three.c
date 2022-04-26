/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataji <ataji@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 03:22:25 by ataji             #+#    #+#             */
/*   Updated: 2022/04/25 11:42:35 by ataji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_stack *stack)
{
	t_stack	*ptr;
	int		f;

	f = 1;
	ptr = stack;
	while (ptr && ptr->next)
	{
		if (ptr->value > ptr->next->value)
			f = 0;
		ptr = ptr->next;
	}
	return (f);
}

int	is_rev_sorted(t_stack *stack_b)
{
	t_stack	*ptr;
	int		f;

	f = 1;
	ptr = stack_b;
	while (ptr && ptr->next)
	{
		if (ptr->value < ptr->next->value)
			f = 0;
		ptr = ptr->next;
	}
	return (f);
}

void	sort_three(t_stack **stack, t_oper **oper)
{
	if (!is_sorted(*stack))
	{
		if ((*stack)->value > (*stack)->next->value)
			add_oper(oper, swap_char_a(stack));
	}
	if (!is_sorted(*stack))
	{
		if ((*stack)->next->value > (*stack)->next->next->value)
			add_oper(oper, rev_rotate_char_a(stack));
	}
	if (!is_sorted(*stack))
	{
		if ((*stack)->value > (*stack)->next->value)
			add_oper(oper, swap_char_a(stack));
	}
}

void	sort_rev(t_stack **stack, int len, t_oper **oper)
{
	if (len == 2)
	{
		if ((*stack)->value < (*stack)->next->value)
			add_oper(oper, swap_char_b(stack));
	}
	else if (count_stack(stack) == 3 && len == 3)
	{
		if (!is_rev_sorted(*stack))
		{
			if ((*stack)->value < (*stack)->next->value)
				add_oper(oper, swap_char_b(stack));
		}
		if (!is_rev_sorted(*stack))
		{
			if ((*stack)->next->value < (*stack)->next->next->value)
				add_oper(oper, rev_rotate_char_b(stack));
		}
		if (!is_rev_sorted(*stack))
		{
			if ((*stack)->value < (*stack)->next->value)
				add_oper(oper, swap_char_b(stack));
		}
	}
	else if (len == 3)
		ft_sort_desc(stack, len, oper);
}

void	sort(t_stack **stack, int len, t_oper **oper)
{
	if (len == 2)
	{
		if ((*stack)->value > (*stack)->next->value)
			add_oper(oper, swap_char_a(stack));
	}
	else if (count_stack(stack) == 3 && len == 3)
		sort_three(stack, oper);
	else if (len == 3)
		ft_sort_asc(stack, len, oper);
}
