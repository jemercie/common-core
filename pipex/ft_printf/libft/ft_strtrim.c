/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jemercie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 16:10:29 by jemercie          #+#    #+#             */
/*   Updated: 2022/10/17 21:58:32 by jemercie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static int	ft_strcmpc(char c, char *set2)
{
	int	i;

	i = 0;
	while (set2[i])
	{
		if (set2[i] == c)
			return (1);
		else
			i++;
	}
	return (0);
}

static int	ft_indexstart(char *s2, char *set2)
{
	int	i;
	int	j;

	i = 0;
	while (s2[i])
	{
		j = ft_strcmpc(s2[i], set2);
		if (j != 0)
			i++;
		else
			return (i);
	}
	return (0);
}

static int	ft_indexend(char *s2, char *set2)
{
	int	i;
	int	j;

	i = ft_strlen(s2) - 1;
	while (i >= 0)
	{
		j = ft_strcmpc(s2[i], set2);
		if (j != 0)
			i--;
		else
		{
			if (i > 0)
				i += 1;
			return (i);
		}
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		start;
	int		end;
	char	*str;

	if (!s1 || !set)
		return (0);
	end = ft_indexend((char *) s1, (char *) set);
	start = ft_indexstart((char *) s1, (char *) set);
	str = malloc(sizeof(char) * ((end - start) + 1));
	if (!str)
		return (0);
	i = 0;
	while (start < end)
	{
		str[i] = s1[start];
		i++;
		start++;
	}
	str[i] = '\0';
	return (str);
}
