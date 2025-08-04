/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jemercie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 15:01:22 by jemercie          #+#    #+#             */
/*   Updated: 2022/09/30 18:38:51 by jemercie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	char	*p;

	if (size == 0 || nmemb == 0)
	{
		p = malloc(0);
		if (!p)
			return (NULL);
		return (p);
	}
	if (((nmemb * size) / size != nmemb))
		return (NULL);
	p = malloc(size * nmemb);
	if (!p)
		return (0);
	ft_bzero(p, (size * nmemb));
	return ((void *)p);
}
