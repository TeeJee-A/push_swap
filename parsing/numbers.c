/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   numbers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataji <ataji@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 16:02:33 by ataji             #+#    #+#             */
/*   Updated: 2022/04/20 00:57:47 by ataji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_atoi(char *str)
{
	int				i;
	long int		n;
	int				signe;

	i = 0;
	n = 0;
	signe = 1;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '+')
		i++;
	else if (str[i] == '-')
	{
		signe *= -1;
		i++;
	}
	if (str[i] == '\0')
		write_error("Error\n");
	while (str[i] >= '0' && str[i] <= '9')
		n = (n * 10) + (str[i++] - '0');
	if ((str[i] < '0' || str[i] > '9') && str[i] != '\0')
		write_error("Error\n");
	if (n * signe < -2147483648 || n * signe > 2147483647)
		write_error("Error\n");
	return (n * signe);
}

void	check_duplicate(int *args, int k)
{
	int	i;
	int	j;

	i = 0;
	while (i < k)
	{
		j = i + 1;
		while (j < k)
		{
			if (args[i] == args[j])
				write_error("Error\n");
			j++;
		}
		i++;
	}
}

int	check_space_char(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] != ' ')
			return (1);
		i++;
	}
	return (0);
}
