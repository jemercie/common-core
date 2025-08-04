/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jemercie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 16:04:55 by jemercie          #+#    #+#             */
/*   Updated: 2022/10/07 15:40:30 by jemercie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static char	*ft_convert(char *str, int i, int j, int n)
{
	char	tmp;

	if (j == 1)
			str[0] = '-';
	while (i >= j)
	{
		tmp = n % 10 + '0';
		n /= 10;
		str[i] = tmp;
		i--;
	}
	return (str);
}

char	*ft_itoa(int n)
{
	int		i;
	int		j;
	char	*str;

	i = ft_intlen(n);
	str = malloc(sizeof(char) * (i + 1));
	if (!str)
		return (NULL);
	str[i] = '\0';
	i--;
	j = 0;
	if (n < 0)
	{
		j = 1;
		if (n == -2147483648)
		{
			str[i] = '8';
			n = -1 * (n / 10);
			i--;
		}
		else
			n = -n;
	}
	str = ft_convert(str, i, j, n);
	return (str);
}
