/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jemercie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 19:48:25 by jemercie          #+#    #+#             */
/*   Updated: 2022/10/14 19:48:27 by jemercie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static char	**ft_split_fill(char *s1, char **tab, char c)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 0;
	while (s1[i] && s1[i] == c)
		i++;
	while (s1[i])
	{
		k = 0;
		while (s1[i] && s1[i] != c)
		{
			tab[j][k] = s1[i];
			i++;
			k++;
		}
		while (s1[i] && s1[i] == c)
			i++;
		tab[j][k] = '\0';
		j++;
	}
	tab[j] = 0;
	return (tab);
}

static int	ft_count(char *s1, char c)
{
	int	i;
	int	nb_words;

	i = 0;
	nb_words = 0;
	while (s1[i] == c && s1[i])
		i++;
	if (s1[i] == 0)
		return (0);
	while (s1[i])
	{
		if (s1[i] == c)
		{
			while (s1[i] == c)
				i++;
			nb_words++;
		}
		else
			i++;
	}
	if (s1[i - 1] != c)
		nb_words++;
	return (nb_words);
}

static int	nb_letters(int *i, char c, char *s1)
{
	int	j;

	j = 0;
	while (s1[*i] && s1[*i] != c)
	{
		j++;
		*i += 1;
	}
	return (j);
}

static char	**ft_tabtab(char **tab, char c, char *s1)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s1[i] && s1[i] == c)
		i++;
	while (s1[i])
	{
		tab[j] = malloc(sizeof(char) * (nb_letters(&i, c, s1) + 1));
		if (!tab[j])
		{
			while (j != 0)
			{
				j--;
				free(tab[j]);
			}
			return (NULL);
		}
		while (s1[i] && s1[i] == c)
			i++;
		j++;
	}
	return (tab);
}

char	**ft_split(char const *s, char c)
{
	char	*s1;
	char	**tab;

	if (!s)
		return (0);
	s1 = (char *) s;
	tab = malloc(sizeof(char *) * (ft_count(s1, c) + 1));
	if (!tab)
		return (NULL);
	tab = ft_tabtab(tab, c, s1);
	tab = ft_split_fill(s1, tab, c);
	return (tab);
}
