/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jemercie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 00:14:18 by jemercie          #+#    #+#             */
/*   Updated: 2022/10/17 21:57:50 by jemercie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	int		j;
	char	*str;

	c %= 256;
	str = (char *)s;
	i = 0;
	j = ft_strlen(str);
	while (i <= j)
	{
		if (str[i] == c)
			return (&str[i]);
		i++;
	}
	return (0);
}
