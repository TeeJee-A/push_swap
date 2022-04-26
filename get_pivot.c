/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_pivot.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataji <ataji@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 02:02:51 by ataji             #+#    #+#             */
/*   Updated: 2022/04/21 02:05:48 by ataji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_pivot(t_stack *stack_a, int len)
{
	int		size;
	int		*x;
	int		i;
	t_stack	*ptr;

	ptr = stack_a;
	size = len;
	i = 0;
	x = (int *)malloc(sizeof(int) * len);
	while (ptr && len--)
	{
		x[i++] = ptr->value;
		ptr = ptr->next;
	}
	i = 0;
	bubble_sort(x, size);
	i = x[size / 2];
	free(x);
	return (i);
}
