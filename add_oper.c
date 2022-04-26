/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_oper.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataji <ataji@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 05:43:11 by ataji             #+#    #+#             */
/*   Updated: 2022/04/26 17:08:23 by ataji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	remove_ele(t_oper *oper)
{
	ft_strdel(&oper->data);
	free(oper);
	oper = NULL;
}

void	double_remove(t_oper *second, t_oper *first)
{
	remove_ele(second);
	remove_ele(first);
}

void	remove_oper(t_oper **oper)
{
	if (*oper)
	{
		if ((*oper)->next)
			remove_oper(&(*oper)->next);
		ft_strdel(&(*oper)->data);
		free((*oper)->next);
	}
}

void	add_oper(t_oper **oper, char *data)
{
	t_oper	*current;
	t_oper	*new;

	current = *oper;
	if (!ft_sequ(data, ""))
	{
		if (current)
		{
			if (current->next == NULL)
			{
				new = (t_oper *)malloc(sizeof(t_oper));
				new->data = ft_strdup(data);
				new->next = NULL;
				current->next = new;
				return ;
			}
			else
				return (add_oper(&(current)->next, data));
		}
		(*oper) = (t_oper *)malloc(sizeof(t_oper));
		(*oper)->data = ft_strdup(data);
		(*oper)->next = NULL;
	}
}

void	print_operations(t_oper *oper)
{
	while (oper != NULL)
	{
		ft_putendl(oper->data);
		oper = oper->next;
	}
}
