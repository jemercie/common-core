/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jemercie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 10:23:09 by jemercie          #+#    #+#             */
/*   Updated: 2022/10/17 22:01:57 by jemercie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t			a;
	unsigned char	*d;
	unsigned char	*s;

	if (!dest && !src)
		return (0);
	a = -1;
	d = (unsigned char *)dest;
	s = (unsigned char *)src;
	while (++a < n)
		d[a] = s[a];
	return (dest);
}
