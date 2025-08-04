/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jemercie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 04:11:26 by jemercie          #+#    #+#             */
/*   Updated: 2022/10/17 22:03:08 by jemercie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static char	*ft_find_little(char *b, char *l, size_t n)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (b[i] && n > 0)
	{
		while (b[i] && (i + j) < n)
		{
			while (l[j] == b[i + j] && (i + j) < n && l[j])
				j++;
			if (l[j] == '\0')
				return (&b[i]);
			i++;
			j = 0;
		}
	}
	return (NULL);
}

char	*ft_strnstr(const char *big, const char *little, size_t n)
{
	char	*b;
	char	*l;
	char	*tmp;

	b = (char *)big;
	l = (char *)little;
	if (n == 0 && (b == NULL || l == NULL))
		return (0);
	if (l[0] == '\0')
		return (b);
	tmp = ft_find_little(b, l, n);
	if (!tmp)
		return (NULL);
	else
		return (tmp);
}
