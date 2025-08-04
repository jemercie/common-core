/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jemercie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 03:09:18 by jemercie          #+#    #+#             */
/*   Updated: 2022/09/28 03:33:22 by jemercie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	a;
	char	*str;

	a = 0;
	str = (char *) s;
	c %= 256;
	while (a < n)
	{
		if (str[a] == c)
			return (&str[a]);
		a++;
	}
	return (NULL);
}
