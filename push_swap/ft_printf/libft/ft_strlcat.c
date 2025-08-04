/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jemercie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 23:44:12 by jemercie          #+#    #+#             */
/*   Updated: 2022/09/28 00:08:15 by jemercie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t n)
{
	size_t	i;
	size_t	j;
	char	*str;

	if (n == 0 && (dest == NULL || src == NULL))
		return (0);
	str = (char *) src;
	i = ft_strlen(dest);
	j = 0;
	if (n == 0 || n < i)
		return (ft_strlen(str) + n);
	while (src[j] && ((i + j) < n - 1))
	{
		dest[i + j] = src[j];
		j++;
	}
	dest[i + j] = '\0';
	return (i + ft_strlen(str));
}
