/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jemercie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 00:54:59 by jemercie          #+#    #+#             */
/*   Updated: 2022/10/17 22:04:00 by jemercie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		j;
	char	*k;
	char	*str;

	c %= 256;
	str = (char *)s;
	j = ft_strlen(str);
	while (j >= 0)
	{
		if (str[j] == c)
		{
			k = &str[j];
			return (k);
		}
		if (str[j] != c)
		j--;
	}
	return (0);
}
