/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataji <ataji@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 16:07:08 by ataji             #+#    #+#             */
/*   Updated: 2022/04/26 21:44:40 by ataji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	count_words(char *str, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (*str)
	{
		if (*str != c && count == 0)
		{
			count = 1;
			i++;
		}
		else if (*str == c)
			count = 0;
		str++;
	}
	return (i);
}

char	**ft_freeing(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
		free(tab[i++]);
	free(tab);
	return (NULL);
}

char	*ft_substr(char *s, int start, int len)
{
	int		i;
	char	*str;

	i = 0;
	if (!s)
		return (NULL);
	if (start < ft_strlen(s))
	{
		if (ft_strlen(s) < len)
			len = ft_strlen(s);
		str = (char *)malloc((len + 1) * sizeof(char));
		if (!str)
			return (NULL);
		while (i < len)
			str[i++] = s[start++];
	}
	else
		str = malloc(1);
	str[i] = '\0';
	return (str);
}

char	**set_words(char *s, char c)
{
	int		i;
	int		j;
	int		k;
	char	**tab;

	tab = (char **)malloc((count_words(s, c) + 1) * sizeof(char *));
	if (!tab)
		return (NULL);
	i = 0;
	k = 0;
	while (s[i])
	{
		while (s[i] == c && s[i])
			i++;
		j = 0;
		while (s[i + j] != c && s[i + j])
			j++;
		if (j != 0)
			tab[k++] = ft_substr(s, i, j);
		if (j != 0 && !tab[k - 1])
			return (ft_freeing(tab));
		i = i + j;
	}
	tab[k] = NULL;
	return (tab);
}

char	**ft_split(char *s, char c)
{
	char	**tab;

	if (!s)
		return (NULL);
	tab = set_words((char *)s, c);
	return (tab);
}
