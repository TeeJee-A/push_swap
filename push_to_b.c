/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_to_b.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataji <ataji@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 06:57:54 by ataji             #+#    #+#             */
/*   Updated: 2022/04/26 02:13:17 by ataji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	back_a(t_stack **stack_a, int ra, t_oper **oper)
{
	if (ra > count_stack(stack_a) / 2)
		while (count_stack(stack_a) - ra++ > 0)
			add_oper(oper, rotate_char_a(*stack_a));
	else
		while (ra--)
			add_oper(oper, rev_rotate_char_a(stack_a));
}

void	back_b(t_stack **stack_b, int r, t_oper **oper)
{
	if (r > count_stack(stack_b) / 2)
		while (count_stack(stack_b) - r++ > 0)
			add_oper(oper, rotate_char_b(*stack_b));
	else
		while (r--)
			add_oper(oper, rev_rotate_char_b(stack_b));
}

int	push_to_b(t_stack **stack_a, t_stack **stack_b, int len, t_oper **oper)
{
	int	pb;
	int	ra;
	int	x;
	int	pivot;

	x = -1;
	if (len <= 3)
		return (sort(stack_a, len, oper), 0);
	pb = 0;
	ra = 0;
	pivot = ft_pivot(*stack_a, len);
	while (++x < len)
	{
		if ((*stack_a)->value >= pivot && ++ra)
			add_oper(oper, rotate_char_a(*stack_a));
		else if ((*stack_a)->value < pivot && ++pb)
			add_oper(oper, push_char_b(stack_a, stack_b));
	}
	back_a(stack_a, ra, oper);
	push_to_b(stack_a, stack_b, len - pb, oper);
	push_to_a(stack_a, stack_b, pb, oper);
	while (pb--)
		add_oper(oper, push_char_a(stack_a, stack_b));
	return (0);
}

int	push_to_a(t_stack **stack_a, t_stack **stack_b, int len, t_oper **oper)
{
	int	pa;
	int	rb;
	int	x;
	int	pivot;

	x = -1;
	if (len <= 3)
		return (sort_rev(stack_b, len, oper), 0);
	pa = 0;
	rb = 0;
	pivot = ft_pivot(*stack_b, len);
	while (++x < len)
	{
		if ((*stack_b)->value <= pivot && ++rb)
			add_oper(oper, rotate_char_b(*stack_b));
		else if ((*stack_b)->value > pivot && ++pa)
			add_oper(oper, push_char_a(stack_a, stack_b));
	}
	push_to_b(stack_a, stack_b, pa, oper);
	back_b(stack_b, rb, oper);
	push_to_a(stack_a, stack_b, len - pa, oper);
	while (pa--)
		add_oper(oper, push_char_b(stack_a, stack_b));
	return (0);
}
